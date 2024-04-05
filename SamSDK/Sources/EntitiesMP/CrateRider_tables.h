/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CCrateRider

CEntityProperty CCrateRider_properties[] = {
 CEntityProperty(CEntityProperty::EPT_FILENAME, NULL, (0x00000155<<8)+1, offsetof(CCrateRider, m_fnmHeadTex1), "Head texture1", 'H', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FILENAME, NULL, (0x00000155<<8)+2, offsetof(CCrateRider, m_fnmHeadTex2), "Head texture2", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FILENAME, NULL, (0x00000155<<8)+3, offsetof(CCrateRider, m_fnmDriveSnd), "Drive sound", 'S', 0x7F0000FFUL, 0),
};
#define CCrateRider_propertiesct ARRAYCOUNT(CCrateRider_properties)

CEntityComponent CCrateRider_components[] = {
#define CLASS_BASE ((0x00000155<<8)+1)
 CEntityComponent(ECT_CLASS, CLASS_BASE, "EFNM" "Classes\\EnemyBase.ecl"),
#define CLASS_DEBRIS ((0x00000155<<8)+2)
 CEntityComponent(ECT_CLASS, CLASS_DEBRIS, "EFNM" "Classes\\Debris.ecl"),
#define CLASS_BLOOD_SPRAY ((0x00000155<<8)+3)
 CEntityComponent(ECT_CLASS, CLASS_BLOOD_SPRAY, "EFNM" "Classes\\BloodSpray.ecl"),
#define CLASS_BASIC_EFFECT ((0x00000155<<8)+4)
 CEntityComponent(ECT_CLASS, CLASS_BASIC_EFFECT, "EFNM" "Classes\\BasicEffect.ecl"),
#define MODEL_MENTAL ((0x00000155<<8)+10)
 CEntityComponent(ECT_MODEL, MODEL_MENTAL, "EFNM" "Models\\Enemies\\Mental\\Mental.mdl"),
#define TEXTURE_MENTAL ((0x00000155<<8)+11)
 CEntityComponent(ECT_TEXTURE, TEXTURE_MENTAL, "EFNM" "Models\\Enemies\\Mental\\Mental.tex"),
#define MODEL_HEAD ((0x00000155<<8)+12)
 CEntityComponent(ECT_MODEL, MODEL_HEAD, "EFNM" "Models\\Enemies\\Mental\\Head.mdl"),
#define MODEL_CRATE ((0x00000155<<8)+13)
 CEntityComponent(ECT_MODEL, MODEL_CRATE, "EFNM" "Models\\CutSequences\\CrateRider\\Crate.mdl"),
#define TEXTURE_CRATE ((0x00000155<<8)+14)
 CEntityComponent(ECT_TEXTURE, TEXTURE_CRATE, "EFNM" "Models\\CutSequences\\CrateRider\\Crate.tex"),
#define TEXTURE_BUMP ((0x00000155<<8)+15)
 CEntityComponent(ECT_TEXTURE, TEXTURE_BUMP, "EFNM" "Models\\CutSequences\\Bridge\\BridgeBump.tex"),
};
#define CCrateRider_componentsct ARRAYCOUNT(CCrateRider_components)

CEventHandlerEntry CCrateRider_handlers[] = {
 {1, -1, CEntity::pEventHandler(&CCrateRider::
#line 164 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
Main),DEBUGSTRING("CCrateRider::Main")},
};
#define CCrateRider_handlersct ARRAYCOUNT(CCrateRider_handlers)

CEntity *CCrateRider_New(void) { return new CCrateRider; };
void CCrateRider_OnInitClass(void) {};
void CCrateRider_OnEndClass(void) {};
void CCrateRider_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CCrateRider_OnWorldEnd(CWorld *pwo) {};
void CCrateRider_OnWorldInit(CWorld *pwo) {};
void CCrateRider_OnWorldTick(CWorld *pwo) {};
void CCrateRider_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CCrateRider, CEnemyBase, "CrateRider", "Thumbnails\\Mental.tbn", 0x00000155);
DECLARE_CTFILENAME(_fnmCCrateRider_tbn, "Thumbnails\\Mental.tbn");
