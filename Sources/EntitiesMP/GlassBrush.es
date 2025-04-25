700
%{
#include "StdH.h"
%}

//uses "EntitiesMP/MovingBrushMarker";
uses "EntitiesMP/SoundHolder";
uses "EntitiesMP\MirrorMarker";
uses "EntitiesMP/Debris";

event EGBrushDestroyed { // sent to all children of a moving brush when it is destroyed
};

/*enum BlockAction {
  0 BA_NONE         "None",         // continue moving
  1 BA_BOUNCE       "Bounce",       // bounce when obstructed
  2 BA_SKIPMARKER   "Skip marker",  // skip moving to next marker
};*/

enum TouchOrDamageBrushEvent {
  0 TDE_TOUCHONLY   "Touch Only", 
  1 TDE_DAMAGEONLY  "Damage Only", 
  2 TDE_BOTH        "Both", 
};

//type debrises
enum DebrisType {
  0 DT_GLASS        "Glass", 
  1 DT_STONE        "Stone",
  2 DT_WOOD         "Wood",
  3 DT_METAL        "Metal",
};

%{
static const float TRANSLATION_EPSILON=0.05f;
static const float ROTATION_EPSILON=0.05f;
extern void GetDefaultForce(INDEX iForce, const FLOAT3D &vPoint, 
    CForceStrength &fsGravity, CForceStrength &fsField);
%}

class CGlassBrush : CMovableBrushEntity {
name      "Glass Brush";
thumbnail "Thumbnails\\GlassBrush.tbn";
features  "HasName", "IsTargetable";

properties:
  1 CTString m_strName            "Name" 'N' = "Glass Brush",
  2 CTString m_strDescription = "",
  
  // Здоровье и разрушение
  3 FLOAT m_fHealth             "Health" 'H' = -1.0f,
  4 BOOL m_bBlowupByBull        "Blowup by Bull" = FALSE,
  5 BOOL m_bBlowupByDamager     "Blowup by Damager" = FALSE,
  6 enum EventEType m_eetBlowupEvent "Blowup Event - Type" = EET_IGNORE,
  7 CEntityPointer m_penBlowupEvent  "Blowup Event - Target" COLOR(C_BLACK|0xFF),
  8 BOOL m_bZoning              "Zoning" 'Z' = FALSE,

  // Звук разрушения (только один звук)
  9 CEntityPointer m_penSoundDestroy  "Destroy Sound" 'S' COLOR(C_RED|0xFF),  // сущность со звуком
  10 CSoundObject m_soDestroy,  // объект звука

  // Визуальные эффекты
  11 COLOR m_colDebrises         "Color of debrises" = C_WHITE,
  12 INDEX m_ctDebrises          "Debris count" = 12,
  13 FLOAT m_fCandyEffect        "Debris blow power" = 0.0f,
  14 FLOAT m_fCubeFactor         "Cube factor" = 1.0f,
  15 enum DebrisType m_dtDebrisType "Debris Type" = DT_GLASS,

  // Тени и видимость
  16 BOOL m_bDynamicShadows      "Dynamic shadows" = FALSE,
  
  17 FLOAT m_fTouchDamage        "Touch damage" = 0.0f,
  18 enum EventEType m_eetTouchEvent "Touch Event - Type" 'U' = EET_IGNORE,
  19 CEntityPointer m_penTouchEvent  "Touch Event - Target" 'I' COLOR(C_dCYAN|0xFF),
  20 enum TouchOrDamageBrushEvent m_tdeSendEventOnDamage "Send touch event on damage" = TDE_TOUCHONLY,

components:
  1 model     MODEL_GLASS        "Models\\Effects\\Debris\\Glass\\glass.mdl",
  2 texture   TEXTURE_GLASS      "TexturesMP\\Detail\\white.tex",
  
  3 model     MODEL_STONE        "Models\\Effects\\Debris\\Stone\\Stone.mdl",
  4 texture   TEXTURE_STONE      "Models\\Effects\\Debris\\Stone\\Stone.tex",
  
  5 model     MODEL_WOOD         "Models\\Effects\\Debris\\Wood01\\Wood.mdl",
  6 texture   TEXTURE_WOOD       "Models\\Effects\\Debris\\Wood01\\Wood.tex",
  
  7 model     MODEL_METAL        "Models\\Effects\\Debris\\Fruits\\Apple.mdl",
  8 texture   TEXTURE_METAL      "Models\\Effects\\Debris\\Fruits\\Apple.tex",
  
  9 class     CLASS_DEBRIS       "Classes\\Debris.ecl",
  10 class     CLASS_BASIC_EFFECT "Classes\\BasicEffect.ecl",

functions:
  void Precache(void) {
    PrecacheClass(CLASS_DEBRIS);
    PrecacheClass(CLASS_BASIC_EFFECT);
	
    PrecacheModel(MODEL_GLASS);
    PrecacheTexture(TEXTURE_GLASS);
    PrecacheModel(MODEL_STONE);
    PrecacheTexture(TEXTURE_STONE);
    PrecacheModel(MODEL_WOOD);
    PrecacheTexture(TEXTURE_WOOD);
    PrecacheModel(MODEL_METAL);
    PrecacheTexture(TEXTURE_METAL);
  };

  // Воспроизведение звука разрушения
  void PlayDestroySound(void) {
    if (m_penSoundDestroy != NULL) {
      CSoundHolder &sh = (CSoundHolder&)*m_penSoundDestroy;
      m_soDestroy.Set3DParameters(FLOAT(sh.m_rFallOffRange), FLOAT(sh.m_rHotSpotRange), sh.m_fVolume, 1.0f);
      PlaySound(m_soDestroy, sh.m_fnSound, sh.m_iPlayType);
    }
  };
  
    // Get model and texture for current type debrises
  void GetDebrisModelTexture(INDEX &iModel, INDEX &iTexture) {
    switch(m_dtDebrisType) {
      case DT_STONE:
        iModel = MODEL_STONE;
        iTexture = TEXTURE_STONE;
        break;
      case DT_WOOD:
        iModel = MODEL_WOOD;
        iTexture = TEXTURE_WOOD;
        break;
      case DT_METAL:
        iModel = MODEL_METAL;
        iTexture = TEXTURE_METAL;
        break;
      case DT_GLASS:
      default:
        iModel = MODEL_GLASS;
        iTexture = TEXTURE_GLASS;
        break;
    }
  };
  
    // Get type debris for Debris_Begin
  INDEX GetDebrisImpactType(void) {
    switch(m_dtDebrisType) {
      case DT_STONE: return EIBT_ROCK;
      case DT_WOOD:  return EIBT_WOOD;
      case DT_METAL: return EIBT_METAL;
      case DT_GLASS: return EIBT_GLASS;
    }
	return EIBT_GLASS;
  };
  
  // Check if entity can react to touch/damage
  BOOL CanReactOnEntity(CEntity *pen) {
    if (pen==NULL) {
      return FALSE;
    }
    if (!(pen->GetFlags()&ENF_ALIVE)) {
      return FALSE;
    }
    return TRUE;
  };

   void ReceiveDamage(CEntity *penInflictor, enum DamageType dmtType,
    FLOAT fDamageAmmount, const FLOAT3D &vHitPoint, const FLOAT3D &vDirection) 
  {
    if (m_fHealth < 0){return;}

    // send event on damage
    if(m_tdeSendEventOnDamage!=TDE_TOUCHONLY && CanReactOnEntity(penInflictor)) {
      SendToTarget(m_penTouchEvent, m_eetTouchEvent, penInflictor);
    }

    if (m_bBlowupByBull && dmtType == DMT_IMPACT && IsOfClass(penInflictor, "Werebull")) {
      CMovableBrushEntity::ReceiveDamage(penInflictor, dmtType, m_fHealth*2, vHitPoint, vDirection);
      ((CLiveEntity*)penInflictor)->SetHealth(0.0f);
      return;
    }

    if (m_bBlowupByDamager && dmtType == DMT_DAMAGER) {
      CMovableBrushEntity::ReceiveDamage(penInflictor, dmtType, fDamageAmmount, vHitPoint, vDirection);
      return;
    }

    if (dmtType == DMT_EXPLOSION || dmtType == DMT_PROJECTILE || dmtType == DMT_CANNONBALL) {
      CMovableBrushEntity::ReceiveDamage(penInflictor, dmtType, fDamageAmmount, vHitPoint, vDirection);
    }
  };

procedures:
  Main() {
    InitAsBrush();
    SetPhysicsFlags(EPF_BRUSH_FIXED);
    SetCollisionFlags(ECF_BRUSH);
    SetHealth(m_fHealth);

    if (m_bZoning){ SetFlags(GetFlags() | ENF_ZONING);}
    if (m_bDynamicShadows){ SetFlags(GetFlags() | ENF_DYNAMICSHADOWS);}

    wait() {
	
	   on (ETouch eTouch) : {
        // inflict damage if required
        if(m_fTouchDamage != 0.0f) {
          InflictDirectDamage(eTouch.penOther, this, DMT_SPIKESTAB, m_fTouchDamage,
                     eTouch.penOther->GetPlacement().pl_PositionVector, eTouch.plCollision);
        }
        // send event on touch
        if(m_tdeSendEventOnDamage!=TDE_DAMAGEONLY && CanReactOnEntity(eTouch.penOther)) {
          SendToTarget(m_penTouchEvent, m_eetTouchEvent);
        }
        resume;
      }
	  
      on (EDeath eDeath) : {
        // Звук разрушения
        PlayDestroySound();

        // Создание обломков
        if (m_ctDebrises > 0) {
          FLOATaabbox3D box;
          GetSize(box);
          FLOAT fEntitySize = pow(box.Size()(1)*box.Size()(2)*box.Size()(3)/m_ctDebrises, 1.0f/3.0f)*m_fCubeFactor;
          
		  //INDEX iDebrisType = GetDebrisImpactType();
		  EntityInfoBodyType eibtDebris = (EntityInfoBodyType)GetDebrisImpactType();
          Debris_Begin(eibtDebris, DPT_NONE, BET_NONE, fEntitySize, FLOAT3D(1.0f,2.0f,3.0f),
            FLOAT3D(0,0,0), 1.0f + m_fCandyEffect/2.0f, m_fCandyEffect, m_colDebrises);
			
		  // Get model and texture
          INDEX iModel, iTexture;
          GetDebrisModelTexture(iModel, iTexture);
		  
          for (INDEX iDebris = 0; iDebris < m_ctDebrises; iDebris++) {
            Debris_Spawn(this, this, iModel, iTexture, 0, 0, 0, IRnd()%4, 1.0f,
              FLOAT3D(FRnd()*0.8f+0.1f, FRnd()*0.8f+0.1f, FRnd()*0.8f+0.1f));
          }
        }

        // Уведомление дочерних объектов
        FOREACHINLIST(CEntity, en_lnInParent, en_lhChildren, iten) {
          iten->SendEvent(EGBrushDestroyed());
        }

        // Отправка события
        SendToTarget(m_penBlowupEvent, m_eetBlowupEvent, eDeath.eLastDamage.penInflictor);

        // Деактивация объекта
        SetFlags(GetFlags() | ENF_HIDDEN);
        SetCollisionFlags(ECF_IMMATERIAL);
        stop;
      }
    }
    return;
  }
};
