/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

EP_ENUMBEG(HeadmanType)
  EP_ENUMVALUE(HDT_FIRECRACKER, "Fire Cracker"),
  EP_ENUMVALUE(HDT_ROCKETMAN, "Rocketman"),
  EP_ENUMVALUE(HDT_BOMBERMAN, "Bomberman"),
  EP_ENUMVALUE(HDT_KAMIKAZE, "Kamikaze"),
EP_ENUMEND(HeadmanType);

#define ENTITYCLASS CHeadman

CEntityProperty CHeadman_properties[] = {
 CEntityProperty(CEntityProperty::EPT_ENUM, &HeadmanType_enum, (0x0000012f<<8)+1, offsetof(CHeadman, m_hdtType), "Type", 'Y', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x0000012f<<8)+5, offsetof(CHeadman, m_bExploded), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x0000012f<<8)+6, offsetof(CHeadman, m_bAttackSound), "", 0, 0, 0),
};
#define CHeadman_propertiesct ARRAYCOUNT(CHeadman_properties)

CEntityComponent CHeadman_components[] = {
#define CLASS_BASE ((0x0000012f<<8)+1)
 CEntityComponent(ECT_CLASS, CLASS_BASE, "EFNM" "Classes\\EnemyBase.ecl"),
#define CLASS_BASIC_EFFECT ((0x0000012f<<8)+2)
 CEntityComponent(ECT_CLASS, CLASS_BASIC_EFFECT, "EFNM" "Classes\\BasicEffect.ecl"),
#define CLASS_PROJECTILE ((0x0000012f<<8)+3)
 CEntityComponent(ECT_CLASS, CLASS_PROJECTILE, "EFNM" "Classes\\Projectile.ecl"),
#define MODEL_HEADMAN ((0x0000012f<<8)+10)
 CEntityComponent(ECT_MODEL, MODEL_HEADMAN, "EFNM" "Models\\Enemies\\Headman\\Headman.mdl"),
#define MODEL_HEAD ((0x0000012f<<8)+11)
 CEntityComponent(ECT_MODEL, MODEL_HEAD, "EFNM" "Models\\Enemies\\Headman\\Head.mdl"),
#define MODEL_FIRECRACKERHEAD ((0x0000012f<<8)+12)
 CEntityComponent(ECT_MODEL, MODEL_FIRECRACKERHEAD, "EFNM" "Models\\Enemies\\Headman\\FirecrackerHead.mdl"),
#define MODEL_CHAINSAW ((0x0000012f<<8)+13)
 CEntityComponent(ECT_MODEL, MODEL_CHAINSAW, "EFNM" "Models\\Enemies\\Headman\\ChainSaw.mdl"),
#define MODEL_ROCKETLAUNCHER ((0x0000012f<<8)+15)
 CEntityComponent(ECT_MODEL, MODEL_ROCKETLAUNCHER, "EFNM" "Models\\Enemies\\Headman\\RocketLauncher.mdl"),
#define MODEL_BOMB ((0x0000012f<<8)+17)
 CEntityComponent(ECT_MODEL, MODEL_BOMB, "EFNM" "Models\\Enemies\\Headman\\Projectile\\Bomb.mdl"),
#define TEXTURE_BOMBERMAN ((0x0000012f<<8)+20)
 CEntityComponent(ECT_TEXTURE, TEXTURE_BOMBERMAN, "EFNM" "Models\\Enemies\\Headman\\Bomberman.tex"),
#define TEXTURE_FIRECRACKER ((0x0000012f<<8)+21)
 CEntityComponent(ECT_TEXTURE, TEXTURE_FIRECRACKER, "EFNM" "Models\\Enemies\\Headman\\Firecracker.tex"),
#define TEXTURE_KAMIKAZE ((0x0000012f<<8)+22)
 CEntityComponent(ECT_TEXTURE, TEXTURE_KAMIKAZE, "EFNM" "Models\\Enemies\\Headman\\Kamikaze.tex"),
#define TEXTURE_ROCKETMAN ((0x0000012f<<8)+23)
 CEntityComponent(ECT_TEXTURE, TEXTURE_ROCKETMAN, "EFNM" "Models\\Enemies\\Headman\\Rocketman.tex"),
#define TEXTURE_HEAD ((0x0000012f<<8)+24)
 CEntityComponent(ECT_TEXTURE, TEXTURE_HEAD, "EFNM" "Models\\Enemies\\Headman\\Head.tex"),
#define TEXTURE_FIRECRACKERHEAD ((0x0000012f<<8)+25)
 CEntityComponent(ECT_TEXTURE, TEXTURE_FIRECRACKERHEAD, "EFNM" "Models\\Enemies\\Headman\\FirecrackerHead.tex"),
#define TEXTURE_CHAINSAW ((0x0000012f<<8)+26)
 CEntityComponent(ECT_TEXTURE, TEXTURE_CHAINSAW, "EFNM" "Models\\Enemies\\Headman\\Chainsaw.tex"),
#define TEXTURE_ROCKETLAUNCHER ((0x0000012f<<8)+28)
 CEntityComponent(ECT_TEXTURE, TEXTURE_ROCKETLAUNCHER, "EFNM" "Models\\Enemies\\Headman\\RocketLauncher.tex"),
#define TEXTURE_BOMB ((0x0000012f<<8)+29)
 CEntityComponent(ECT_TEXTURE, TEXTURE_BOMB, "EFNM" "Models\\Enemies\\Headman\\Projectile\\Bomb.tex"),
#define SOUND_IDLE ((0x0000012f<<8)+50)
 CEntityComponent(ECT_SOUND, SOUND_IDLE, "EFNM" "Models\\Enemies\\Headman\\Sounds\\Idle.wav"),
#define SOUND_IDLEKAMIKAZE ((0x0000012f<<8)+51)
 CEntityComponent(ECT_SOUND, SOUND_IDLEKAMIKAZE, "EFNM" "Models\\Enemies\\Headman\\Sounds\\IdleKamikaze.wav"),
#define SOUND_SIGHT ((0x0000012f<<8)+52)
 CEntityComponent(ECT_SOUND, SOUND_SIGHT, "EFNM" "Models\\Enemies\\Headman\\Sounds\\Sight.wav"),
#define SOUND_WOUND ((0x0000012f<<8)+53)
 CEntityComponent(ECT_SOUND, SOUND_WOUND, "EFNM" "Models\\Enemies\\Headman\\Sounds\\Wound.wav"),
#define SOUND_FIREROCKETMAN ((0x0000012f<<8)+54)
 CEntityComponent(ECT_SOUND, SOUND_FIREROCKETMAN, "EFNM" "Models\\Enemies\\Headman\\Sounds\\FireRocketman.wav"),
#define SOUND_FIREFIRECRACKER ((0x0000012f<<8)+55)
 CEntityComponent(ECT_SOUND, SOUND_FIREFIRECRACKER, "EFNM" "Models\\Enemies\\Headman\\Sounds\\FireFirecracker.wav"),
#define SOUND_FIREBOMBERMAN ((0x0000012f<<8)+56)
 CEntityComponent(ECT_SOUND, SOUND_FIREBOMBERMAN, "EFNM" "Models\\Enemies\\Headman\\Sounds\\FireBomberman.wav"),
#define SOUND_ATTACKKAMIKAZE ((0x0000012f<<8)+57)
 CEntityComponent(ECT_SOUND, SOUND_ATTACKKAMIKAZE, "EFNM" "Models\\Enemies\\Headman\\Sounds\\AttackKamikaze.wav"),
#define SOUND_DEATH ((0x0000012f<<8)+58)
 CEntityComponent(ECT_SOUND, SOUND_DEATH, "EFNM" "Models\\Enemies\\Headman\\Sounds\\Death.wav"),
};
#define CHeadman_componentsct ARRAYCOUNT(CHeadman_components)

CEventHandlerEntry CHeadman_handlers[] = {
 {0x012f0000, STATE_CEnemyBase_InitializeAttack, CEntity::pEventHandler(&CHeadman::
#line 462 "V:/Programs/SamSDK/Sources/EntitiesMP/Headman.es"
InitializeAttack),DEBUGSTRING("CHeadman::InitializeAttack")},
 {0x012f0001, STATE_CEnemyBase_StopAttack, CEntity::pEventHandler(&CHeadman::
#line 469 "V:/Programs/SamSDK/Sources/EntitiesMP/Headman.es"
StopAttack),DEBUGSTRING("CHeadman::StopAttack")},
 {0x012f0002, STATE_CEnemyBase_Fire, CEntity::pEventHandler(&CHeadman::
#line 474 "V:/Programs/SamSDK/Sources/EntitiesMP/Headman.es"
Fire),DEBUGSTRING("CHeadman::Fire")},
 {0x012f0003, -1, CEntity::pEventHandler(&CHeadman::H0x012f0003_Fire_01), DEBUGSTRING("CHeadman::H0x012f0003_Fire_01")},
 {0x012f0004, -1, CEntity::pEventHandler(&CHeadman::H0x012f0004_Fire_02), DEBUGSTRING("CHeadman::H0x012f0004_Fire_02")},
 {0x012f0005, -1, CEntity::pEventHandler(&CHeadman::H0x012f0005_Fire_03), DEBUGSTRING("CHeadman::H0x012f0005_Fire_03")},
 {0x012f0006, -1, CEntity::pEventHandler(&CHeadman::H0x012f0006_Fire_04), DEBUGSTRING("CHeadman::H0x012f0006_Fire_04")},
 {0x012f0007, -1, CEntity::pEventHandler(&CHeadman::H0x012f0007_Fire_05), DEBUGSTRING("CHeadman::H0x012f0007_Fire_05")},
 {0x012f0008, -1, CEntity::pEventHandler(&CHeadman::H0x012f0008_Fire_06), DEBUGSTRING("CHeadman::H0x012f0008_Fire_06")},
 {0x012f0009, -1, CEntity::pEventHandler(&CHeadman::H0x012f0009_Fire_07), DEBUGSTRING("CHeadman::H0x012f0009_Fire_07")},
 {0x012f000a, -1, CEntity::pEventHandler(&CHeadman::H0x012f000a_Fire_08), DEBUGSTRING("CHeadman::H0x012f000a_Fire_08")},
 {0x012f000b, -1, CEntity::pEventHandler(&CHeadman::H0x012f000b_Fire_09), DEBUGSTRING("CHeadman::H0x012f000b_Fire_09")},
 {0x012f000c, -1, CEntity::pEventHandler(&CHeadman::H0x012f000c_Fire_10), DEBUGSTRING("CHeadman::H0x012f000c_Fire_10")},
 {0x012f000d, -1, CEntity::pEventHandler(&CHeadman::H0x012f000d_Fire_11), DEBUGSTRING("CHeadman::H0x012f000d_Fire_11")},
 {0x012f000e, -1, CEntity::pEventHandler(&CHeadman::H0x012f000e_Fire_12), DEBUGSTRING("CHeadman::H0x012f000e_Fire_12")},
 {0x012f000f, -1, CEntity::pEventHandler(&CHeadman::
#line 492 "V:/Programs/SamSDK/Sources/EntitiesMP/Headman.es"
BombermanAttack),DEBUGSTRING("CHeadman::BombermanAttack")},
 {0x012f0010, -1, CEntity::pEventHandler(&CHeadman::H0x012f0010_BombermanAttack_01), DEBUGSTRING("CHeadman::H0x012f0010_BombermanAttack_01")},
 {0x012f0011, -1, CEntity::pEventHandler(&CHeadman::H0x012f0011_BombermanAttack_02), DEBUGSTRING("CHeadman::H0x012f0011_BombermanAttack_02")},
 {0x012f0012, -1, CEntity::pEventHandler(&CHeadman::H0x012f0012_BombermanAttack_03), DEBUGSTRING("CHeadman::H0x012f0012_BombermanAttack_03")},
 {0x012f0013, -1, CEntity::pEventHandler(&CHeadman::H0x012f0013_BombermanAttack_04), DEBUGSTRING("CHeadman::H0x012f0013_BombermanAttack_04")},
 {0x012f0014, -1, CEntity::pEventHandler(&CHeadman::H0x012f0014_BombermanAttack_05), DEBUGSTRING("CHeadman::H0x012f0014_BombermanAttack_05")},
 {0x012f0015, -1, CEntity::pEventHandler(&CHeadman::H0x012f0015_BombermanAttack_06), DEBUGSTRING("CHeadman::H0x012f0015_BombermanAttack_06")},
 {0x012f0016, -1, CEntity::pEventHandler(&CHeadman::H0x012f0016_BombermanAttack_07), DEBUGSTRING("CHeadman::H0x012f0016_BombermanAttack_07")},
 {0x012f0017, -1, CEntity::pEventHandler(&CHeadman::H0x012f0017_BombermanAttack_08), DEBUGSTRING("CHeadman::H0x012f0017_BombermanAttack_08")},
 {0x012f0018, -1, CEntity::pEventHandler(&CHeadman::
#line 541 "V:/Programs/SamSDK/Sources/EntitiesMP/Headman.es"
FirecrackerAttack),DEBUGSTRING("CHeadman::FirecrackerAttack")},
 {0x012f0019, -1, CEntity::pEventHandler(&CHeadman::H0x012f0019_FirecrackerAttack_01), DEBUGSTRING("CHeadman::H0x012f0019_FirecrackerAttack_01")},
 {0x012f001a, -1, CEntity::pEventHandler(&CHeadman::H0x012f001a_FirecrackerAttack_02), DEBUGSTRING("CHeadman::H0x012f001a_FirecrackerAttack_02")},
 {0x012f001b, -1, CEntity::pEventHandler(&CHeadman::H0x012f001b_FirecrackerAttack_03), DEBUGSTRING("CHeadman::H0x012f001b_FirecrackerAttack_03")},
 {0x012f001c, -1, CEntity::pEventHandler(&CHeadman::H0x012f001c_FirecrackerAttack_04), DEBUGSTRING("CHeadman::H0x012f001c_FirecrackerAttack_04")},
 {0x012f001d, -1, CEntity::pEventHandler(&CHeadman::H0x012f001d_FirecrackerAttack_05), DEBUGSTRING("CHeadman::H0x012f001d_FirecrackerAttack_05")},
 {0x012f001e, -1, CEntity::pEventHandler(&CHeadman::H0x012f001e_FirecrackerAttack_06), DEBUGSTRING("CHeadman::H0x012f001e_FirecrackerAttack_06")},
 {0x012f001f, -1, CEntity::pEventHandler(&CHeadman::H0x012f001f_FirecrackerAttack_07), DEBUGSTRING("CHeadman::H0x012f001f_FirecrackerAttack_07")},
 {0x012f0020, -1, CEntity::pEventHandler(&CHeadman::H0x012f0020_FirecrackerAttack_08), DEBUGSTRING("CHeadman::H0x012f0020_FirecrackerAttack_08")},
 {0x012f0021, -1, CEntity::pEventHandler(&CHeadman::H0x012f0021_FirecrackerAttack_09), DEBUGSTRING("CHeadman::H0x012f0021_FirecrackerAttack_09")},
 {0x012f0022, -1, CEntity::pEventHandler(&CHeadman::H0x012f0022_FirecrackerAttack_10), DEBUGSTRING("CHeadman::H0x012f0022_FirecrackerAttack_10")},
 {0x012f0023, -1, CEntity::pEventHandler(&CHeadman::H0x012f0023_FirecrackerAttack_11), DEBUGSTRING("CHeadman::H0x012f0023_FirecrackerAttack_11")},
 {0x012f0024, -1, CEntity::pEventHandler(&CHeadman::H0x012f0024_FirecrackerAttack_12), DEBUGSTRING("CHeadman::H0x012f0024_FirecrackerAttack_12")},
 {0x012f0025, -1, CEntity::pEventHandler(&CHeadman::H0x012f0025_FirecrackerAttack_13), DEBUGSTRING("CHeadman::H0x012f0025_FirecrackerAttack_13")},
 {0x012f0026, -1, CEntity::pEventHandler(&CHeadman::H0x012f0026_FirecrackerAttack_14), DEBUGSTRING("CHeadman::H0x012f0026_FirecrackerAttack_14")},
 {0x012f0027, -1, CEntity::pEventHandler(&CHeadman::H0x012f0027_FirecrackerAttack_15), DEBUGSTRING("CHeadman::H0x012f0027_FirecrackerAttack_15")},
 {0x012f0028, -1, CEntity::pEventHandler(&CHeadman::H0x012f0028_FirecrackerAttack_16), DEBUGSTRING("CHeadman::H0x012f0028_FirecrackerAttack_16")},
 {0x012f0029, -1, CEntity::pEventHandler(&CHeadman::
#line 572 "V:/Programs/SamSDK/Sources/EntitiesMP/Headman.es"
RocketmanAttack),DEBUGSTRING("CHeadman::RocketmanAttack")},
 {0x012f002a, -1, CEntity::pEventHandler(&CHeadman::H0x012f002a_RocketmanAttack_01), DEBUGSTRING("CHeadman::H0x012f002a_RocketmanAttack_01")},
 {0x012f002b, -1, CEntity::pEventHandler(&CHeadman::H0x012f002b_RocketmanAttack_02), DEBUGSTRING("CHeadman::H0x012f002b_RocketmanAttack_02")},
 {0x012f002c, -1, CEntity::pEventHandler(&CHeadman::H0x012f002c_RocketmanAttack_03), DEBUGSTRING("CHeadman::H0x012f002c_RocketmanAttack_03")},
 {0x012f002d, -1, CEntity::pEventHandler(&CHeadman::H0x012f002d_RocketmanAttack_04), DEBUGSTRING("CHeadman::H0x012f002d_RocketmanAttack_04")},
 {0x012f002e, STATE_CEnemyBase_Death, CEntity::pEventHandler(&CHeadman::
#line 589 "V:/Programs/SamSDK/Sources/EntitiesMP/Headman.es"
Death),DEBUGSTRING("CHeadman::Death")},
 {0x012f002f, -1, CEntity::pEventHandler(&CHeadman::H0x012f002f_Death_01), DEBUGSTRING("CHeadman::H0x012f002f_Death_01")},
 {0x012f0030, -1, CEntity::pEventHandler(&CHeadman::H0x012f0030_Death_02), DEBUGSTRING("CHeadman::H0x012f0030_Death_02")},
 {1, -1, CEntity::pEventHandler(&CHeadman::
#line 610 "V:/Programs/SamSDK/Sources/EntitiesMP/Headman.es"
Main),DEBUGSTRING("CHeadman::Main")},
};
#define CHeadman_handlersct ARRAYCOUNT(CHeadman_handlers)

CEntity *CHeadman_New(void) { return new CHeadman; };
void CHeadman_OnInitClass(void) {};
void CHeadman_OnEndClass(void) {};
void CHeadman_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CHeadman_OnWorldEnd(CWorld *pwo) {};
void CHeadman_OnWorldInit(CWorld *pwo) {};
void CHeadman_OnWorldTick(CWorld *pwo) {};
void CHeadman_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CHeadman, CEnemyBase, "Headman", "Thumbnails\\Headman.tbn", 0x0000012f);
DECLARE_CTFILENAME(_fnmCHeadman_tbn, "Thumbnails\\Headman.tbn");
