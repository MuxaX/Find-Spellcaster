/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CChainsawFreak

CEntityProperty CChainsawFreak_properties[] = {
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x00000156<<8)+1, offsetof(CChainsawFreak, m_bRunAttack), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x00000156<<8)+2, offsetof(CChainsawFreak, m_bSawHit), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x00000156<<8)+3, offsetof(CChainsawFreak, m_penLastTouched), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_SOUNDOBJECT, NULL, (0x00000156<<8)+4, offsetof(CChainsawFreak, m_soFeet), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x00000156<<8)+5, offsetof(CChainsawFreak, m_bRunSoundPlaying), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x00000156<<8)+6, offsetof(CChainsawFreak, m_iRunType), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x00000156<<8)+10, offsetof(CChainsawFreak, m_bAttacking), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000156<<8)+11, offsetof(CChainsawFreak, m_fSightSoundBegin), "", 0, 0, 0),
};
#define CChainsawFreak_propertiesct ARRAYCOUNT(CChainsawFreak_properties)

CEntityComponent CChainsawFreak_components[] = {
#define CLASS_BASE ((0x00000156<<8)+0)
 CEntityComponent(ECT_CLASS, CLASS_BASE, "EFNM" "Classes\\EnemyRunInto.ecl"),
#define MODEL_FREAK ((0x00000156<<8)+1)
 CEntityComponent(ECT_MODEL, MODEL_FREAK, "EFNM" "ModelsMP\\Enemies\\ChainsawFreak\\Freak.mdl"),
#define MODEL_CHAINSAW ((0x00000156<<8)+2)
 CEntityComponent(ECT_MODEL, MODEL_CHAINSAW, "EFNM" "ModelsMP\\Enemies\\ChainsawFreak\\Saw.mdl"),
#define TEXTURE_FREAK ((0x00000156<<8)+3)
 CEntityComponent(ECT_TEXTURE, TEXTURE_FREAK, "EFNM" "ModelsMP\\Enemies\\ChainsawFreak\\Freak.tex"),
#define TEXTURE_CHAINSAW ((0x00000156<<8)+4)
 CEntityComponent(ECT_TEXTURE, TEXTURE_CHAINSAW, "EFNM" "ModelsMP\\Enemies\\ChainsawFreak\\Saw.tex"),
#define SOUND_IDLE ((0x00000156<<8)+50)
 CEntityComponent(ECT_SOUND, SOUND_IDLE, "EFNM" "ModelsMP\\Enemies\\ChainsawFreak\\Sounds\\Idle.wav"),
#define SOUND_RUN ((0x00000156<<8)+51)
 CEntityComponent(ECT_SOUND, SOUND_RUN, "EFNM" "ModelsMP\\Enemies\\ChainsawFreak\\Sounds\\Run.wav"),
#define SOUND_ATTACK ((0x00000156<<8)+54)
 CEntityComponent(ECT_SOUND, SOUND_ATTACK, "EFNM" "ModelsMP\\Enemies\\ChainsawFreak\\Sounds\\Attack.wav"),
#define SOUND_WOUND ((0x00000156<<8)+55)
 CEntityComponent(ECT_SOUND, SOUND_WOUND, "EFNM" "ModelsMP\\Enemies\\ChainsawFreak\\Sounds\\Wound.wav"),
#define SOUND_DEATH ((0x00000156<<8)+56)
 CEntityComponent(ECT_SOUND, SOUND_DEATH, "EFNM" "ModelsMP\\Enemies\\ChainsawFreak\\Sounds\\Death.wav"),
#define SOUND_SIGHT ((0x00000156<<8)+57)
 CEntityComponent(ECT_SOUND, SOUND_SIGHT, "EFNM" "ModelsMP\\Enemies\\ChainsawFreak\\Sounds\\Sight.wav"),
};
#define CChainsawFreak_componentsct ARRAYCOUNT(CChainsawFreak_components)

CEventHandlerEntry CChainsawFreak_handlers[] = {
 {0x01560000, STATE_CEnemyBase_Hit, CEntity::pEventHandler(&CChainsawFreak::
#line 280 "V:/Programs/SamSDK/Sources/EntitiesMP/ChainsawFreak.es"
Hit),DEBUGSTRING("CChainsawFreak::Hit")},
 {0x01560001, -1, CEntity::pEventHandler(&CChainsawFreak::H0x01560001_Hit_01), DEBUGSTRING("CChainsawFreak::H0x01560001_Hit_01")},
 {0x01560002, -1, CEntity::pEventHandler(&CChainsawFreak::H0x01560002_Hit_02), DEBUGSTRING("CChainsawFreak::H0x01560002_Hit_02")},
 {0x01560003, -1, CEntity::pEventHandler(&CChainsawFreak::H0x01560003_Hit_03), DEBUGSTRING("CChainsawFreak::H0x01560003_Hit_03")},
 {0x01560004, -1, CEntity::pEventHandler(&CChainsawFreak::H0x01560004_Hit_04), DEBUGSTRING("CChainsawFreak::H0x01560004_Hit_04")},
 {0x01560005, -1, CEntity::pEventHandler(&CChainsawFreak::H0x01560005_Hit_05), DEBUGSTRING("CChainsawFreak::H0x01560005_Hit_05")},
 {0x01560006, -1, CEntity::pEventHandler(&CChainsawFreak::H0x01560006_Hit_06), DEBUGSTRING("CChainsawFreak::H0x01560006_Hit_06")},
 {0x01560007, -1, CEntity::pEventHandler(&CChainsawFreak::H0x01560007_Hit_07), DEBUGSTRING("CChainsawFreak::H0x01560007_Hit_07")},
 {0x01560008, -1, CEntity::pEventHandler(&CChainsawFreak::H0x01560008_Hit_08), DEBUGSTRING("CChainsawFreak::H0x01560008_Hit_08")},
 {0x01560009, -1, CEntity::pEventHandler(&CChainsawFreak::H0x01560009_Hit_09), DEBUGSTRING("CChainsawFreak::H0x01560009_Hit_09")},
 {0x0156000a, STATE_CEnemyBase_AttackEnemy, CEntity::pEventHandler(&CChainsawFreak::
#line 322 "V:/Programs/SamSDK/Sources/EntitiesMP/ChainsawFreak.es"
AttackEnemy),DEBUGSTRING("CChainsawFreak::AttackEnemy")},
 {0x0156000b, STATE_CEnemyBase_BeIdle, CEntity::pEventHandler(&CChainsawFreak::
#line 329 "V:/Programs/SamSDK/Sources/EntitiesMP/ChainsawFreak.es"
BeIdle),DEBUGSTRING("CChainsawFreak::BeIdle")},
 {0x0156000c, STATE_CEnemyRunInto_PostRunAwayFromEnemy, CEntity::pEventHandler(&CChainsawFreak::
#line 336 "V:/Programs/SamSDK/Sources/EntitiesMP/ChainsawFreak.es"
PostRunAwayFromEnemy),DEBUGSTRING("CChainsawFreak::PostRunAwayFromEnemy")},
 {0x0156000d, -1, CEntity::pEventHandler(&CChainsawFreak::H0x0156000d_PostRunAwayFromEnemy_01), DEBUGSTRING("CChainsawFreak::H0x0156000d_PostRunAwayFromEnemy_01")},
 {0x0156000e, -1, CEntity::pEventHandler(&CChainsawFreak::H0x0156000e_PostRunAwayFromEnemy_02), DEBUGSTRING("CChainsawFreak::H0x0156000e_PostRunAwayFromEnemy_02")},
 {0x0156000f, -1, CEntity::pEventHandler(&CChainsawFreak::H0x0156000f_PostRunAwayFromEnemy_03), DEBUGSTRING("CChainsawFreak::H0x0156000f_PostRunAwayFromEnemy_03")},
 {0x01560010, -1, CEntity::pEventHandler(&CChainsawFreak::H0x01560010_PostRunAwayFromEnemy_04), DEBUGSTRING("CChainsawFreak::H0x01560010_PostRunAwayFromEnemy_04")},
 {1, -1, CEntity::pEventHandler(&CChainsawFreak::
#line 348 "V:/Programs/SamSDK/Sources/EntitiesMP/ChainsawFreak.es"
Main),DEBUGSTRING("CChainsawFreak::Main")},
};
#define CChainsawFreak_handlersct ARRAYCOUNT(CChainsawFreak_handlers)

CEntity *CChainsawFreak_New(void) { return new CChainsawFreak; };
void CChainsawFreak_OnInitClass(void) {};
void CChainsawFreak_OnEndClass(void) {};
void CChainsawFreak_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CChainsawFreak_OnWorldEnd(CWorld *pwo) {};
void CChainsawFreak_OnWorldInit(CWorld *pwo) {};
void CChainsawFreak_OnWorldTick(CWorld *pwo) {};
void CChainsawFreak_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CChainsawFreak, CEnemyRunInto, "ChainsawFreak", "Thumbnails\\ChainsawFreak.tbn", 0x00000156);
DECLARE_CTFILENAME(_fnmCChainsawFreak_tbn, "Thumbnails\\ChainsawFreak.tbn");
