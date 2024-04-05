/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_ModelHolder3_INCLUDED
#define _EntitiesMP_ModelHolder3_INCLUDED 1
#include <EntitiesMP/ModelDestruction.h>
#include <EntitiesMP/AnimationChanger.h>
#include <EntitiesMP/BloodSpray.h>
extern DECL_DLL CEntityPropertyEnumType SkaCustomShadingType_enum;
enum SkaCustomShadingType {
  SCST_NONE = 0,
  SCST_CONSTANT_SHADING = 1,
  SCST_FULL_CUSTOMIZED = 2,
};
DECL_DLL inline void ClearToDefault(SkaCustomShadingType &e) { e = (SkaCustomShadingType)0; } ;
extern DECL_DLL CEntityPropertyEnumType SkaShadowType_enum;
enum SkaShadowType {
  SST_NONE = 0,
  SST_CLUSTER = 1,
  SST_POLYGONAL = 2,
};
DECL_DLL inline void ClearToDefault(SkaShadowType &e) { e = (SkaShadowType)0; } ;
extern "C" DECL_DLL CDLLEntityClass CModelHolder3_DLLClass;
class CModelHolder3 : public CRationalEntity {
public:
virtual const CTString &GetName(void) const { return m_strName; };
virtual const CTString &GetDescription(void) const { return m_strDescription; };
  DECL_DLL virtual void SetDefaultProperties(void);
  CTFileName m_fnModel;
  FLOAT m_fStretchAll;
  ANGLE3D m_vStretchXYZ;
  CTString m_strName;
  CTString m_strDescription;
  BOOL m_bColliding;
  enum SkaShadowType m_stClusterShadows;
  BOOL m_bBackground;
  BOOL m_bTargetable;
  enum SkaCustomShadingType m_cstCustomShading;
  ANGLE3D m_aShadingDirection;
  COLOR m_colLight;
  COLOR m_colAmbient;
  BOOL m_bActive;
  FLOAT m_fClassificationStretch;
  FLOAT m_fMaxTessellationLevel;
   
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
BOOL FillEntityStatistics(EntityStats * pes);
   
#line 138 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
FLOAT3D GetClassificationBoxStretch(void);
   
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
FLOAT GetMaxTessellationLevel(void);
   
#line 152 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
void ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 153 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection);
   
#line 300 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
void * GetEntityInfo(void);
   
#line 315 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
BOOL IsTargetable(void)const;
   
#line 372 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
BOOL AdjustShadingParameters(FLOAT3D & vLightDirection,COLOR & colLight,COLOR & colAmbient);
   
#line 452 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
void MirrorAndStretch(FLOAT fStretch,BOOL bMirrorX);
   
#line 462 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
void StretchModel(void);
   
#line 498 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
void InitModelHolder(void);
#define  STATE_CModelHolder3_Die 0x00f20000
  BOOL 
#line 603 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
Die(const CEntityEvent &__eeInput);
#define  STATE_CModelHolder3_Main 1
  BOOL 
#line 660 "V:/Programs/SamSDK/Sources/EntitiesMP/ModelHolder3.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x00f20001_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x00f20002_Main_02(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_ModelHolder3_INCLUDED
