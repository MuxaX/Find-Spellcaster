/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_Effector_INCLUDED
#define _EntitiesMP_Effector_INCLUDED 1
extern DECL_DLL CEntityPropertyEnumType EffectorEffectType_enum;
enum EffectorEffectType {
  ET_NONE = 0,
  ET_DESTROY_OBELISK = 1,
  ET_DESTROY_PYLON = 2,
  ET_HIT_GROUND = 3,
  ET_LIGHTNING = 4,
  ET_SIZING_BIG_BLUE_FLARE = 5,
  ET_SIZING_RING_FLARE = 6,
  ET_MOVING_RING = 7,
  ET_PORTAL_LIGHTNING = 8,
  ET_MORPH_MODELS = 9,
  ET_DISAPPEAR_MODEL = 10,
  ET_APPEAR_MODEL = 11,
  ET_DISAPPEAR_MODEL_NOW = 12,
  ET_APPEAR_MODEL_NOW = 13,
};
DECL_DLL inline void ClearToDefault(EffectorEffectType &e) { e = (EffectorEffectType)0; } ;
#define EVENTCODE_ESpawnEffector 0x02600000
class DECL_DLL ESpawnEffector : public CEntityEvent {
public:
ESpawnEffector();
CEntityEvent *MakeCopy(void);
enum EffectorEffectType eetType;
FLOAT3D vDamageDir;
FLOAT3D vDestination;
FLOAT tmLifeTime;
FLOAT fSize;
INDEX ctCount;
CEntityPointer penModel;
CEntityPointer penModel2;
};
DECL_DLL inline void ClearToDefault(ESpawnEffector &e) { e = ESpawnEffector(); } ;
extern "C" DECL_DLL CDLLEntityClass CEffector_DLLClass;
class CEffector : public CMovableModelEntity {
public:
  DECL_DLL virtual void SetDefaultProperties(void);
  enum EffectorEffectType m_eetType;
  FLOAT m_tmStarted;
  FLOAT3D m_vDamageDir;
  FLOAT3D m_vFXDestination;
  FLOAT m_tmLifeTime;
  FLOAT m_fSize;
  INDEX m_ctCount;
  BOOL m_bLightSource;
  CAnimObject m_aoLightAnimation;
  INDEX m_iLightAnimation;
  BOOL m_bAlive;
  CEntityPointer m_penModel;
  CEntityPointer m_penModel2;
  BOOL m_bWaitTrigger;
CLightSource m_lsLightSource;
   
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/Effector.es"
FLOAT CalculateLifeRatio(FLOAT fFadeInRatio,FLOAT fFadeOutRatio);
   
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/Effector.es"
void AdjustMipFactor(FLOAT & fMipFactor);
   
#line 182 "V:/Programs/SamSDK/Sources/EntitiesMP/Effector.es"
BOOL AdjustShadingParameters(FLOAT3D & vLightDirection,COLOR & colLight,COLOR & colAmbient);
   
#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/Effector.es"
void RenderMovingLightnings(void);
   
#line 258 "V:/Programs/SamSDK/Sources/EntitiesMP/Effector.es"
void RenderParticles(void);
   
#line 294 "V:/Programs/SamSDK/Sources/EntitiesMP/Effector.es"
void Read_t(CTStream * istr);
   
#line 304 "V:/Programs/SamSDK/Sources/EntitiesMP/Effector.es"
CLightSource * GetLightSource(void);
   
#line 314 "V:/Programs/SamSDK/Sources/EntitiesMP/Effector.es"
void SetupLightSource(void);
#define  STATE_CEffector_Main 1
  BOOL 
#line 369 "V:/Programs/SamSDK/Sources/EntitiesMP/Effector.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x02600001_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x02600002_Main_02(const CEntityEvent &__eeInput);
  BOOL H0x02600003_Main_03(const CEntityEvent &__eeInput);
  BOOL H0x02600004_Main_04(const CEntityEvent &__eeInput);
  BOOL H0x02600005_Main_05(const CEntityEvent &__eeInput);
  BOOL H0x02600006_Main_06(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_Effector_INCLUDED
