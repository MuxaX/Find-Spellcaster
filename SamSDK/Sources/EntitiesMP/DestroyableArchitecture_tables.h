/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CDestroyableArchitecture

CEntityProperty CDestroyableArchitecture_properties[] = {
 CEntityProperty(CEntityProperty::EPT_STRING, NULL, (0x0000006b<<8)+1, offsetof(CDestroyableArchitecture, m_strName), "Name", 'N', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000006b<<8)+2, offsetof(CDestroyableArchitecture, m_fHealth), "Health", 'H', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENUM, &EffectorEffectType_enum, (0x0000006b<<8)+3, offsetof(CDestroyableArchitecture, m_etType), "Type", 'Y', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT3D, NULL, (0x0000006b<<8)+4, offsetof(CDestroyableArchitecture, m_vDamageDir), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000006b<<8)+5, offsetof(CDestroyableArchitecture, m_fStretch), "Stretch", 'S', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000006b<<8)+6, offsetof(CDestroyableArchitecture, m_penGradient), "Gradient", 'R', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x0000006b<<8)+10, offsetof(CDestroyableArchitecture, m_colDebrises), "Color of debrises", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x0000006b<<8)+11, offsetof(CDestroyableArchitecture, m_ctDebrises), "Debris count", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000006b<<8)+12, offsetof(CDestroyableArchitecture, m_fCandyEffect), "Debris blow power", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000006b<<8)+13, offsetof(CDestroyableArchitecture, m_fCubeFactor), "Cube factor", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x0000006b<<8)+14, offsetof(CDestroyableArchitecture, m_bBlowupByDamager), "Blowup by Damager", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000006b<<8)+15, offsetof(CDestroyableArchitecture, m_fDustStretch), "Dust stretch", 0, 0x7F0000FFUL, 0),
};
#define CDestroyableArchitecture_propertiesct ARRAYCOUNT(CDestroyableArchitecture_properties)

CEntityComponent CDestroyableArchitecture_components[] = {
#define TEXTURE_OBELISK ((0x0000006b<<8)+10)
 CEntityComponent(ECT_TEXTURE, TEXTURE_OBELISK, "EFNM" "Models\\CutSequences\\Obelisk\\Obelisk.tex"),
#define MODEL_OBELISK01 ((0x0000006b<<8)+11)
 CEntityComponent(ECT_MODEL, MODEL_OBELISK01, "EFNM" "Models\\CutSequences\\Obelisk\\Part01.mdl"),
#define MODEL_OBELISK02 ((0x0000006b<<8)+12)
 CEntityComponent(ECT_MODEL, MODEL_OBELISK02, "EFNM" "Models\\CutSequences\\Obelisk\\Part02.mdl"),
#define MODEL_OBELISK03 ((0x0000006b<<8)+13)
 CEntityComponent(ECT_MODEL, MODEL_OBELISK03, "EFNM" "Models\\CutSequences\\Obelisk\\Part03.mdl"),
#define MODEL_OBELISK04 ((0x0000006b<<8)+14)
 CEntityComponent(ECT_MODEL, MODEL_OBELISK04, "EFNM" "Models\\CutSequences\\Obelisk\\Part04.mdl"),
#define MODEL_OBELISK05 ((0x0000006b<<8)+15)
 CEntityComponent(ECT_MODEL, MODEL_OBELISK05, "EFNM" "Models\\CutSequences\\Obelisk\\Part05.mdl"),
#define MODEL_OBELISK06 ((0x0000006b<<8)+16)
 CEntityComponent(ECT_MODEL, MODEL_OBELISK06, "EFNM" "Models\\CutSequences\\Obelisk\\Part06.mdl"),
#define MODEL_OBELISK07 ((0x0000006b<<8)+17)
 CEntityComponent(ECT_MODEL, MODEL_OBELISK07, "EFNM" "Models\\CutSequences\\Obelisk\\Part07.mdl"),
#define MODEL_OBELISK08 ((0x0000006b<<8)+18)
 CEntityComponent(ECT_MODEL, MODEL_OBELISK08, "EFNM" "Models\\CutSequences\\Obelisk\\Part08.mdl"),
#define MODEL_OBELISK09 ((0x0000006b<<8)+19)
 CEntityComponent(ECT_MODEL, MODEL_OBELISK09, "EFNM" "Models\\CutSequences\\Obelisk\\Part09.mdl"),
#define TEXTURE_PYLON ((0x0000006b<<8)+20)
 CEntityComponent(ECT_TEXTURE, TEXTURE_PYLON, "EFNM" "Models\\CutSequences\\Pylon\\Pylon.tex"),
#define MODEL_PYLON01 ((0x0000006b<<8)+21)
 CEntityComponent(ECT_MODEL, MODEL_PYLON01, "EFNM" "Models\\CutSequences\\Pylon\\Part01.mdl"),
#define MODEL_PYLON02 ((0x0000006b<<8)+22)
 CEntityComponent(ECT_MODEL, MODEL_PYLON02, "EFNM" "Models\\CutSequences\\Pylon\\Part02.mdl"),
#define MODEL_PYLON03 ((0x0000006b<<8)+23)
 CEntityComponent(ECT_MODEL, MODEL_PYLON03, "EFNM" "Models\\CutSequences\\Pylon\\Part03.mdl"),
#define MODEL_PYLON04 ((0x0000006b<<8)+24)
 CEntityComponent(ECT_MODEL, MODEL_PYLON04, "EFNM" "Models\\CutSequences\\Pylon\\Part04.mdl"),
#define MODEL_PYLON05 ((0x0000006b<<8)+25)
 CEntityComponent(ECT_MODEL, MODEL_PYLON05, "EFNM" "Models\\CutSequences\\Pylon\\Part05.mdl"),
#define MODEL_PYLON06 ((0x0000006b<<8)+26)
 CEntityComponent(ECT_MODEL, MODEL_PYLON06, "EFNM" "Models\\CutSequences\\Pylon\\Part06.mdl"),
#define MODEL_PYLON07 ((0x0000006b<<8)+27)
 CEntityComponent(ECT_MODEL, MODEL_PYLON07, "EFNM" "Models\\CutSequences\\Pylon\\Part07.mdl"),
#define MODEL_PYLON08 ((0x0000006b<<8)+28)
 CEntityComponent(ECT_MODEL, MODEL_PYLON08, "EFNM" "Models\\CutSequences\\Pylon\\Part08.mdl"),
#define MODEL_PYLON09 ((0x0000006b<<8)+29)
 CEntityComponent(ECT_MODEL, MODEL_PYLON09, "EFNM" "Models\\CutSequences\\Pylon\\Part09.mdl"),
#define CLASS_DEBRIS ((0x0000006b<<8)+30)
 CEntityComponent(ECT_CLASS, CLASS_DEBRIS, "EFNM" "Classes\\Debris.ecl"),
#define CLASS_EFFECTOR ((0x0000006b<<8)+31)
 CEntityComponent(ECT_CLASS, CLASS_EFFECTOR, "EFNM" "Classes\\Effector.ecl"),
#define MODEL_STONE ((0x0000006b<<8)+32)
 CEntityComponent(ECT_MODEL, MODEL_STONE, "EFNM" "Models\\Effects\\Debris\\Stone\\Stone.mdl"),
#define TEXTURE_STONE ((0x0000006b<<8)+33)
 CEntityComponent(ECT_TEXTURE, TEXTURE_STONE, "EFNM" "Models\\Effects\\Debris\\Stone\\Stone.tex"),
};
#define CDestroyableArchitecture_componentsct ARRAYCOUNT(CDestroyableArchitecture_components)

CEventHandlerEntry CDestroyableArchitecture_handlers[] = {
 {1, -1, CEntity::pEventHandler(&CDestroyableArchitecture::
#line 369 "V:/Programs/SamSDK/Sources/EntitiesMP/DestroyableArchitecture.es"
Main),DEBUGSTRING("CDestroyableArchitecture::Main")},
 {0x006b0000, -1, CEntity::pEventHandler(&CDestroyableArchitecture::H0x006b0000_Main_01), DEBUGSTRING("CDestroyableArchitecture::H0x006b0000_Main_01")},
 {0x006b0001, -1, CEntity::pEventHandler(&CDestroyableArchitecture::H0x006b0001_Main_02), DEBUGSTRING("CDestroyableArchitecture::H0x006b0001_Main_02")},
};
#define CDestroyableArchitecture_handlersct ARRAYCOUNT(CDestroyableArchitecture_handlers)

CEntity *CDestroyableArchitecture_New(void) { return new CDestroyableArchitecture; };
void CDestroyableArchitecture_OnInitClass(void) {};
void CDestroyableArchitecture_OnEndClass(void) {};
void CDestroyableArchitecture_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CDestroyableArchitecture_OnWorldEnd(CWorld *pwo) {};
void CDestroyableArchitecture_OnWorldInit(CWorld *pwo) {};
void CDestroyableArchitecture_OnWorldTick(CWorld *pwo) {};
void CDestroyableArchitecture_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CDestroyableArchitecture, CMovableBrushEntity, "DestroyableArchitecture", "Thumbnails\\DestroyableArchitecture.tbn", 0x0000006b);
DECLARE_CTFILENAME(_fnmCDestroyableArchitecture_tbn, "Thumbnails\\DestroyableArchitecture.tbn");