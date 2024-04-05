/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_CannonStatic_INCLUDED
#define _EntitiesMP_CannonStatic_INCLUDED 1
#include <EntitiesMP/ModelHolder2.h>
#include <EntitiesMP/Projectile.h>
#include <EntitiesMP/SoundHolder.h>
#include <EntitiesMP/BloodSpray.h>
#include <EntitiesMP/CannonBall.h>
extern "C" DECL_DLL CDLLEntityClass CCannonStatic_DLLClass;
class CCannonStatic : public CEnemyBase {
public:
  DECL_DLL virtual void SetDefaultProperties(void);
  FLOAT m_fHealth;
  RANGE m_fFiringRangeClose;
  RANGE m_fFiringRangeFar;
  FLOAT m_fShootingPeriod;
  FLOAT m_fSize;
  FLOAT m_fMaxPitch;
  FLOAT m_fViewAngle;
  BOOL m_bActive;
  FLOAT3D m_fRotSpeedMuzzle;
  FLOAT m_fDistanceToPlayer;
  FLOAT m_fDesiredMuzzlePitch;
  INDEX m_iMuzzleDir;
  FLOAT3D m_vFiringPos;
  FLOAT3D m_vTarget;
  FLOAT3D m_aBeginMuzzleRotation;
  FLOAT3D m_aEndMuzzleRotation;
  
#line 79 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
virtual CTString GetPlayerKillDescription(const CTString & strPlayerName,const EDeath & eDeath);
   
#line 87 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
void * GetEntityInfo(void);
  
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
virtual const CTFileName & GetComputerMessageName(void)const;
   
#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
void Precache(void);
   
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
void ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 112 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection);
   
#line 125 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
INDEX AnimForDamage(FLOAT fDamage);
   
#line 130 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
INDEX AnimForDeath(void);
   
#line 135 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
BOOL IsVisible(CEntity * penEntity);
   
#line 152 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
BOOL IsInTheLineOfFire(CEntity * penEntity,FLOAT fAngle);
   
#line 177 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
CPlayer * AcquireTarget();
   
#line 198 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
void CannonBlowUp(void);
   
#line 248 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
void PreMoving();
   
#line 254 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
void PostMoving();
   
#line 260 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
BOOL AdjustShadingParameters(FLOAT3D & vLightDirection,COLOR & colLight,COLOR & colAmbient);
   
#line 267 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
void UpdateAttachmentRotations(void);
   
#line 274 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
void UpdateFiringPos();
#define  STATE_CCannonStatic_MainLoop 0x01590000
  BOOL 
#line 290 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
MainLoop(const CEntityEvent &__eeInput);
  BOOL H0x01590001_MainLoop_01(const CEntityEvent &__eeInput);
  BOOL H0x01590002_MainLoop_02(const CEntityEvent &__eeInput);
#define  STATE_CCannonStatic_Die 0x01590003
  BOOL 
#line 307 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
Die(const CEntityEvent &__eeInput);
#define  STATE_CCannonStatic_RotateMuzzle 0x01590004
  BOOL 
#line 354 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
RotateMuzzle(const CEntityEvent &__eeInput);
  BOOL H0x01590005_RotateMuzzle_01(const CEntityEvent &__eeInput);
  BOOL H0x01590006_RotateMuzzle_02(const CEntityEvent &__eeInput);
#define  STATE_CCannonStatic_FireCannon 0x01590007
  BOOL 
#line 369 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
FireCannon(const CEntityEvent &__eeInput);
  BOOL H0x01590008_FireCannon_01(const CEntityEvent &__eeInput);
  BOOL H0x01590009_FireCannon_02(const CEntityEvent &__eeInput);
#define  STATE_CCannonStatic_WatchPlayers 0x0159000a
  BOOL 
#line 432 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
WatchPlayers(const CEntityEvent &__eeInput);
  BOOL H0x0159000b_WatchPlayers_01(const CEntityEvent &__eeInput);
  BOOL H0x0159000c_WatchPlayers_02(const CEntityEvent &__eeInput);
  BOOL H0x0159000d_WatchPlayers_03(const CEntityEvent &__eeInput);
  BOOL H0x0159000e_WatchPlayers_04(const CEntityEvent &__eeInput);
  BOOL H0x0159000f_WatchPlayers_05(const CEntityEvent &__eeInput);
  BOOL H0x01590010_WatchPlayers_06(const CEntityEvent &__eeInput);
  BOOL H0x01590011_WatchPlayers_07(const CEntityEvent &__eeInput);
  BOOL H0x01590012_WatchPlayers_08(const CEntityEvent &__eeInput);
  BOOL H0x01590013_WatchPlayers_09(const CEntityEvent &__eeInput);
  BOOL H0x01590014_WatchPlayers_10(const CEntityEvent &__eeInput);
#define  STATE_CCannonStatic_Inactive 0x01590015
  BOOL 
#line 450 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
Inactive(const CEntityEvent &__eeInput);
  BOOL H0x01590016_Inactive_01(const CEntityEvent &__eeInput);
  BOOL H0x01590017_Inactive_02(const CEntityEvent &__eeInput);
#define  STATE_CCannonStatic_Main 1
  BOOL 
#line 465 "V:/Programs/SamSDK/Sources/EntitiesMP/CannonStatic.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x01590018_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x01590019_Main_02(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_CannonStatic_INCLUDED