/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CEnemyCounter

CEntityProperty CEnemyCounter_properties[] = {
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x00000153<<8)+1, offsetof(CEnemyCounter, m_penMainMusicHolder), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_STRING, NULL, (0x00000153<<8)+2, offsetof(CEnemyCounter, m_strName), "Name", 'N', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x00000153<<8)+4, offsetof(CEnemyCounter, m_iCountFrom), "Count start", 'A', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x00000153<<8)+5, offsetof(CEnemyCounter, m_iCount), "", 0, 0, 0),
};
#define CEnemyCounter_propertiesct ARRAYCOUNT(CEnemyCounter_properties)

CEntityComponent CEnemyCounter_components[] = {
#define SOUND_TICK ((0x00000153<<8)+0)
 CEntityComponent(ECT_SOUND, SOUND_TICK, "EFNM" "Sounds\\Menu\\Select.wav"),
#define MODEL_MARKER ((0x00000153<<8)+1)
 CEntityComponent(ECT_MODEL, MODEL_MARKER, "EFNM" "Models\\Editor\\Axis.mdl"),
#define TEXTURE_MARKER ((0x00000153<<8)+2)
 CEntityComponent(ECT_TEXTURE, TEXTURE_MARKER, "EFNM" "Models\\Editor\\Vector.tex"),
};
#define CEnemyCounter_componentsct ARRAYCOUNT(CEnemyCounter_components)

CEventHandlerEntry CEnemyCounter_handlers[] = {
 {1, -1, CEntity::pEventHandler(&CEnemyCounter::
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
Main),DEBUGSTRING("CEnemyCounter::Main")},
 {0x01530000, -1, CEntity::pEventHandler(&CEnemyCounter::H0x01530000_Main_01), DEBUGSTRING("CEnemyCounter::H0x01530000_Main_01")},
 {0x01530001, -1, CEntity::pEventHandler(&CEnemyCounter::H0x01530001_Main_02), DEBUGSTRING("CEnemyCounter::H0x01530001_Main_02")},
 {0x01530002, -1, CEntity::pEventHandler(&CEnemyCounter::H0x01530002_Main_03), DEBUGSTRING("CEnemyCounter::H0x01530002_Main_03")},
 {0x01530003, -1, CEntity::pEventHandler(&CEnemyCounter::H0x01530003_Main_04), DEBUGSTRING("CEnemyCounter::H0x01530003_Main_04")},
};
#define CEnemyCounter_handlersct ARRAYCOUNT(CEnemyCounter_handlers)

CEntity *CEnemyCounter_New(void) { return new CEnemyCounter; };
void CEnemyCounter_OnInitClass(void) {};
void CEnemyCounter_OnEndClass(void) {};
void CEnemyCounter_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CEnemyCounter_OnWorldEnd(CWorld *pwo) {};
void CEnemyCounter_OnWorldInit(CWorld *pwo) {};
void CEnemyCounter_OnWorldTick(CWorld *pwo) {};
void CEnemyCounter_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CEnemyCounter, CRationalEntity, "EnemyCounter", "Thumbnails\\Counter.tbn", 0x00000153);
DECLARE_CTFILENAME(_fnmCEnemyCounter_tbn, "Thumbnails\\Counter.tbn");
