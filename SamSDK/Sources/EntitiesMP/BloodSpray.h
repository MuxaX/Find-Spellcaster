/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_BloodSpray_INCLUDED
#define _EntitiesMP_BloodSpray_INCLUDED 1
#define EVENTCODE_ESpawnSpray 0x025b0000
class DECL_DLL ESpawnSpray : public CEntityEvent {
public:
ESpawnSpray();
CEntityEvent *MakeCopy(void);
enum SprayParticlesType sptType;
FLOAT fDamagePower;
FLOAT fSizeMultiplier;
FLOAT3D vDirection;
CEntityPointer penOwner;
COLOR colCentralColor;
FLOAT fLaunchPower;
COLOR colBurnColor;
};
DECL_DLL inline void ClearToDefault(ESpawnSpray &e) { e = ESpawnSpray(); } ;
extern "C" DECL_DLL CDLLEntityClass CBloodSpray_DLLClass;
class CBloodSpray : public CRationalEntity {
public:
virtual CEntity *GetPredictionPair(void) { return m_penPrediction; };
virtual void SetPredictionPair(CEntity *penPair) { m_penPrediction = penPair; };
  DECL_DLL virtual void SetDefaultProperties(void);
  enum SprayParticlesType m_sptType;
  FLOAT m_tmStarted;
  FLOAT3D m_vDirection;
  CEntityPointer m_penOwner;
  FLOAT m_fDamagePower;
  FLOATaabbox3D m_boxSizedOwner;
  FLOAT3D m_vGDir;
  FLOAT m_fGA;
  FLOAT m_fLaunchPower;
  COLOR m_colCentralColor;
  FLOATaabbox3D m_boxOriginalOwner;
  COLOR m_colBurnColor;
  CEntityPointer m_penPrediction;
   
#line 46 "V:/Programs/SamSDK/Sources/EntitiesMP/BloodSpray.es"
void RenderParticles(void);
#define  STATE_CBloodSpray_Main 1
  BOOL 
#line 109 "V:/Programs/SamSDK/Sources/EntitiesMP/BloodSpray.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x025b0001_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x025b0002_Main_02(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_BloodSpray_INCLUDED
