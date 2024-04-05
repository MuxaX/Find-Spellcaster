/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

EP_ENUMBEG(ScorpmanType)
  EP_ENUMVALUE(SMT_SOLDIER, "Soldier"),
  EP_ENUMVALUE(SMT_GENERAL, "General"),
  EP_ENUMVALUE(SMT_MONSTER, "Obsolete"),
EP_ENUMEND(ScorpmanType);

#define ENTITYCLASS CScorpman

CEntityProperty CScorpman_properties[] = {
 CEntityProperty(CEntityProperty::EPT_ENUM, &ScorpmanType_enum, (0x00000132<<8)+1, offsetof(CScorpman, m_smtType), "Type", 'Y', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x00000132<<8)+2, offsetof(CScorpman, m_bFireBulletCount), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x00000132<<8)+3, offsetof(CScorpman, m_iSpawnEffect), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000132<<8)+4, offsetof(CScorpman, m_fFireTime), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ANIMOBJECT, NULL, (0x00000132<<8)+5, offsetof(CScorpman, m_aoLightAnimation), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x00000132<<8)+6, offsetof(CScorpman, m_bSleeping), "Sleeping", 'S', 0x7F0000FFUL, 0),
};
#define CScorpman_propertiesct ARRAYCOUNT(CScorpman_properties)

CEntityComponent CScorpman_components[] = {
#define CLASS_BASE ((0x00000132<<8)+0)
 CEntityComponent(ECT_CLASS, CLASS_BASE, "EFNM" "Classes\\EnemyBase.ecl"),
#define CLASS_BULLET ((0x00000132<<8)+1)
 CEntityComponent(ECT_CLASS, CLASS_BULLET, "EFNM" "Classes\\Bullet.ecl"),
#define MODEL_SCORPMAN ((0x00000132<<8)+5)
 CEntityComponent(ECT_MODEL, MODEL_SCORPMAN, "EFNM" "Models\\Enemies\\Scorpman\\Scorpman.mdl"),
#define TEXTURE_SOLDIER ((0x00000132<<8)+6)
 CEntityComponent(ECT_TEXTURE, TEXTURE_SOLDIER, "EFNM" "Models\\Enemies\\Scorpman\\Soldier.tex"),
#define TEXTURE_GENERAL ((0x00000132<<8)+7)
 CEntityComponent(ECT_TEXTURE, TEXTURE_GENERAL, "EFNM" "Models\\Enemies\\Scorpman\\General.tex"),
#define TEXTURE_SPECULAR ((0x00000132<<8)+12)
 CEntityComponent(ECT_TEXTURE, TEXTURE_SPECULAR, "EFNM" "Models\\SpecularTextures\\Medium.tex"),
#define MODEL_GUN ((0x00000132<<8)+9)
 CEntityComponent(ECT_MODEL, MODEL_GUN, "EFNM" "Models\\Enemies\\Scorpman\\Gun.mdl"),
#define MODEL_FLARE ((0x00000132<<8)+10)
 CEntityComponent(ECT_MODEL, MODEL_FLARE, "EFNM" "Models\\Enemies\\Scorpman\\Flare.mdl"),
#define TEXTURE_GUN ((0x00000132<<8)+11)
 CEntityComponent(ECT_TEXTURE, TEXTURE_GUN, "EFNM" "Models\\Enemies\\Scorpman\\Gun.tex"),
#define SOUND_IDLE ((0x00000132<<8)+50)
 CEntityComponent(ECT_SOUND, SOUND_IDLE, "EFNM" "Models\\Enemies\\Scorpman\\Sounds\\Idle.wav"),
#define SOUND_SIGHT ((0x00000132<<8)+51)
 CEntityComponent(ECT_SOUND, SOUND_SIGHT, "EFNM" "Models\\Enemies\\Scorpman\\Sounds\\Sight.wav"),
#define SOUND_WOUND ((0x00000132<<8)+52)
 CEntityComponent(ECT_SOUND, SOUND_WOUND, "EFNM" "Models\\Enemies\\Scorpman\\Sounds\\Wound.wav"),
#define SOUND_FIRE ((0x00000132<<8)+53)
 CEntityComponent(ECT_SOUND, SOUND_FIRE, "EFNM" "Models\\Enemies\\Scorpman\\Sounds\\Fire.wav"),
#define SOUND_KICK ((0x00000132<<8)+54)
 CEntityComponent(ECT_SOUND, SOUND_KICK, "EFNM" "Models\\Enemies\\Scorpman\\Sounds\\Kick.wav"),
#define SOUND_DEATH ((0x00000132<<8)+55)
 CEntityComponent(ECT_SOUND, SOUND_DEATH, "EFNM" "Models\\Enemies\\Scorpman\\Sounds\\Death.wav"),
};
#define CScorpman_componentsct ARRAYCOUNT(CScorpman_components)

CEventHandlerEntry CScorpman_handlers[] = {
 {0x01320000, STATE_CEnemyBase_Fire, CEntity::pEventHandler(&CScorpman::
#line 372 "V:/Programs/SamSDK/Sources/EntitiesMP/Scorpman.es"
Fire),DEBUGSTRING("CScorpman::Fire")},
 {0x01320001, -1, CEntity::pEventHandler(&CScorpman::H0x01320001_Fire_01), DEBUGSTRING("CScorpman::H0x01320001_Fire_01")},
 {0x01320002, -1, CEntity::pEventHandler(&CScorpman::H0x01320002_Fire_02), DEBUGSTRING("CScorpman::H0x01320002_Fire_02")},
 {0x01320003, -1, CEntity::pEventHandler(&CScorpman::H0x01320003_Fire_03), DEBUGSTRING("CScorpman::H0x01320003_Fire_03")},
 {0x01320004, -1, CEntity::pEventHandler(&CScorpman::H0x01320004_Fire_04), DEBUGSTRING("CScorpman::H0x01320004_Fire_04")},
 {0x01320005, -1, CEntity::pEventHandler(&CScorpman::H0x01320005_Fire_05), DEBUGSTRING("CScorpman::H0x01320005_Fire_05")},
 {0x01320006, -1, CEntity::pEventHandler(&CScorpman::H0x01320006_Fire_06), DEBUGSTRING("CScorpman::H0x01320006_Fire_06")},
 {0x01320007, -1, CEntity::pEventHandler(&CScorpman::H0x01320007_Fire_07), DEBUGSTRING("CScorpman::H0x01320007_Fire_07")},
 {0x01320008, -1, CEntity::pEventHandler(&CScorpman::H0x01320008_Fire_08), DEBUGSTRING("CScorpman::H0x01320008_Fire_08")},
 {0x01320009, STATE_CEnemyBase_Hit, CEntity::pEventHandler(&CScorpman::
#line 450 "V:/Programs/SamSDK/Sources/EntitiesMP/Scorpman.es"
Hit),DEBUGSTRING("CScorpman::Hit")},
 {0x0132000a, -1, CEntity::pEventHandler(&CScorpman::H0x0132000a_Hit_01), DEBUGSTRING("CScorpman::H0x0132000a_Hit_01")},
 {0x0132000b, -1, CEntity::pEventHandler(&CScorpman::H0x0132000b_Hit_02), DEBUGSTRING("CScorpman::H0x0132000b_Hit_02")},
 {0x0132000c, -1, CEntity::pEventHandler(&CScorpman::H0x0132000c_Hit_03), DEBUGSTRING("CScorpman::H0x0132000c_Hit_03")},
 {0x0132000d, -1, CEntity::pEventHandler(&CScorpman::H0x0132000d_Hit_04), DEBUGSTRING("CScorpman::H0x0132000d_Hit_04")},
 {0x0132000e, -1, CEntity::pEventHandler(&CScorpman::
#line 471 "V:/Programs/SamSDK/Sources/EntitiesMP/Scorpman.es"
Sleep),DEBUGSTRING("CScorpman::Sleep")},
 {0x0132000f, -1, CEntity::pEventHandler(&CScorpman::H0x0132000f_Sleep_01), DEBUGSTRING("CScorpman::H0x0132000f_Sleep_01")},
 {0x01320010, -1, CEntity::pEventHandler(&CScorpman::H0x01320010_Sleep_02), DEBUGSTRING("CScorpman::H0x01320010_Sleep_02")},
 {0x01320011, -1, CEntity::pEventHandler(&CScorpman::
#line 495 "V:/Programs/SamSDK/Sources/EntitiesMP/Scorpman.es"
WakeUp),DEBUGSTRING("CScorpman::WakeUp")},
 {0x01320012, -1, CEntity::pEventHandler(&CScorpman::H0x01320012_WakeUp_01), DEBUGSTRING("CScorpman::H0x01320012_WakeUp_01")},
 {0x01320013, -1, CEntity::pEventHandler(&CScorpman::H0x01320013_WakeUp_02), DEBUGSTRING("CScorpman::H0x01320013_WakeUp_02")},
 {0x01320014, STATE_CEnemyBase_PreMainLoop, CEntity::pEventHandler(&CScorpman::
#line 509 "V:/Programs/SamSDK/Sources/EntitiesMP/Scorpman.es"
PreMainLoop),DEBUGSTRING("CScorpman::PreMainLoop")},
 {0x01320015, -1, CEntity::pEventHandler(&CScorpman::H0x01320015_PreMainLoop_01), DEBUGSTRING("CScorpman::H0x01320015_PreMainLoop_01")},
 {0x01320016, -1, CEntity::pEventHandler(&CScorpman::H0x01320016_PreMainLoop_02), DEBUGSTRING("CScorpman::H0x01320016_PreMainLoop_02")},
 {0x01320017, -1, CEntity::pEventHandler(&CScorpman::H0x01320017_PreMainLoop_03), DEBUGSTRING("CScorpman::H0x01320017_PreMainLoop_03")},
 {1, -1, CEntity::pEventHandler(&CScorpman::
#line 535 "V:/Programs/SamSDK/Sources/EntitiesMP/Scorpman.es"
Main),DEBUGSTRING("CScorpman::Main")},
};
#define CScorpman_handlersct ARRAYCOUNT(CScorpman_handlers)

CEntity *CScorpman_New(void) { return new CScorpman; };
void CScorpman_OnInitClass(void) {};
void CScorpman_OnEndClass(void) {};
void CScorpman_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CScorpman_OnWorldEnd(CWorld *pwo) {};
void CScorpman_OnWorldInit(CWorld *pwo) {};
void CScorpman_OnWorldTick(CWorld *pwo) {};
void CScorpman_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CScorpman, CEnemyBase, "Scorpman", "Thumbnails\\Scorpman.tbn", 0x00000132);
DECLARE_CTFILENAME(_fnmCScorpman_tbn, "Thumbnails\\Scorpman.tbn");