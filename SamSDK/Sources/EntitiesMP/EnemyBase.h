/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_EnemyBase_INCLUDED
#define _EntitiesMP_EnemyBase_INCLUDED 1
#include <EntitiesMP/Watcher.h>
#include <EntitiesMP/BasicEffects.h>
#include <EntitiesMP/Projectile.h>
#include <EntitiesMP/Debris.h>
#include <EntitiesMP/EnemyMarker.h>
#include <EntitiesMP/MusicHolder.h>
#include <EntitiesMP/BloodSpray.h>
#define EVENTCODE_ERestartAttack 0x01360000
class DECL_DLL ERestartAttack : public CEntityEvent {
public:
ERestartAttack();
CEntityEvent *MakeCopy(void);
};
DECL_DLL inline void ClearToDefault(ERestartAttack &e) { e = ERestartAttack(); } ;
#define EVENTCODE_EReconsiderBehavior 0x01360001
class DECL_DLL EReconsiderBehavior : public CEntityEvent {
public:
EReconsiderBehavior();
CEntityEvent *MakeCopy(void);
};
DECL_DLL inline void ClearToDefault(EReconsiderBehavior &e) { e = EReconsiderBehavior(); } ;
#define EVENTCODE_EForceWound 0x01360002
class DECL_DLL EForceWound : public CEntityEvent {
public:
EForceWound();
CEntityEvent *MakeCopy(void);
};
DECL_DLL inline void ClearToDefault(EForceWound &e) { e = EForceWound(); } ;
extern DECL_DLL CEntityPropertyEnumType TargetType_enum;
enum TargetType {
  TT_NONE = 0,
  TT_SOFT = 1,
  TT_HARD = 2,
};
DECL_DLL inline void ClearToDefault(TargetType &e) { e = (TargetType)0; } ;
extern DECL_DLL CEntityPropertyEnumType DestinationType_enum;
enum DestinationType {
  DT_PLAYERCURRENT = 0,
  DT_PLAYERSPOTTED = 1,
  DT_PATHTEMPORARY = 2,
  DT_PATHPERSISTENT = 3,
};
DECL_DLL inline void ClearToDefault(DestinationType &e) { e = (DestinationType)0; } ;
extern "C" DECL_DLL CDLLEntityClass CEnemyBase_DLLClass;
class DECL_DLL  CEnemyBase : public CMovableModelEntity {
public:
virtual const CTString &GetName(void) const { return m_strName; };
virtual BOOL IsTargetable(void) const { return TRUE; };
virtual CEntity *GetPredictionPair(void) { return m_penPrediction; };
virtual void SetPredictionPair(CEntity *penPair) { m_penPrediction = penPair; };
   virtual void SetDefaultProperties(void);
  CEntityPointer m_penWatcher;
  FLOAT3D m_vStartPosition;
  CEntityPointer m_penEnemy;
  enum TargetType m_ttTarget;
  CTString m_strDescription;
  CTString m_strName;
  CSoundObject m_soSound;
  FLOAT3D m_vStartDirection;
  BOOL m_bOnStartPosition;
  FLOAT m_fFallHeight;
  FLOAT m_fStepHeight;
  RANGE m_fSenseRange;
  FLOAT m_fViewAngle;
  FLOAT m_fWalkSpeed;
  ANGLE m_aWalkRotateSpeed;
  FLOAT m_fAttackRunSpeed;
  ANGLE m_aAttackRotateSpeed;
  FLOAT m_fCloseRunSpeed;
  ANGLE m_aCloseRotateSpeed;
  FLOAT m_fAttackDistance;
  FLOAT m_fCloseDistance;
  FLOAT m_fAttackFireTime;
  FLOAT m_fCloseFireTime;
  FLOAT m_fStopDistance;
  FLOAT m_fIgnoreRange;
  FLOAT m_fLockOnEnemyTime;
  FLOAT m_fBlowUpAmount;
  INDEX m_fBodyParts;
  FLOAT m_fDamageWounded;
  FLOAT3D m_vDamage;
  FLOAT m_tmLastDamage;
  BOOL m_bRobotBlowup;
  FLOAT m_fBlowUpSize;
  FLOAT m_fMoveTime;
  FLOAT3D m_vDesiredPosition;
  enum DestinationType m_dtDestination;
  CEntityPointer m_penPathMarker;
  FLOAT3D m_vPlayerSpotted;
  FLOAT m_fMoveFrequency;
  FLOAT m_fMoveSpeed;
  ANGLE m_aRotateSpeed;
  FLOAT m_fLockStartTime;
  FLOAT m_fRangeLast;
  BOOL m_bFadeOut;
  FLOAT m_fFadeStartTime;
  FLOAT m_fFadeTime;
  FLOAT m_fShootTime;
  FLOAT m_fDamageConfused;
  INDEX m_iChargeHitAnimation;
  FLOAT m_fChargeHitDamage;
  FLOAT m_fChargeHitAngle;
  FLOAT m_fChargeHitSpeed;
  CEntityPointer m_penSpawnerTarget;
  CEntityPointer m_penDeathTarget;
  enum EventEType m_eetDeathType;
  BOOL m_bTemplate;
  RANGE m_fAttackRadius;
  COLOR m_colColor;
  BOOL m_bDeaf;
  BOOL m_bBlind;
  FLOAT m_tmGiveUp;
  FLOAT m_tmReflexMin;
  FLOAT m_tmReflexMax;
  FLOAT m_fActivityRange;
  BOOL m_bApplyRandomStretch;
  FLOAT m_fRandomStretchFactor;
  FLOAT m_fStretchMultiplier;
  FLOAT m_fRandomStretchMultiplier;
  CEntityPointer m_penMarker;
  CEntityPointer m_penMainMusicHolder;
  FLOAT m_tmLastFussTime;
  FLOAT m_iScore;
  FLOAT m_fMaxHealth;
  BOOL m_bBoss;
  FLOAT m_fSpiritStartTime;
  FLOAT m_tmSpraySpawned;
  FLOAT m_fSprayDamage;
  CEntityPointer m_penSpray;
  FLOAT m_fMaxDamageAmmount;
  FLOAT3D m_vLastStain;
  enum SprayParticlesType m_sptType;
  CEntityPointer m_penTacticsHolder;
  BOOL m_bTacticActive;
  FLOAT m_tmTacticsActivation;
  FLOAT3D m_vTacticsStartPosition;
  FLOAT m_fTacticVar1;
  FLOAT m_fTacticVar2;
  FLOAT m_fTacticVar3;
  FLOAT m_fTacticVar4;
  FLOAT m_fTacticVar5;
  BOOL m_bTacticsStartOnSense;
  COLOR m_colBurning;
  BOOL m_bResizeAttachments;
  CEntityPointer m_penPrediction;
TIME m_tmPredict;
    CEnemyBase(void);
   
#line 216 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void SetPredictionTime(TIME tmAdvance);
   
#line 223 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
TIME GetPredictionTime(void);
  
#line 229 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual CTString GetPlayerKillDescription(const CTString & strPlayerName,const EDeath & eDeath);
  
#line 236 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual FLOAT GetCrushHealth(void);
  
#line 242 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual BOOL CountAsKill(void);
  
#line 247 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual BOOL ForcesCannonballToExplode(void);
  
#line 253 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual FLOAT & GetProp(FLOAT & m_fBase);
  
#line 259 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual FLOAT GetThreatDistance(void);
   
#line 266 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void MaybeSwitchToAnotherPlayer(void);
   
#line 287 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
class CWatcher * GetWatcher(void);
   void Copy(CEntity & enOther,ULONG ulFlags);
   
#line 298 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void Precache(void);
  
#line 323 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual FLOAT3D PlayerDestinationPos(void);
   
#line 329 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT3D CalcDelta(CEntity * penEntity);
   
#line 336 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT CalcDist(CEntity * penEntity);
   
#line 341 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL IfTargetCrushed(CEntity * penOther,const FLOAT3D & vDirection);
   
#line 357 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT3D CalcPlaneDelta(CEntity * penEntity);
   
#line 369 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT CalcPlaneDist(CEntity * penEntity);
   
#line 375 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT GetFrustumAngle(const FLOAT3D & vDir);
   
#line 384 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT GetPlaneFrustumAngle(const FLOAT3D & vDir);
   
#line 400 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL IsInFrustum(CEntity * penEntity,FLOAT fCosHalfFrustum);
   
#line 412 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL IsInPlaneFrustum(CEntity * penEntity,FLOAT fCosHalfFrustum);
   
#line 428 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL IsVisible(CEntity * penEntity);
   
#line 446 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL IsVisibleCheckAll(CEntity * penEntity);
   
#line 464 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void CalculateAngularLaunchParams(
#line 465 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT3D vShooting,FLOAT fShootHeight,
#line 466 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT3D vTarget,FLOAT3D vSpeedDest,
#line 467 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
ANGLE aPitch,
#line 468 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT & fLaunchSpeed,
#line 469 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT & fRelativeHdg);
   
#line 507 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT3D CalculatePredictedPosition(FLOAT3D vShootPos,FLOAT3D vTarget,
#line 508 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT fSpeedSrc,FLOAT3D vSpeedDst,FLOAT fClampY);
   
#line 532 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL MovesByTargetedRoute(CTString & strTargetProperty)const;
   
#line 537 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL DropsMarker(CTFileName & fnmMarkerClass,CTString & strTargetProperty)const;
   
#line 542 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
const CTString & GetDescription(void)const;
  
#line 550 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual const CTFileName & GetComputerMessageName(void)const;
   
#line 556 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void AddDependentsToPrediction(void);
   
#line 565 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void ChecksumForSync(ULONG & ulCRC,INDEX iExtensiveSyncCheck);
   
#line 569 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void DumpSync_t(CTStream & strm,INDEX iExtensiveSyncCheck);
   
#line 589 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void Read_t(CTStream * istr);
   
#line 599 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL FillEntityStatistics(EntityStats * pes);
   
#line 614 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 615 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection);
   
#line 780 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL AdjustShadingParameters(FLOAT3D & vLightDirection,COLOR & colLight,COLOR & colAmbient);
   
#line 842 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void AddToFuss(void);
   
#line 882 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void RemoveFromFuss(void);
   
#line 905 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL ShouldCeaseAttack(void);
  
#line 924 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void SizeModel(void);
   
#line 952 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL IsValidForEnemy(CEntity * penPlayer);
   
#line 961 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void SetTargetNone(void);
   
#line 969 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL SetTargetSoft(CEntity * penPlayer);
   
#line 990 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL SetTargetHard(CEntity * penPlayer);
   
#line 1011 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL SetTargetHardForce(CEntity * penPlayer);
  
#line 1031 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual FLOAT GetAttackMoveFrequency(FLOAT fEnemyDistance);
  
#line 1041 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void SetSpeedsToDesiredPosition(const FLOAT3D & vPosDelta,FLOAT fPosDist,BOOL bGoingToPlayer);
  
#line 1100 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void MovementAnimation(ULONG ulFlags);
  
#line 1122 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual ULONG SetDesiredMovement(void);
   
#line 1191 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void StopMoving();
   
#line 1198 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void StopRotating();
   
#line 1204 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void StopTranslating();
   
#line 1210 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT CalcDistanceInPlaneToDestination(void);
  
#line 1219 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void StartPathFinding(void);
  
#line 1243 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void FindNextPathMarker(void);
   
#line 1276 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL CheckTouchForPathFinding(const ETouch & eTouch);
   
#line 1308 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL CheckFallForPathFinding(const EWouldFall & eWouldFall);
   
#line 1336 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void InitializeTactics(void);
  
#line 1402 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void ApplyTactics(FLOAT3D & vDesiredPos);
   
#line 1531 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void StartTacticsNow(void);
   
#line 1539 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL CanAttackEnemy(CEntity * penTarget,FLOAT fCosAngle);
  
#line 1549 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual BOOL CanHitEnemy(CEntity * penTarget,FLOAT fCosAngle);
   
#line 1557 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL SeeEntity(CEntity * pen,FLOAT fCosAngle);
   
#line 1565 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL SeeEntityInPlane(CEntity * pen,FLOAT fCosAngle);
   
#line 1574 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void PreparePropelledProjectile(CPlacement3D & plProjectile,FLOAT3D vShootTarget,
#line 1575 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT3D & vOffset,ANGLE3D & aOffset);
   
#line 1598 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void PrepareFreeFlyingProjectile(CPlacement3D & plProjectile,FLOAT3D vShootTarget,
#line 1599 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT3D & vOffset,ANGLE3D & aOffset);
   
#line 1622 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
CEntity * ShootProjectile(enum ProjectileType pt,FLOAT3D & vOffset,ANGLE3D & aOffset);
   
#line 1644 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
CEntity * ShootProjectileAt(FLOAT3D vShootTarget,enum ProjectileType pt,FLOAT3D & vOffset,ANGLE3D & aOffset);
   
#line 1659 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
CEntity * ShootPredictedProjectile(enum ProjectileType pt,FLOAT3D vPredictedPos,FLOAT3D & vOffset,ANGLE3D & aOffset);
   
#line 1685 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL WouldNotLeaveAttackRadius(void);
  
#line 1700 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual BOOL MayMoveToAttack(void);
  
#line 1715 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual BOOL ShouldBlowUp(void);
   
#line 1734 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void BlowUpBase(void);
  
#line 1742 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void BlowUp(void);
  
#line 1814 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void LeaveStain(BOOL bGrow);
  
#line 1849 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void AdjustDifficulty(void);
   
#line 1883 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void WoundedNotify(const EDamage & eDamage);
   
#line 1902 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void SeeNotify();
  
#line 1921 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void StandingAnim(void);
  
#line 1922 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void StandingAnimFight(void);
  
#line 1923 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void WalkingAnim(void);
  
#line 1924 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void RunningAnim(void);
  
#line 1925 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void RotatingAnim(void);
  
#line 1926 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void ChargeAnim(void);
  
#line 1927 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual INDEX AnimForDamage(FLOAT fDamage);
  
#line 1928 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void BlowUpNotify(void);
  
#line 1929 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual INDEX AnimForDeath(void);
  
#line 1930 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual FLOAT WaitForDust(FLOAT3D & vStretch);
  
#line 1931 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void DeathNotify(void);
  
#line 1932 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void IdleSound(void);
  
#line 1933 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void SightSound(void);
  
#line 1934 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void WoundSound(void);
  
#line 1935 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void DeathSound(void);
  
#line 1936 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual FLOAT GetLockRotationSpeed(void);
   
#line 1940 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void RenderParticles(void);
  
#line 1955 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
virtual void EnemyPostInit(void);
   
#line 1958 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL HandleEvent(const CEntityEvent & ee);
   
#line 1978 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT GetAnimLength(int iAnim);
   
#line 1988 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT GetCurrentAnimLength();
   
#line 1998 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BOOL IsAnimFinished();
   
#line 2008 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT GetPassedTime();
   
#line 2017 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FLOAT3D & GetModelStretch();
   
#line 2027 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void StretchModel(FLOAT3D vStretch);
   
#line 2037 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
void StretchSingleModel(FLOAT3D vStretch);
   
#line 2048 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
SLONG GetUsedMemory(void);
#define  STATE_CEnemyBase_MoveToDestination 0x01360003
  BOOL 
#line 2068 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
MoveToDestination(const CEntityEvent &__eeInput);
  BOOL H0x01360004_MoveToDestination_01(const CEntityEvent &__eeInput);
  BOOL H0x01360005_MoveToDestination_02(const CEntityEvent &__eeInput);
  BOOL H0x01360006_MoveToDestination_03(const CEntityEvent &__eeInput);
  BOOL H0x01360007_MoveToDestination_04(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_MoveToRandomPatrolPosition 0x01360008
  BOOL 
#line 2093 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
MoveToRandomPatrolPosition(const CEntityEvent &__eeInput);
  BOOL H0x01360009_MoveToRandomPatrolPosition_01(const CEntityEvent &__eeInput);
  BOOL H0x0136000a_MoveToRandomPatrolPosition_02(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_DoPatrolling 0x0136000b
  BOOL 
#line 2133 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
DoPatrolling(const CEntityEvent &__eeInput);
  BOOL H0x0136000c_DoPatrolling_01(const CEntityEvent &__eeInput);
  BOOL H0x0136000d_DoPatrolling_02(const CEntityEvent &__eeInput);
  BOOL H0x0136000e_DoPatrolling_03(const CEntityEvent &__eeInput);
  BOOL H0x0136000f_DoPatrolling_04(const CEntityEvent &__eeInput);
  BOOL H0x01360010_DoPatrolling_05(const CEntityEvent &__eeInput);
  BOOL H0x01360011_DoPatrolling_06(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_BeIdle 0x01360012
  BOOL 
#line 2148 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BeIdle(const CEntityEvent &__eeInput);
  BOOL H0x01360013_BeIdle_01(const CEntityEvent &__eeInput);
  BOOL H0x01360014_BeIdle_02(const CEntityEvent &__eeInput);
  BOOL H0x01360015_BeIdle_03(const CEntityEvent &__eeInput);
  BOOL H0x01360016_BeIdle_04(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_ReturnToStartPosition 0x01360017
  BOOL 
#line 2166 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
ReturnToStartPosition(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_MoveThroughMarkers 0x01360018
  BOOL 
#line 2210 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
MoveThroughMarkers(const CEntityEvent &__eeInput);
  BOOL H0x01360019_MoveThroughMarkers_01(const CEntityEvent &__eeInput);
  BOOL H0x0136001a_MoveThroughMarkers_02(const CEntityEvent &__eeInput);
  BOOL H0x0136001b_MoveThroughMarkers_03(const CEntityEvent &__eeInput);
  BOOL H0x0136001c_MoveThroughMarkers_04(const CEntityEvent &__eeInput);
  BOOL H0x0136001d_MoveThroughMarkers_05(const CEntityEvent &__eeInput);
  BOOL H0x0136001e_MoveThroughMarkers_06(const CEntityEvent &__eeInput);
  BOOL H0x0136001f_MoveThroughMarkers_07(const CEntityEvent &__eeInput);
  BOOL H0x01360020_MoveThroughMarkers_08(const CEntityEvent &__eeInput);
  BOOL H0x01360021_MoveThroughMarkers_09(const CEntityEvent &__eeInput);
  BOOL H0x01360022_MoveThroughMarkers_10(const CEntityEvent &__eeInput);
  BOOL H0x01360023_MoveThroughMarkers_11(const CEntityEvent &__eeInput);
  BOOL H0x01360024_MoveThroughMarkers_12(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_NewEnemySpotted 0x01360025
  BOOL 
#line 2308 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
NewEnemySpotted(const CEntityEvent &__eeInput);
  BOOL H0x01360026_NewEnemySpotted_01(const CEntityEvent &__eeInput);
  BOOL H0x01360027_NewEnemySpotted_02(const CEntityEvent &__eeInput);
  BOOL H0x01360028_NewEnemySpotted_03(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_StopAttack 0x01360029
  BOOL 
#line 2340 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
StopAttack(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_InitializeAttack 0x0136002a
  BOOL 
#line 2353 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
InitializeAttack(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_AttackEnemy 0x0136002b
  BOOL 
#line 2379 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
AttackEnemy(const CEntityEvent &__eeInput);
  BOOL H0x0136002c_AttackEnemy_01(const CEntityEvent &__eeInput);
  BOOL H0x0136002d_AttackEnemy_02(const CEntityEvent &__eeInput);
  BOOL H0x0136002e_AttackEnemy_03(const CEntityEvent &__eeInput);
  BOOL H0x0136002f_AttackEnemy_04(const CEntityEvent &__eeInput);
  BOOL H0x01360030_AttackEnemy_05(const CEntityEvent &__eeInput);
  BOOL H0x01360031_AttackEnemy_06(const CEntityEvent &__eeInput);
  BOOL H0x01360032_AttackEnemy_07(const CEntityEvent &__eeInput);
  BOOL H0x01360033_AttackEnemy_08(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_PerformAttack 0x01360034
  BOOL 
#line 2397 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
PerformAttack(const CEntityEvent &__eeInput);
  BOOL H0x01360035_PerformAttack_01(const CEntityEvent &__eeInput);
  BOOL H0x01360036_PerformAttack_02(const CEntityEvent &__eeInput);
  BOOL H0x01360037_PerformAttack_03(const CEntityEvent &__eeInput);
  BOOL H0x01360038_PerformAttack_04(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_FireOrHit 0x01360039
  BOOL 
#line 2585 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
FireOrHit(const CEntityEvent &__eeInput);
  BOOL H0x0136003a_FireOrHit_01(const CEntityEvent &__eeInput);
  BOOL H0x0136003b_FireOrHit_02(const CEntityEvent &__eeInput);
  BOOL H0x0136003c_FireOrHit_03(const CEntityEvent &__eeInput);
  BOOL H0x0136003d_FireOrHit_04(const CEntityEvent &__eeInput);
  BOOL H0x0136003e_FireOrHit_05(const CEntityEvent &__eeInput);
  BOOL H0x0136003f_FireOrHit_06(const CEntityEvent &__eeInput);
  BOOL H0x01360040_FireOrHit_07(const CEntityEvent &__eeInput);
  BOOL H0x01360041_FireOrHit_08(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_Hit 0x01360042
  BOOL 
#line 2628 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
Hit(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_Fire 0x01360043
  BOOL 
#line 2634 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
Fire(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_LockOnEnemy 0x01360044
  BOOL 
#line 2644 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
LockOnEnemy(const CEntityEvent &__eeInput);
  BOOL H0x01360045_LockOnEnemy_01(const CEntityEvent &__eeInput);
  BOOL H0x01360046_LockOnEnemy_02(const CEntityEvent &__eeInput);
  BOOL H0x01360047_LockOnEnemy_03(const CEntityEvent &__eeInput);
  BOOL H0x01360048_LockOnEnemy_04(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_ChargeHitEnemy 0x01360049
  BOOL 
#line 2683 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
ChargeHitEnemy(const CEntityEvent &__eeInput);
  BOOL H0x0136004a_ChargeHitEnemy_01(const CEntityEvent &__eeInput);
  BOOL H0x0136004b_ChargeHitEnemy_02(const CEntityEvent &__eeInput);
  BOOL H0x0136004c_ChargeHitEnemy_03(const CEntityEvent &__eeInput);
  BOOL H0x0136004d_ChargeHitEnemy_04(const CEntityEvent &__eeInput);
  BOOL H0x0136004e_ChargeHitEnemy_05(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_BeWounded 0x0136004f
  BOOL 
#line 2739 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
BeWounded(const CEntityEvent &__eeInput);
  BOOL H0x01360050_BeWounded_01(const CEntityEvent &__eeInput);
  BOOL H0x01360051_BeWounded_02(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_Die 0x01360052
  BOOL 
#line 2748 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
Die(const CEntityEvent &__eeInput);
  BOOL H0x01360053_Die_01(const CEntityEvent &__eeInput);
  BOOL H0x01360054_Die_02(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_Death 0x01360055
  BOOL 
#line 2841 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
Death(const CEntityEvent &__eeInput);
  BOOL H0x01360056_Death_01(const CEntityEvent &__eeInput);
  BOOL H0x01360057_Death_02(const CEntityEvent &__eeInput);
  BOOL H0x01360058_Death_03(const CEntityEvent &__eeInput);
  BOOL H0x01360059_Death_04(const CEntityEvent &__eeInput);
  BOOL H0x0136005a_Death_05(const CEntityEvent &__eeInput);
  BOOL H0x0136005b_Death_06(const CEntityEvent &__eeInput);
  BOOL H0x0136005c_Death_07(const CEntityEvent &__eeInput);
  BOOL H0x0136005d_Death_08(const CEntityEvent &__eeInput);
  BOOL H0x0136005e_Death_09(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_DeathSequence 0x0136005f
  BOOL 
#line 2901 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
DeathSequence(const CEntityEvent &__eeInput);
  BOOL H0x01360060_DeathSequence_01(const CEntityEvent &__eeInput);
  BOOL H0x01360061_DeathSequence_02(const CEntityEvent &__eeInput);
  BOOL H0x01360062_DeathSequence_03(const CEntityEvent &__eeInput);
  BOOL H0x01360063_DeathSequence_04(const CEntityEvent &__eeInput);
  BOOL H0x01360064_DeathSequence_05(const CEntityEvent &__eeInput);
  BOOL H0x01360065_DeathSequence_06(const CEntityEvent &__eeInput);
  BOOL H0x01360066_DeathSequence_07(const CEntityEvent &__eeInput);
  BOOL H0x01360067_DeathSequence_08(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_Active 0x01360068
  BOOL 
#line 2940 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
Active(const CEntityEvent &__eeInput);
  BOOL H0x01360069_Active_01(const CEntityEvent &__eeInput);
  BOOL H0x0136006a_Active_02(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_Inactive 0x0136006b
  BOOL 
#line 3079 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
Inactive(const CEntityEvent &__eeInput);
  BOOL H0x0136006c_Inactive_01(const CEntityEvent &__eeInput);
  BOOL H0x0136006d_Inactive_02(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_PreMainLoop 0x0136006e
  BOOL 
#line 3125 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
PreMainLoop(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_MainLoop 0x0136006f
  BOOL 
#line 3131 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
MainLoop(const CEntityEvent &__eeInput);
  BOOL H0x01360070_MainLoop_01(const CEntityEvent &__eeInput);
  BOOL H0x01360071_MainLoop_02(const CEntityEvent &__eeInput);
  BOOL H0x01360072_MainLoop_03(const CEntityEvent &__eeInput);
  BOOL H0x01360073_MainLoop_04(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_StandardBehavior 0x01360074
  BOOL 
#line 3208 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
StandardBehavior(const CEntityEvent &__eeInput);
  BOOL H0x01360075_StandardBehavior_01(const CEntityEvent &__eeInput);
  BOOL H0x01360076_StandardBehavior_02(const CEntityEvent &__eeInput);
#define  STATE_CEnemyBase_Main 1
  BOOL 
#line 3256 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyBase.es"
Main(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_EnemyBase_INCLUDED
