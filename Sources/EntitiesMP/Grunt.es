343
%{
#include "StdH.h"
#include "ModelsMP/Enemies/Grunt/elite_merc/merc_elite.h"
#include "ModelsMP/Enemies/Grunt/merc/merc_idle.h"
%}

uses "EntitiesMP/EnemyBase";
uses "EntitiesMP/BasicEffects";
uses "EntitiesMP/Bullet";  // Add this for bullet attacks

enum GruntWeaponType {
  0 GWT_AUTO_RIFLE   "Auto Rifle",
  1 GWT_SHOTGUN      "Shotgun",
};

enum GruntType {
  0 GT_SOLDIER    "Grunt soldier",
  1 GT_COMMANDER  "Grunt commander",
};

%{
#define STRETCH_SOLDIER   1.2f
#define STRETCH_COMMANDER 1.4f
#define FIREPOS_SOLDIER      FLOAT3D(0.07f, 1.36f, -0.78f)*STRETCH_SOLDIER
#define FIREPOS_COMMANDER    FLOAT3D(0.10f, 1.30f, -0.60f)*STRETCH_COMMANDER
#define SHOTGUN_SPREAD_ANGLE 5.0f // angle for shotgun
#define BULLET_DAMAGE 4.0f  // Damage per bullet

// info structure
static EntityInfo eiGruntSoldier = {
  EIBT_FLESH, 200.0f,
  0.0f, 1.9f*STRETCH_SOLDIER, 0.0f,     // source (eyes)
  0.0f, 1.3f*STRETCH_SOLDIER, 0.0f,     // target (body)
};

static EntityInfo eiGruntCommander = {
  EIBT_FLESH, 250.0f,
  0.0f, 1.9f*STRETCH_COMMANDER, 0.0f,     // source (eyes)
  0.0f, 1.3f*STRETCH_COMMANDER, 0.0f,     // target (body)
};

#define FIREPOS_SOLDIER      FLOAT3D(0.07f, 1.36f, -0.78f)*STRETCH_SOLDIER
#define FIREPOS_COMMANDER_UP  FLOAT3D(0.09f, 1.45f, -0.62f)*STRETCH_COMMANDER
#define FIREPOS_COMMANDER_DN  FLOAT3D(0.10f, 1.30f, -0.60f)*STRETCH_COMMANDER
%}


class CGrunt: CEnemyBase {
name      "Grunt";
thumbnail "Thumbnails\\Grunt.tbn";

properties:
  1 enum GruntType m_gtType "Type" 'Y' = GT_SOLDIER,
  2 enum GruntWeaponType m_gwtWeapon "Weapon Type" = GWT_AUTO_RIFLE,
  3 INDEX m_bFireBulletCount = 0,       // fire bullet binary divider
  4 FLOAT m_fFireTime = 0.0f,           // time to fire bullets

  10 CSoundObject m_soFire1,
  11 CSoundObject m_soFire2,

// class internal
    
components:
  1 class   CLASS_BASE            "Classes\\EnemyBase.ecl",
  3 class   CLASS_PROJECTILE      "Classes\\Projectile.ecl",
  4 class   CLASS_BULLET          "Classes\\Bullet.ecl",  // Add this for bullet attacks

 10 model   MODEL_GRUNT           "ModelsMP\\Enemies\\Grunt\\elite_merc\\merc_elite.mdl",
 11 model   MODEL_GUN_COMMANDER   "ModelsMP\\Enemies\\Grunt\\merc\\ag36_merc.mdl",
 12 model   MODEL_GUN_SOLDIER     "ModelsMP\\Enemies\\Grunt\\elite_merc\\p90_merc.mdl",
 
 20 texture TEXTURE_SOLDIER       "ModelsMP\\Enemies\\Grunt\\elite_merc\\merc_elite.tex",
 21 texture TEXTURE_COMMANDER     "ModelsMP\\Enemies\\Grunt\\merc\\elite_merc.tex",
 22 texture TEXTURE_GUN_COMMANDER "Models\\Weapons\\TommyGun\\Body.tex",
 23 texture TEXTURE_GUN_SOLDIER   "Models\\Weapons\\P90\\p90.tex",
 
// ************** SOUNDS **************
 50 sound   SOUND_IDLE            "ModelsMP\\Enemies\\Grunt\\Sounds\\Idle.wav",
 52 sound   SOUND_SIGHT           "ModelsMP\\Enemies\\Grunt\\Sounds\\Sight.wav",
 53 sound   SOUND_WOUND           "ModelsMP\\Enemies\\Grunt\\Sounds\\Wound.wav",
 57 sound   SOUND_FIRE            "ModelsMP\\Enemies\\Grunt\\Sounds\\Fire.wav",
 58 sound   SOUND_DEATH           "ModelsMP\\Enemies\\Grunt\\Sounds\\Death.wav",
 
 59 model   MODEL_GRUNT_COMMANDER   "ModelsMP\\Enemies\\Grunt\\merc\\merc_idle.mdl",
 60 model   MODEL_SHELM_COMMANDER   "ModelsMP\\Enemies\\Grunt\\merc\\sh_nv.mdl",
 61 texture TEXTURE_SHELM_COMMANDER "ModelsMP\\Enemies\\Grunt\\merc\\nightvision.tex",
 62 sound   SOUND_FIRE_1            "ModelsMP\\Enemies\\Grunt\\Sounds\\Fire_1.wav",

functions:
    
  // describe how this enemy killed player
  virtual CTString GetPlayerKillDescription(const CTString &strPlayerName, const EDeath &eDeath)
  {
    CTString str;
    str.PrintF(TRANS("A Grunt sent %s into the halls of Valhalla"), strPlayerName);
    return str;
  }

  /* Entity info */
  void *GetEntityInfo(void) {
    if (m_gtType==GT_SOLDIER) {
      return &eiGruntSoldier;
    } else if (m_gtType==GT_COMMANDER) {
      return &eiGruntSoldier;
    } else {
      ASSERT("Unknown grunt type!");
      return NULL;
    }
  };

  virtual const CTFileName &GetComputerMessageName(void) const {
    static DECLARE_CTFILENAME(fnmSoldier,     "DataMP\\Messages\\Enemies\\GruntSoldier.txt");
    static DECLARE_CTFILENAME(fnmCommander,   "DataMP\\Messages\\Enemies\\GruntCommander.txt");
    switch(m_gtType) {
    default: ASSERT(FALSE);
    case GT_SOLDIER:  return fnmSoldier;
    case GT_COMMANDER: return fnmCommander;
    }
  };

  void Precache(void) {
    CEnemyBase::Precache();
    
    if (m_gtType==GT_SOLDIER) {
      PrecacheClass(CLASS_PROJECTILE, PRT_GRUNT_PROJECTILE_SOL);
    }
    if (m_gtType==GT_COMMANDER) {
      PrecacheClass(CLASS_PROJECTILE, PRT_GRUNT_PROJECTILE_COM);
    }
    
    PrecacheClass(CLASS_BULLET);  // Precache bullet class

    PrecacheSound(SOUND_IDLE);
    PrecacheSound(SOUND_SIGHT);
    PrecacheSound(SOUND_WOUND);
    PrecacheSound(SOUND_FIRE);
    PrecacheSound(SOUND_DEATH);
  };

  /* Receive damage */
  void ReceiveDamage(CEntity *penInflictor, enum DamageType dmtType,
    FLOAT fDamageAmmount, const FLOAT3D &vHitPoint, const FLOAT3D &vDirection) 
  {
    CEnemyBase::ReceiveDamage(penInflictor, dmtType, fDamageAmmount, vHitPoint, vDirection);
  };

  // damage anim
  INDEX AnimForDamage(FLOAT fDamage) {
    INDEX iAnim;
    if(m_gtType==GT_SOLDIER) { iAnim = MERC_ELITE_ANIM_WOUND01;}
    if(m_gtType==GT_COMMANDER) { iAnim = MERC_IDLE_ANIM_WOUND01;}
    StartModelAnim(iAnim, 0);
    return iAnim;
  };

  // death
  INDEX AnimForDeath(void) {
    INDEX iAnim;
    FLOAT3D vFront;
    GetHeadingDirection(0, vFront);
    FLOAT fDamageDir = m_vDamage%vFront;
    if(m_gtType==GT_SOLDIER){
      if (fDamageDir<0) {
        iAnim = MERC_ELITE_ANIM_DEATHBACKWARD;
      } else {
        iAnim = MERC_ELITE_ANIM_DEATHFORWARD;
      }
    }
    if(m_gtType==GT_COMMANDER){
      if (fDamageDir<0) {
        iAnim = MERC_IDLE_ANIM_DEATHBACKWARD;
      } else {
        iAnim = MERC_IDLE_ANIM_DEATHFORWARD;
      }
    }

    StartModelAnim(iAnim, 0);
    return iAnim;
  };

  FLOAT WaitForDust(FLOAT3D &vStretch) {
    vStretch=FLOAT3D(1,1,2);
    if(m_gtType==GT_SOLDIER){
      if(GetModelObject()->GetAnim()==MERC_ELITE_ANIM_DEATHBACKWARD) {
        return 0.5f;
      } else if(GetModelObject()->GetAnim()==MERC_ELITE_ANIM_DEATHFORWARD) {
        return 1.0f;
      }
    }
    if(m_gtType==GT_COMMANDER){
      if(GetModelObject()->GetAnim()==MERC_IDLE_ANIM_DEATHBACKWARD) {
        return 0.5f;
      } else if(GetModelObject()->GetAnim()==MERC_IDLE_ANIM_DEATHFORWARD) {
        return 1.0f;
      }
    }
    return -1.0f;
  };

  void DeathNotify(void) {
    if(m_gtType==GT_SOLDIER) { ChangeCollisionBoxIndexWhenPossible(MERC_ELITE_COLLISION_BOX_DEATH); }
    if(m_gtType==GT_COMMANDER) { ChangeCollisionBoxIndexWhenPossible(MERC_IDLE_COLLISION_BOX_DEATH); }
    en_fDensity = 500.0f;
  };

  // virtual anim functions
  void StandingAnim(void) {
    if(m_gtType==GT_SOLDIER){
      StartModelAnim(MERC_ELITE_ANIM_IDLEPATROL, AOF_LOOPING|AOF_NORESTART);
    }
    if(m_gtType==GT_COMMANDER){
      StartModelAnim(MERC_IDLE_ANIM_IDLE, AOF_LOOPING|AOF_NORESTART);
    }
  };
  
  void StandingAnimFight(void) {
    if(m_gtType==GT_SOLDIER){
      StartModelAnim(MERC_ELITE_ANIM_FIRE, AOF_LOOPING|AOF_NORESTART);
    }
    if(m_gtType==GT_COMMANDER){
      StartModelAnim(MERC_IDLE_ANIM_FIRE, AOF_LOOPING|AOF_NORESTART);
    }
  }
  
  void RunningAnim(void) {
    if(m_gtType==GT_SOLDIER){
      StartModelAnim(MERC_ELITE_ANIM_RUN, AOF_LOOPING|AOF_NORESTART);
    }
    if(m_gtType==GT_COMMANDER){
      StartModelAnim(MERC_IDLE_ANIM_RUN, AOF_LOOPING|AOF_NORESTART);
    }
  };
  
  void WalkingAnim(void) {
    if(m_gtType==GT_SOLDIER){
      StartModelAnim(MERC_ELITE_ANIM_WALK, AOF_LOOPING|AOF_NORESTART);
    }
    if(m_gtType==GT_COMMANDER){
      StartModelAnim(MERC_IDLE_ANIM_WALK, AOF_LOOPING|AOF_NORESTART);
    }
  };
  
  void RotatingAnim(void) {
    RunningAnim();
  };

  // virtual sound functions
  void IdleSound(void) {
    PlaySound(m_soSound, SOUND_IDLE, SOF_3D);
  };
  
  void SightSound(void) {
    PlaySound(m_soSound, SOUND_SIGHT, SOF_3D);
  };
  
  void WoundSound(void) {
    PlaySound(m_soSound, SOUND_WOUND, SOF_3D);
  };
  
  void DeathSound(void) {
    PlaySound(m_soSound, SOUND_DEATH, SOF_3D);
  };

  // adjust sound and watcher parameters here if needed
  void EnemyPostInit(void) 
  {
    // set sound default parameters
    m_soFire1.Set3DParameters(160.0f, 50.0f, 1.0f, 1.0f);
    m_soFire2.Set3DParameters(160.0f, 50.0f, 1.0f, 1.0f);
  };
  
  // Can enemy see player to fire?
  BOOL CanFireAtPlayer(void) {
    // get ray source and target
    FLOAT3D vSource, vTarget;
    GetPositionCastRay(this, m_penEnemy, vSource, vTarget);

    // bullet start position
    CPlacement3D plBullet;
    plBullet.pl_OrientationAngle = ANGLE3D(0,0,0);
    if (m_gtType == GT_SOLDIER) {
      plBullet.pl_PositionVector = FIREPOS_SOLDIER;
    } else {
      plBullet.pl_PositionVector = FIREPOS_COMMANDER_DN;
    }
    plBullet.RelativeToAbsolute(GetPlacement());
    vSource = plBullet.pl_PositionVector;

    // cast the ray
    CCastRay crRay(this, vSource, vTarget);
    crRay.cr_ttHitModels = CCastRay::TT_NONE;
    crRay.cr_bHitTranslucentPortals = FALSE;
    en_pwoWorld->CastRay(crRay);

    return (crRay.cr_penHit==NULL);
  }

  // Prepare bullet
  void PrepareBullet(FLOAT fDamage) {
    // bullet start position
    CPlacement3D plBullet;
    plBullet.pl_OrientationAngle = ANGLE3D(0,0,0);
    if (m_gtType == GT_SOLDIER) {
      plBullet.pl_PositionVector = FIREPOS_SOLDIER;
    } else {
      plBullet.pl_PositionVector = FIREPOS_COMMANDER_DN;
    }
    plBullet.RelativeToAbsolute(GetPlacement());
    
    // create bullet
    CEntityPointer penBullet = CreateEntity(plBullet, CLASS_BULLET);
    
    // init bullet
    EBulletInit eInit;
    eInit.penOwner = this;
    eInit.fDamage = fDamage;
    penBullet->Initialize(eInit);
    
    // calculate target
    ((CBullet&)*penBullet).CalcTarget(m_penEnemy, 250);
    ((CBullet&)*penBullet).LaunchBullet(TRUE, TRUE, TRUE);
    ((CBullet&)*penBullet).DestroyBullet();
  }

  // Fire bullet
  void FireBullet(void) {
    // binary divide counter
    m_bFireBulletCount++;
    if (m_bFireBulletCount>1) { m_bFireBulletCount = 0; }
    if (m_bFireBulletCount==1) { return; }
    
    // bullet start position
    CPlacement3D plBullet;
    plBullet.pl_OrientationAngle = ANGLE3D(0,0,0);
    if (m_gtType == GT_SOLDIER) {
      plBullet.pl_PositionVector = FIREPOS_SOLDIER;
    } else {
      plBullet.pl_PositionVector = FIREPOS_COMMANDER_DN;
    }
    plBullet.RelativeToAbsolute(GetPlacement());
    
    // create bullet
    CEntityPointer penBullet = CreateEntity(plBullet, CLASS_BULLET);
    
    // init bullet with random spread
    EBulletInit eInit;
    eInit.penOwner = this;
    eInit.fDamage = BULLET_DAMAGE;
    penBullet->Initialize(eInit);
    
    // calculate target with some spread
    ((CBullet&)*penBullet).CalcTarget(m_penEnemy, 250);
    ((CBullet&)*penBullet).CalcJitterTarget(18.0f); // Smaller spread than shotgun
    ((CBullet&)*penBullet).LaunchBullet(TRUE, TRUE, TRUE);
    ((CBullet&)*penBullet).DestroyBullet();
  }

  // Fire shotgun spread
  void FireShotgun(void) {
    // main bullet on center
    PrepareBullet(BULLET_DAMAGE);
    
    // Add bullets with spread
    for(INDEX i=0; i<7; i++) {
      CPlacement3D plBullet;
      plBullet.pl_OrientationAngle = ANGLE3D(0,0,0);
      if (m_gtType == GT_SOLDIER) {
        plBullet.pl_PositionVector = FIREPOS_SOLDIER;
      } else {
        plBullet.pl_PositionVector = FIREPOS_COMMANDER_DN;
      }
      plBullet.RelativeToAbsolute(GetPlacement());
      
      // create bullet
      CEntityPointer penBullet = CreateEntity(plBullet, CLASS_BULLET);
      
      // init bullet with random spread
      EBulletInit eInit;
      eInit.penOwner = this;
      eInit.fDamage = BULLET_DAMAGE;
      penBullet->Initialize(eInit);
      
      // calculate jittered target
      ((CBullet&)*penBullet).CalcTarget(m_penEnemy, 250);
      ((CBullet&)*penBullet).CalcJitterTarget(35.0f); // Spread angle
      ((CBullet&)*penBullet).LaunchBullet(TRUE, TRUE, TRUE);
      ((CBullet&)*penBullet).DestroyBullet();
    }
  }

procedures:
/************************************************************
 *                A T T A C K   E N E M Y                   *
 ************************************************************/
  // Soldier attack
  SoldierAttack(EVoid) {
    StandingAnimFight();
    autowait(0.2f + FRnd()*0.25f);

    // Set up automatic firing with spread
    m_fFireTime = _pTimer->CurrentTick() + 4.0f;
    m_bFireBulletCount = 0;
    PlaySound(m_soFire1, SOUND_FIRE_1, SOF_3D|SOF_LOOP);
    StartModelAnim(MERC_ELITE_ANIM_FIRE, AOF_LOOPING|AOF_NORESTART);

    while (m_fFireTime > _pTimer->CurrentTick()) {
      wait(0.05f) {
        on (EBegin) : {
          // Fire bullet with spread
          FireBullet();
          
          if (!IsInPlaneFrustum(m_penEnemy, CosFast(5.0f))) {
            m_fMoveSpeed = 0.0f;
            m_aRotateSpeed = 4000.0f;
          } else {
            m_fMoveSpeed = 0.0f;
            m_aRotateSpeed = 0.0f;
          }
          SetDesiredMovement();
          resume;
        }
        on (ETimer) : { stop; }
      }
    }
    
    m_soFire1.Stop();
    m_fShootTime = _pTimer->CurrentTick() + m_fAttackFireTime*(1.0f + FRnd()/3.0f);
    return EEnd();
  };

  // Commander attack (auto rifle)
  CommanderAttack(EVoid) {
    StandingAnimFight();
    autowait(0.2f + FRnd()*0.25f);

    // Set up automatic firing with spread
    m_fFireTime = _pTimer->CurrentTick() + 4.0f;
    m_bFireBulletCount = 0;
    PlaySound(m_soFire1, SOUND_FIRE_1, SOF_3D|SOF_LOOP);
    StartModelAnim(MERC_IDLE_ANIM_FIRE, AOF_LOOPING|AOF_NORESTART);

    while (m_fFireTime > _pTimer->CurrentTick()) {
      wait(0.05f) {
        on (EBegin) : {
          // Fire bullet with spread
          FireBullet();
          
          if (!IsInPlaneFrustum(m_penEnemy, CosFast(5.0f))) {
            m_fMoveSpeed = 0.0f;
            m_aRotateSpeed = 4000.0f;
          } else {
            m_fMoveSpeed = 0.0f;
            m_aRotateSpeed = 0.0f;
          }
          SetDesiredMovement();
          resume;
        }
        on (ETimer) : { stop; }
      }
    }
    
    m_soFire1.Stop();
    m_fShootTime = _pTimer->CurrentTick() + m_fAttackFireTime*(1.0f + FRnd()/3.0f);
    return EEnd();
  };

  // Shotgun attack
  ShotgunAttack(EVoid) {
    StandingAnimFight();
    autowait(0.3f + FRnd()*0.2f); // Longer preparation before shooting

    StartModelAnim(MERC_IDLE_ANIM_FIRE, 0);
    FireShotgun();
    
    autowait(0.5f); // Recoil after shooting
    
    // Longer reload time
    m_fShootTime = _pTimer->CurrentTick() + 1.5f + FRnd()*0.5f;
    return EEnd();
  };
 
  Fire(EVoid) : CEnemyBase::Fire {
    if (m_gtType == GT_SOLDIER) {
      autocall SoldierAttack() EEnd;
    } else if (m_gtType == GT_COMMANDER) {
      if (m_gwtWeapon == GWT_AUTO_RIFLE) {
        autocall CommanderAttack() EEnd;
      } else if (m_gwtWeapon == GWT_SHOTGUN) {
        autocall ShotgunAttack() EEnd;
      }
    }
    return EReturn();
  };

/************************************************************
 *                       M  A  I  N                         *
 ************************************************************/
  Main(EVoid) {
    // declare yourself as a model
    InitAsModel();
    SetPhysicsFlags(EPF_MODEL_WALKING|EPF_HASLUNGS);
    SetCollisionFlags(ECF_MODEL);
    SetFlags(GetFlags()|ENF_ALIVE);
    en_tmMaxHoldBreath = 5.0f;
    en_fDensity = 2000.0f;
    //m_fBlowUpSize = 2.0f;

    // set your appearance
    switch (m_gtType) {
      case GT_SOLDIER:
        // set your texture
        SetModel(MODEL_GRUNT);
        SetModelMainTexture(TEXTURE_SOLDIER);
        AddAttachment(MERC_ELITE_ATTACHMENT_P90_MERC, MODEL_GUN_SOLDIER, TEXTURE_GUN_SOLDIER);
        // setup moving speed
        m_fWalkSpeed = FRnd() + 2.5f;
        m_aWalkRotateSpeed = AngleDeg(FRnd()*10.0f + 500.0f);
        m_fAttackRunSpeed = FRnd() + 6.5f;
        m_aAttackRotateSpeed = AngleDeg(FRnd()*50 + 245.0f);
        m_fCloseRunSpeed = FRnd() + 6.5f;
        m_aCloseRotateSpeed = AngleDeg(FRnd()*50 + 245.0f);
        // setup attack distances
        m_fAttackDistance = 80.0f;
        m_fCloseDistance = 0.0f;
        m_fStopDistance = 8.0f;
        m_fAttackFireTime = 2.0f;
        m_fCloseFireTime = 1.0f;
        m_fIgnoreRange = 200.0f;
        //m_fBlowUpAmount = 65.0f;
        m_fBlowUpAmount = 80.0f;
        m_fBodyParts = 4;
        m_fDamageWounded = 0.0f;
        m_iScore = 500;
        SetHealth(40.0f);
        m_fMaxHealth = 40.0f;
        // set stretch factors for height and width
        GetModelObject()->StretchModel(FLOAT3D(STRETCH_SOLDIER, STRETCH_SOLDIER, STRETCH_SOLDIER));
        break;
  
      case GT_COMMANDER:
        // set your texture
        SetModel(MODEL_GRUNT_COMMANDER);
        SetModelMainTexture(TEXTURE_COMMANDER);
        AddAttachment(MERC_IDLE_ATTACHMENT_SH_NV, MODEL_SHELM_COMMANDER, TEXTURE_SHELM_COMMANDER);
        AddAttachment(MERC_IDLE_ATTACHMENT_AG36_MERC, MODEL_GUN_COMMANDER, TEXTURE_GUN_COMMANDER);
        if (m_gwtWeapon == GWT_SHOTGUN){
          m_fAttackDistance = 50.0f; // Close range
          m_fAttackFireTime = 1.5f;  // Slower firing rate
        }
        // setup moving speed
        m_fWalkSpeed = FRnd() + 2.5f;
        m_aWalkRotateSpeed = AngleDeg(FRnd()*10.0f + 500.0f);
        m_fAttackRunSpeed = FRnd() + 8.0f;
        m_aAttackRotateSpeed = AngleDeg(FRnd()*50 + 245.0f);
        m_fCloseRunSpeed = FRnd() + 8.0f;
        m_aCloseRotateSpeed = AngleDeg(FRnd()*50 + 245.0f);
        // setup attack distances
        m_fAttackDistance = 90.0f;
        m_fCloseDistance = 0.0f;
        m_fStopDistance = 15.0f;
        m_fAttackFireTime = 4.0f;
        m_fCloseFireTime = 2.0f;
        //m_fBlowUpAmount = 180.0f;
        m_fIgnoreRange = 200.0f;
        // damage/explode properties
        m_fBodyParts = 5;
        m_fDamageWounded = 0.0f;
        m_iScore = 800;
        SetHealth(60.0f);
        m_fMaxHealth = 60.0f;
        // set stretch factors for height and width
        GetModelObject()->StretchModel(FLOAT3D(STRETCH_COMMANDER, STRETCH_COMMANDER, STRETCH_COMMANDER));
        break;
    }

    ModelChangeNotify();
    StandingAnim();

    // continue behavior in base class
    jump CEnemyBase::MainLoop();
  };
};