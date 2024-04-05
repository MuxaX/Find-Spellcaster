/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CAirElemental

CEntityProperty CAirElemental_properties[] = {
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x0000015b<<8)+2, offsetof(CAirElemental, m_bFloat), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+3, offsetof(CAirElemental, m_fAttPosY), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x0000015b<<8)+10, offsetof(CAirElemental, m_bInitialAnim), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000015b<<8)+20, offsetof(CAirElemental, m_penTrigger01), "AirBoss 90% Trigger", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000015b<<8)+21, offsetof(CAirElemental, m_penTrigger02), "AirBoss 80% Trigger", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000015b<<8)+22, offsetof(CAirElemental, m_penTrigger03), "AirBoss 70% Trigger", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000015b<<8)+23, offsetof(CAirElemental, m_penTrigger04), "AirBoss 60% Trigger", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000015b<<8)+24, offsetof(CAirElemental, m_penTrigger05), "AirBoss 50% Trigger", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000015b<<8)+25, offsetof(CAirElemental, m_penTrigger06), "AirBoss 40% Trigger", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000015b<<8)+26, offsetof(CAirElemental, m_penTrigger07), "AirBoss 30% Trigger", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000015b<<8)+27, offsetof(CAirElemental, m_penTrigger08), "AirBoss 20% Trigger", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000015b<<8)+28, offsetof(CAirElemental, m_penTrigger09), "AirBoss 10% Trigger", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000015b<<8)+29, offsetof(CAirElemental, m_penTrigger10), "AirBoss 05% Trigger", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+30, offsetof(CAirElemental, m_fAttSizeCurrent), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+31, offsetof(CAirElemental, m_fAttSizeBegin), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+32, offsetof(CAirElemental, m_fAttSizeEnd), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+33, offsetof(CAirElemental, m_fAttSizeRequested), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x0000015b<<8)+34, offsetof(CAirElemental, m_bAttGrow), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x0000015b<<8)+35, offsetof(CAirElemental, m_iSize), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+36, offsetof(CAirElemental, m_fLastSize), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+37, offsetof(CAirElemental, m_fTargetSize), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+47, offsetof(CAirElemental, m_fGrowSpeed), "AirBoss Grow Speed", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+43, offsetof(CAirElemental, m_tmWindNextFire), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+44, offsetof(CAirElemental, m_fWindFireTimeMin), "AirBoss Wind Fire Min. Time", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+45, offsetof(CAirElemental, m_fWindFireTimeMax), "AirBoss Wind Fire Max. Time", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x0000015b<<8)+46, offsetof(CAirElemental, m_iWind), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x0000015b<<8)+50, offsetof(CAirElemental, m_bDying), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+51, offsetof(CAirElemental, m_tmDeath), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+52, offsetof(CAirElemental, m_fDeathDuration), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT3D, NULL, (0x0000015b<<8)+60, offsetof(CAirElemental, m_fWindBlastFirePosBegin), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT3D, NULL, (0x0000015b<<8)+61, offsetof(CAirElemental, m_fWindBlastFirePosEnd), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000015b<<8)+70, offsetof(CAirElemental, m_tmLastAnimation), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000015b<<8)+90, offsetof(CAirElemental, m_penDeathInflictor), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x0000015b<<8)+91, offsetof(CAirElemental, m_bRenderParticles), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_SOUNDOBJECT, NULL, (0x0000015b<<8)+100, offsetof(CAirElemental, m_soFire), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_SOUNDOBJECT, NULL, (0x0000015b<<8)+101, offsetof(CAirElemental, m_soVoice), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x0000015b<<8)+110, offsetof(CAirElemental, m_colParticles), "Color of particles", 0, 0x7F0000FFUL, 0),
};
#define CAirElemental_propertiesct ARRAYCOUNT(CAirElemental_properties)

CEntityComponent CAirElemental_components[] = {
#define CLASS_BASE ((0x0000015b<<8)+0)
 CEntityComponent(ECT_CLASS, CLASS_BASE, "EFNM" "Classes\\EnemyBase.ecl"),
#define CLASS_TWISTER ((0x0000015b<<8)+1)
 CEntityComponent(ECT_CLASS, CLASS_TWISTER, "EFNM" "Classes\\Twister.ecl"),
#define CLASS_BLOOD_SPRAY ((0x0000015b<<8)+2)
 CEntityComponent(ECT_CLASS, CLASS_BLOOD_SPRAY, "EFNM" "Classes\\BloodSpray.ecl"),
#define CLASS_PROJECTILE ((0x0000015b<<8)+3)
 CEntityComponent(ECT_CLASS, CLASS_PROJECTILE, "EFNM" "Classes\\Projectile.ecl"),
#define MODEL_INVISIBLE ((0x0000015b<<8)+10)
 CEntityComponent(ECT_MODEL, MODEL_INVISIBLE, "EFNM" "ModelsMP\\Enemies\\AirElemental\\AirElemental.mdl"),
#define MODEL_ELEMENTAL ((0x0000015b<<8)+11)
 CEntityComponent(ECT_MODEL, MODEL_ELEMENTAL, "EFNM" "ModelsMP\\Enemies\\AirElemental\\Elemental.mdl"),
#define TEXTURE_ELEMENTAL ((0x0000015b<<8)+12)
 CEntityComponent(ECT_TEXTURE, TEXTURE_ELEMENTAL, "EFNM" "ModelsMP\\Enemies\\AirElemental\\Elemental.tex"),
#define TEXTURE_DETAIL_ELEM ((0x0000015b<<8)+13)
 CEntityComponent(ECT_TEXTURE, TEXTURE_DETAIL_ELEM, "EFNM" "ModelsMP\\Enemies\\AirElemental\\Detail.tex"),
#define SOUND_FIREWINDBLAST ((0x0000015b<<8)+200)
 CEntityComponent(ECT_SOUND, SOUND_FIREWINDBLAST, "EFNM" "ModelsMP\\Enemies\\AirElemental\\Sounds\\BlastFire.wav"),
#define SOUND_FIRETWISTER ((0x0000015b<<8)+201)
 CEntityComponent(ECT_SOUND, SOUND_FIRETWISTER, "EFNM" "ModelsMP\\Enemies\\AirElemental\\Sounds\\Fire.wav"),
#define SOUND_ROAR ((0x0000015b<<8)+202)
 CEntityComponent(ECT_SOUND, SOUND_ROAR, "EFNM" "ModelsMP\\Enemies\\AirElemental\\Sounds\\Anger.wav"),
#define SOUND_DEATH ((0x0000015b<<8)+203)
 CEntityComponent(ECT_SOUND, SOUND_DEATH, "EFNM" "ModelsMP\\Enemies\\AirElemental\\Sounds\\Death.wav"),
#define SOUND_EXPLOSION ((0x0000015b<<8)+204)
 CEntityComponent(ECT_SOUND, SOUND_EXPLOSION, "EFNM" "ModelsMP\\Enemies\\AirElemental\\Sounds\\Explosion.wav"),
};
#define CAirElemental_componentsct ARRAYCOUNT(CAirElemental_components)

CEventHandlerEntry CAirElemental_handlers[] = {
 {0x015b0001, STATE_CEnemyBase_Die, CEntity::pEventHandler(&CAirElemental::
#line 476 "V:/Programs/SamSDK/Sources/EntitiesMP/AirElemental.es"
Die),DEBUGSTRING("CAirElemental::Die")},
 {0x015b0002, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0002_Die_01), DEBUGSTRING("CAirElemental::H0x015b0002_Die_01")},
 {0x015b0003, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0003_Die_02), DEBUGSTRING("CAirElemental::H0x015b0003_Die_02")},
 {0x015b0004, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0004_Die_03), DEBUGSTRING("CAirElemental::H0x015b0004_Die_03")},
 {0x015b0005, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0005_Die_04), DEBUGSTRING("CAirElemental::H0x015b0005_Die_04")},
 {0x015b0006, STATE_CEnemyBase_Fire, CEntity::pEventHandler(&CAirElemental::
#line 500 "V:/Programs/SamSDK/Sources/EntitiesMP/AirElemental.es"
Fire),DEBUGSTRING("CAirElemental::Fire")},
 {0x015b0007, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0007_Fire_01), DEBUGSTRING("CAirElemental::H0x015b0007_Fire_01")},
 {0x015b0008, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0008_Fire_02), DEBUGSTRING("CAirElemental::H0x015b0008_Fire_02")},
 {0x015b0009, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0009_Fire_03), DEBUGSTRING("CAirElemental::H0x015b0009_Fire_03")},
 {0x015b000a, -1, CEntity::pEventHandler(&CAirElemental::H0x015b000a_Fire_04), DEBUGSTRING("CAirElemental::H0x015b000a_Fire_04")},
 {0x015b000b, -1, CEntity::pEventHandler(&CAirElemental::H0x015b000b_Fire_05), DEBUGSTRING("CAirElemental::H0x015b000b_Fire_05")},
 {0x015b000c, -1, CEntity::pEventHandler(&CAirElemental::H0x015b000c_Fire_06), DEBUGSTRING("CAirElemental::H0x015b000c_Fire_06")},
 {0x015b000d, -1, CEntity::pEventHandler(&CAirElemental::H0x015b000d_Fire_07), DEBUGSTRING("CAirElemental::H0x015b000d_Fire_07")},
 {0x015b000e, -1, CEntity::pEventHandler(&CAirElemental::H0x015b000e_Fire_08), DEBUGSTRING("CAirElemental::H0x015b000e_Fire_08")},
 {0x015b000f, -1, CEntity::pEventHandler(&CAirElemental::H0x015b000f_Fire_09), DEBUGSTRING("CAirElemental::H0x015b000f_Fire_09")},
 {0x015b0010, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0010_Fire_10), DEBUGSTRING("CAirElemental::H0x015b0010_Fire_10")},
 {0x015b0011, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0011_Fire_11), DEBUGSTRING("CAirElemental::H0x015b0011_Fire_11")},
 {0x015b0012, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0012_Fire_12), DEBUGSTRING("CAirElemental::H0x015b0012_Fire_12")},
 {0x015b0013, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0013_Fire_13), DEBUGSTRING("CAirElemental::H0x015b0013_Fire_13")},
 {0x015b0014, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0014_Fire_14), DEBUGSTRING("CAirElemental::H0x015b0014_Fire_14")},
 {0x015b0015, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0015_Fire_15), DEBUGSTRING("CAirElemental::H0x015b0015_Fire_15")},
 {0x015b0016, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0016_Fire_16), DEBUGSTRING("CAirElemental::H0x015b0016_Fire_16")},
 {0x015b0017, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0017_Fire_17), DEBUGSTRING("CAirElemental::H0x015b0017_Fire_17")},
 {0x015b0018, STATE_CEnemyBase_Hit, CEntity::pEventHandler(&CAirElemental::
#line 577 "V:/Programs/SamSDK/Sources/EntitiesMP/AirElemental.es"
Hit),DEBUGSTRING("CAirElemental::Hit")},
 {0x015b0019, STATE_CEnemyBase_Death, CEntity::pEventHandler(&CAirElemental::
#line 585 "V:/Programs/SamSDK/Sources/EntitiesMP/AirElemental.es"
Death),DEBUGSTRING("CAirElemental::Death")},
 {0x015b001a, -1, CEntity::pEventHandler(&CAirElemental::H0x015b001a_Death_01), DEBUGSTRING("CAirElemental::H0x015b001a_Death_01")},
 {0x015b001b, -1, CEntity::pEventHandler(&CAirElemental::H0x015b001b_Death_02), DEBUGSTRING("CAirElemental::H0x015b001b_Death_02")},
 {0x015b001c, -1, CEntity::pEventHandler(&CAirElemental::H0x015b001c_Death_03), DEBUGSTRING("CAirElemental::H0x015b001c_Death_03")},
 {0x015b001d, -1, CEntity::pEventHandler(&CAirElemental::H0x015b001d_Death_04), DEBUGSTRING("CAirElemental::H0x015b001d_Death_04")},
 {0x015b001e, -1, CEntity::pEventHandler(&CAirElemental::
#line 600 "V:/Programs/SamSDK/Sources/EntitiesMP/AirElemental.es"
Grow),DEBUGSTRING("CAirElemental::Grow")},
 {0x015b001f, -1, CEntity::pEventHandler(&CAirElemental::H0x015b001f_Grow_01), DEBUGSTRING("CAirElemental::H0x015b001f_Grow_01")},
 {0x015b0020, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0020_Grow_02), DEBUGSTRING("CAirElemental::H0x015b0020_Grow_02")},
 {0x015b0021, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0021_Grow_03), DEBUGSTRING("CAirElemental::H0x015b0021_Grow_03")},
 {0x015b0022, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0022_Grow_04), DEBUGSTRING("CAirElemental::H0x015b0022_Grow_04")},
 {0x015b0023, -1, CEntity::pEventHandler(&CAirElemental::
#line 656 "V:/Programs/SamSDK/Sources/EntitiesMP/AirElemental.es"
ElementalLoop),DEBUGSTRING("CAirElemental::ElementalLoop")},
 {0x015b0024, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0024_ElementalLoop_01), DEBUGSTRING("CAirElemental::H0x015b0024_ElementalLoop_01")},
 {0x015b0025, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0025_ElementalLoop_02), DEBUGSTRING("CAirElemental::H0x015b0025_ElementalLoop_02")},
 {1, -1, CEntity::pEventHandler(&CAirElemental::
#line 672 "V:/Programs/SamSDK/Sources/EntitiesMP/AirElemental.es"
Main),DEBUGSTRING("CAirElemental::Main")},
 {0x015b0026, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0026_Main_01), DEBUGSTRING("CAirElemental::H0x015b0026_Main_01")},
 {0x015b0027, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0027_Main_02), DEBUGSTRING("CAirElemental::H0x015b0027_Main_02")},
 {0x015b0028, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0028_Main_03), DEBUGSTRING("CAirElemental::H0x015b0028_Main_03")},
 {0x015b0029, -1, CEntity::pEventHandler(&CAirElemental::H0x015b0029_Main_04), DEBUGSTRING("CAirElemental::H0x015b0029_Main_04")},
 {0x015b002a, -1, CEntity::pEventHandler(&CAirElemental::H0x015b002a_Main_05), DEBUGSTRING("CAirElemental::H0x015b002a_Main_05")},
 {0x015b002b, -1, CEntity::pEventHandler(&CAirElemental::H0x015b002b_Main_06), DEBUGSTRING("CAirElemental::H0x015b002b_Main_06")},
};
#define CAirElemental_handlersct ARRAYCOUNT(CAirElemental_handlers)

CEntity *CAirElemental_New(void) { return new CAirElemental; };
void CAirElemental_OnInitClass(void) {};
void CAirElemental_OnEndClass(void) {};
void CAirElemental_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CAirElemental_OnWorldEnd(CWorld *pwo) {};
void CAirElemental_OnWorldInit(CWorld *pwo) {};
void CAirElemental_OnWorldTick(CWorld *pwo) {};
void CAirElemental_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CAirElemental, CEnemyBase, "AirElemental", "Thumbnails\\AirElemental.tbn", 0x0000015b);
DECLARE_CTFILENAME(_fnmCAirElemental_tbn, "Thumbnails\\AirElemental.tbn");
