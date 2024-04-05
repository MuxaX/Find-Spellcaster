/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CSpawnerProjectile

CEntityProperty CSpawnerProjectile_properties[] = {
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x000001fb<<8)+1, offsetof(CSpawnerProjectile, m_penOwner), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x000001fb<<8)+2, offsetof(CSpawnerProjectile, m_penTemplate), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000001fb<<8)+4, offsetof(CSpawnerProjectile, m_fSize), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000001fb<<8)+5, offsetof(CSpawnerProjectile, m_fTimeAdjust), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x000001fb<<8)+6, offsetof(CSpawnerProjectile, m_bExploding), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000001fb<<8)+7, offsetof(CSpawnerProjectile, m_fExplosionDuration), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000001fb<<8)+8, offsetof(CSpawnerProjectile, m_tmExplosionBegin), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000001fb<<8)+9, offsetof(CSpawnerProjectile, m_tmSpawn), "", 0, 0, 0),
};
#define CSpawnerProjectile_propertiesct ARRAYCOUNT(CSpawnerProjectile_properties)

CEntityComponent CSpawnerProjectile_components[] = {
#define CLASS_BASIC_EFFECT ((0x000001fb<<8)+1)
 CEntityComponent(ECT_CLASS, CLASS_BASIC_EFFECT, "EFNM" "Classes\\BasicEffect.ecl"),
#define MODEL_INVISIBLE ((0x000001fb<<8)+10)
 CEntityComponent(ECT_MODEL, MODEL_INVISIBLE, "EFNM" "ModelsMP\\Enemies\\Summoner\\SpawnerProjectile\\Invisible.mdl"),
};
#define CSpawnerProjectile_componentsct ARRAYCOUNT(CSpawnerProjectile_components)

CEventHandlerEntry CSpawnerProjectile_handlers[] = {
 {1, -1, CEntity::pEventHandler(&CSpawnerProjectile::
#line 136 "V:/Programs/SamSDK/Sources/EntitiesMP/SpawnerProjectile.es"
Main),DEBUGSTRING("CSpawnerProjectile::Main")},
 {0x01fb0001, -1, CEntity::pEventHandler(&CSpawnerProjectile::H0x01fb0001_Main_01), DEBUGSTRING("CSpawnerProjectile::H0x01fb0001_Main_01")},
 {0x01fb0002, -1, CEntity::pEventHandler(&CSpawnerProjectile::H0x01fb0002_Main_02), DEBUGSTRING("CSpawnerProjectile::H0x01fb0002_Main_02")},
 {0x01fb0003, -1, CEntity::pEventHandler(&CSpawnerProjectile::H0x01fb0003_Main_03), DEBUGSTRING("CSpawnerProjectile::H0x01fb0003_Main_03")},
 {0x01fb0004, -1, CEntity::pEventHandler(&CSpawnerProjectile::H0x01fb0004_Main_04), DEBUGSTRING("CSpawnerProjectile::H0x01fb0004_Main_04")},
};
#define CSpawnerProjectile_handlersct ARRAYCOUNT(CSpawnerProjectile_handlers)

CEntity *CSpawnerProjectile_New(void) { return new CSpawnerProjectile; };
void CSpawnerProjectile_OnInitClass(void) {};
void CSpawnerProjectile_OnEndClass(void) {};
void CSpawnerProjectile_OnPrecache(CDLLEntityClass *pdec, INDEX iUser);
void CSpawnerProjectile_OnWorldEnd(CWorld *pwo) {};
void CSpawnerProjectile_OnWorldInit(CWorld *pwo) {};
void CSpawnerProjectile_OnWorldTick(CWorld *pwo) {};
void CSpawnerProjectile_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CSpawnerProjectile, CMovableModelEntity, "SpawnerProjectile", "", 0x000001fb);
DECLARE_CTFILENAME(_fnmCSpawnerProjectile_tbn, "");
