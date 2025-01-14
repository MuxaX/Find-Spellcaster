/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_ExotechLarvaCharger_INCLUDED
#define _EntitiesMP_ExotechLarvaCharger_INCLUDED 1
#include <EntitiesMP/BloodSpray.h>
#include <EntitiesMP/Projectile.h>
#include <EntitiesMP/ExotechLarvaBattery.h>
#define EVENTCODE_EActivateBeam 0x015f0000
class DECL_DLL EActivateBeam : public CEntityEvent {
public:
EActivateBeam();
CEntityEvent *MakeCopy(void);
BOOL bTurnOn;
};
DECL_DLL inline void ClearToDefault(EActivateBeam &e) { e = EActivateBeam(); } ;
extern "C" DECL_DLL CDLLEntityClass CExotechLarvaCharger_DLLClass;
class CExotechLarvaCharger : public CRationalEntity {
public:
virtual const CTString &GetName(void) const { return m_strName; };
virtual BOOL IsTargetable(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
  BOOL m_bActive;
  BOOL m_bBeamActive;
  FLOAT m_fStretch;
  CTString m_strName;
  RANGE m_rSound;
  CEntityPointer m_penBattery01;
  CEntityPointer m_penBattery02;
  CEntityPointer m_penBattery03;
  CEntityPointer m_penBattery04;
  CEntityPointer m_penBattery05;
  CEntityPointer m_penBattery06;
  BOOL m_bCustomShading;
  ANGLE3D m_aShadingDirection;
  COLOR m_colLight;
  COLOR m_colAmbient;
  CSoundObject m_soSound;
   
#line 61 "V:/Programs/SamSDK/Sources/EntitiesMP/ExotechLarvaCharger.es"
BOOL IsTargetValid(SLONG slPropertyOffset,CEntity * penTarget);
   
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/ExotechLarvaCharger.es"
void Precache(void);
   
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/ExotechLarvaCharger.es"
BOOL AdjustShadingParameters(FLOAT3D & vLightDirection,COLOR & colLight,COLOR & colAmbient);
   
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/ExotechLarvaCharger.es"
void UpdateOperationalState(void);
   
#line 131 "V:/Programs/SamSDK/Sources/EntitiesMP/ExotechLarvaCharger.es"
void ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 132 "V:/Programs/SamSDK/Sources/EntitiesMP/ExotechLarvaCharger.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection);
   
#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/ExotechLarvaCharger.es"
void RenderParticles(void);
#define  STATE_CExotechLarvaCharger_ActivateBeam 0x015f0001
  BOOL 
#line 163 "V:/Programs/SamSDK/Sources/EntitiesMP/ExotechLarvaCharger.es"
ActivateBeam(const CEntityEvent &__eeInput);
#define  STATE_CExotechLarvaCharger_DeactivateBeam 0x015f0002
  BOOL 
#line 172 "V:/Programs/SamSDK/Sources/EntitiesMP/ExotechLarvaCharger.es"
DeactivateBeam(const CEntityEvent &__eeInput);
#define  STATE_CExotechLarvaCharger_Main 1
  BOOL 
#line 179 "V:/Programs/SamSDK/Sources/EntitiesMP/ExotechLarvaCharger.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x015f0003_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x015f0004_Main_02(const CEntityEvent &__eeInput);
  BOOL H0x015f0005_Main_03(const CEntityEvent &__eeInput);
  BOOL H0x015f0006_Main_04(const CEntityEvent &__eeInput);
  BOOL H0x015f0007_Main_05(const CEntityEvent &__eeInput);
  BOOL H0x015f0008_Main_06(const CEntityEvent &__eeInput);
  BOOL H0x015f0009_Main_07(const CEntityEvent &__eeInput);
  BOOL H0x015f000a_Main_08(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_ExotechLarvaCharger_INCLUDED
