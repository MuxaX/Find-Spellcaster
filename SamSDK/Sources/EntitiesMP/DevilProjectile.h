/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_DevilProjectile_INCLUDED
#define _EntitiesMP_DevilProjectile_INCLUDED 1
#include <EntitiesMP/BasicEffects.h>
#include <EntitiesMP/Light.h>
#define EVENTCODE_EDevilProjectile 0x01ff0000
class DECL_DLL EDevilProjectile : public CEntityEvent {
public:
EDevilProjectile();
CEntityEvent *MakeCopy(void);
CEntityPointer penLauncher;
CEntityPointer penTarget;
};
DECL_DLL inline void ClearToDefault(EDevilProjectile &e) { e = EDevilProjectile(); } ;
extern "C" DECL_DLL CDLLEntityClass CDevilProjectile_DLLClass;
class CDevilProjectile : public CMovableModelEntity {
public:
  DECL_DLL virtual void SetDefaultProperties(void);
  CEntityPointer m_penLauncher;
  CEntityPointer m_penTarget;
  FLOAT m_fIgnoreTime;
  FLOAT m_fStartTime;
  FLOAT3D m_vDesiredAngle;
  BOOL m_bFly;
  CSoundObject m_soEffect;
CLightSource m_lsLightSource;
   
#line 54 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
void Read_t(CTStream * istr);
   
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
CLightSource * GetLightSource(void);
   
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
void SetupLightSource(void);
   
#line 94 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
void CalcHeadingRotation(ANGLE aWantedHeadingRelative,ANGLE & aRotation);
   
#line 113 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
void CalcAngleFromPosition();
   
#line 128 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
void RotateToAngle();
   
#line 138 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
void FlyInDirection();
   
#line 161 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
void FlyToPosition();
   
#line 167 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
void RotateToPosition();
   
#line 173 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
void StopMoving();
   
#line 179 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
void StopRotating();
   
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
void StopTranslating();
   
#line 193 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
void ProjectileTouch(CEntityPointer penHit);
#define  STATE_CDevilProjectile_Fly 0x01ff0001
  BOOL 
#line 207 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
Fly(const CEntityEvent &__eeInput);
  BOOL H0x01ff0002_Fly_01(const CEntityEvent &__eeInput);
  BOOL H0x01ff0003_Fly_02(const CEntityEvent &__eeInput);
  BOOL H0x01ff0004_Fly_03(const CEntityEvent &__eeInput);
  BOOL H0x01ff0005_Fly_04(const CEntityEvent &__eeInput);
#define  STATE_CDevilProjectile_Main 1
  BOOL 
#line 241 "V:/Programs/SamSDK/Sources/EntitiesMP/DevilProjectile.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x01ff0006_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x01ff0007_Main_02(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_DevilProjectile_INCLUDED
