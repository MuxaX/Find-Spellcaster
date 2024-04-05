/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CGuffy

CEntityProperty CGuffy_properties[] = {
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x00000158<<8)+2, offsetof(CGuffy, m_iLoopCounter), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000158<<8)+3, offsetof(CGuffy, m_fSize), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x00000158<<8)+4, offsetof(CGuffy, m_bWalkSoundPlaying), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000158<<8)+5, offsetof(CGuffy, m_fThreatDistance), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x00000158<<8)+6, offsetof(CGuffy, m_bEnemyToTheLeft), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_SOUNDOBJECT, NULL, (0x00000158<<8)+10, offsetof(CGuffy, m_soFire1), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_SOUNDOBJECT, NULL, (0x00000158<<8)+11, offsetof(CGuffy, m_soFire2), "", 0, 0, 0),
};
#define CGuffy_propertiesct ARRAYCOUNT(CGuffy_properties)

CEntityComponent CGuffy_components[] = {
#define CLASS_BASE ((0x00000158<<8)+0)
 CEntityComponent(ECT_CLASS, CLASS_BASE, "EFNM" "Classes\\EnemyBase.ecl"),
#define CLASS_PROJECTILE ((0x00000158<<8)+1)
 CEntityComponent(ECT_CLASS, CLASS_PROJECTILE, "EFNM" "Classes\\Projectile.ecl"),
#define MODEL_GUFFY ((0x00000158<<8)+10)
 CEntityComponent(ECT_MODEL, MODEL_GUFFY, "EFNM" "ModelsMP\\Enemies\\Guffy\\Guffy.mdl"),
#define TEXTURE_GUFFY ((0x00000158<<8)+11)
 CEntityComponent(ECT_TEXTURE, TEXTURE_GUFFY, "EFNM" "ModelsMP\\Enemies\\Guffy\\Guffy.tex"),
#define MODEL_GUN ((0x00000158<<8)+12)
 CEntityComponent(ECT_MODEL, MODEL_GUN, "EFNM" "ModelsMP\\Enemies\\Guffy\\Gun.mdl"),
#define TEXTURE_GUN ((0x00000158<<8)+13)
 CEntityComponent(ECT_TEXTURE, TEXTURE_GUN, "EFNM" "ModelsMP\\Enemies\\Guffy\\Gun.tex"),
#define SOUND_IDLE ((0x00000158<<8)+40)
 CEntityComponent(ECT_SOUND, SOUND_IDLE, "EFNM" "ModelsMP\\Enemies\\Guffy\\Sounds\\Idle.wav"),
#define SOUND_SIGHT ((0x00000158<<8)+41)
 CEntityComponent(ECT_SOUND, SOUND_SIGHT, "EFNM" "ModelsMP\\Enemies\\Guffy\\Sounds\\Sight.wav"),
#define SOUND_FIRE ((0x00000158<<8)+43)
 CEntityComponent(ECT_SOUND, SOUND_FIRE, "EFNM" "ModelsMP\\Enemies\\Guffy\\Sounds\\Fire.wav"),
#define SOUND_WOUND ((0x00000158<<8)+44)
 CEntityComponent(ECT_SOUND, SOUND_WOUND, "EFNM" "ModelsMP\\Enemies\\Guffy\\Sounds\\Wound.wav"),
#define SOUND_DEATH ((0x00000158<<8)+45)
 CEntityComponent(ECT_SOUND, SOUND_DEATH, "EFNM" "ModelsMP\\Enemies\\Guffy\\Sounds\\Death.wav"),
};
#define CGuffy_componentsct ARRAYCOUNT(CGuffy_components)

CEventHandlerEntry CGuffy_handlers[] = {
 {0x01580000, STATE_CEnemyBase_Fire, CEntity::pEventHandler(&CGuffy::
#line 230 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
Fire),DEBUGSTRING("CGuffy::Fire")},
 {0x01580001, -1, CEntity::pEventHandler(&CGuffy::H0x01580001_Fire_01), DEBUGSTRING("CGuffy::H0x01580001_Fire_01")},
 {0x01580002, -1, CEntity::pEventHandler(&CGuffy::H0x01580002_Fire_02), DEBUGSTRING("CGuffy::H0x01580002_Fire_02")},
 {0x01580003, -1, CEntity::pEventHandler(&CGuffy::H0x01580003_Fire_03), DEBUGSTRING("CGuffy::H0x01580003_Fire_03")},
 {0x01580004, -1, CEntity::pEventHandler(&CGuffy::H0x01580004_Fire_04), DEBUGSTRING("CGuffy::H0x01580004_Fire_04")},
 {0x01580005, -1, CEntity::pEventHandler(&CGuffy::H0x01580005_Fire_05), DEBUGSTRING("CGuffy::H0x01580005_Fire_05")},
 {0x01580006, -1, CEntity::pEventHandler(&CGuffy::H0x01580006_Fire_06), DEBUGSTRING("CGuffy::H0x01580006_Fire_06")},
 {1, -1, CEntity::pEventHandler(&CGuffy::
#line 296 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
Main),DEBUGSTRING("CGuffy::Main")},
};
#define CGuffy_handlersct ARRAYCOUNT(CGuffy_handlers)

CEntity *CGuffy_New(void) { return new CGuffy; };
void CGuffy_OnInitClass(void) {};
void CGuffy_OnEndClass(void) {};
void CGuffy_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CGuffy_OnWorldEnd(CWorld *pwo) {};
void CGuffy_OnWorldInit(CWorld *pwo) {};
void CGuffy_OnWorldTick(CWorld *pwo) {};
void CGuffy_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CGuffy, CEnemyBase, "Guffy", "Thumbnails\\Guffy.tbn", 0x00000158);
DECLARE_CTFILENAME(_fnmCGuffy_tbn, "Thumbnails\\Guffy.tbn");
