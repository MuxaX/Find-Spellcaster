/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CBloodSpray

CEntityProperty CBloodSpray_properties[] = {
 CEntityProperty(CEntityProperty::EPT_ENUM, &SprayParticlesType_enum, (0x0000025b<<8)+1, offsetof(CBloodSpray, m_sptType), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000025b<<8)+2, offsetof(CBloodSpray, m_tmStarted), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT3D, NULL, (0x0000025b<<8)+3, offsetof(CBloodSpray, m_vDirection), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025b<<8)+5, offsetof(CBloodSpray, m_penOwner), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000025b<<8)+6, offsetof(CBloodSpray, m_fDamagePower), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOATAABBOX3D, NULL, (0x0000025b<<8)+8, offsetof(CBloodSpray, m_boxSizedOwner), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT3D, NULL, (0x0000025b<<8)+9, offsetof(CBloodSpray, m_vGDir), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000025b<<8)+10, offsetof(CBloodSpray, m_fGA), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000025b<<8)+11, offsetof(CBloodSpray, m_fLaunchPower), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x0000025b<<8)+12, offsetof(CBloodSpray, m_colCentralColor), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOATAABBOX3D, NULL, (0x0000025b<<8)+13, offsetof(CBloodSpray, m_boxOriginalOwner), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x0000025b<<8)+14, offsetof(CBloodSpray, m_colBurnColor), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025b<<8)+255, offsetof(CBloodSpray, m_penPrediction), "", 0, 0, 0),
};
#define CBloodSpray_propertiesct ARRAYCOUNT(CBloodSpray_properties)

CEntityComponent CBloodSpray_components[] = {
#define MODEL_MARKER ((0x0000025b<<8)+1)
 CEntityComponent(ECT_MODEL, MODEL_MARKER, "EFNM" "Models\\Editor\\Axis.mdl"),
#define TEXTURE_MARKER ((0x0000025b<<8)+2)
 CEntityComponent(ECT_TEXTURE, TEXTURE_MARKER, "EFNM" "Models\\Editor\\Vector.tex"),
};
#define CBloodSpray_componentsct ARRAYCOUNT(CBloodSpray_components)

CEventHandlerEntry CBloodSpray_handlers[] = {
 {1, -1, CEntity::pEventHandler(&CBloodSpray::
#line 109 "V:/Programs/SamSDK/Sources/EntitiesMP/BloodSpray.es"
Main),DEBUGSTRING("CBloodSpray::Main")},
 {0x025b0001, -1, CEntity::pEventHandler(&CBloodSpray::H0x025b0001_Main_01), DEBUGSTRING("CBloodSpray::H0x025b0001_Main_01")},
 {0x025b0002, -1, CEntity::pEventHandler(&CBloodSpray::H0x025b0002_Main_02), DEBUGSTRING("CBloodSpray::H0x025b0002_Main_02")},
};
#define CBloodSpray_handlersct ARRAYCOUNT(CBloodSpray_handlers)

CEntity *CBloodSpray_New(void) { return new CBloodSpray; };
void CBloodSpray_OnInitClass(void) {};
void CBloodSpray_OnEndClass(void) {};
void CBloodSpray_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CBloodSpray_OnWorldEnd(CWorld *pwo) {};
void CBloodSpray_OnWorldInit(CWorld *pwo) {};
void CBloodSpray_OnWorldTick(CWorld *pwo) {};
void CBloodSpray_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CBloodSpray, CRationalEntity, "Blood Spray", "", 0x0000025b);
DECLARE_CTFILENAME(_fnmCBloodSpray_tbn, "");
