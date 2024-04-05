/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CShipMarker

CEntityProperty CShipMarker_properties[] = {
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x00000068<<8)+1, offsetof(CShipMarker, m_bHarbor), "Harbor", 'H', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000068<<8)+2, offsetof(CShipMarker, m_fSpeed), "Speed [m/s]", 'S', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000068<<8)+3, offsetof(CShipMarker, m_fRotation), "Rotation [deg/s]", 'R', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000068<<8)+4, offsetof(CShipMarker, m_fAcceleration), "Acceleration", 'C', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000068<<8)+5, offsetof(CShipMarker, m_fRockingV), "Rocking V", 'V', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000068<<8)+6, offsetof(CShipMarker, m_fRockingA), "Rocking A", 'A', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000068<<8)+7, offsetof(CShipMarker, m_tmRockingChange), "Rocking Change Time", 0, 0x7F0000FFUL, 0),
};
#define CShipMarker_propertiesct ARRAYCOUNT(CShipMarker_properties)

CEntityComponent CShipMarker_components[] = {
#define MODEL_MARKER ((0x00000068<<8)+1)
 CEntityComponent(ECT_MODEL, MODEL_MARKER, "EFNM" "Models\\Editor\\ShipMarker.mdl"),
#define TEXTURE_MARKER ((0x00000068<<8)+2)
 CEntityComponent(ECT_TEXTURE, TEXTURE_MARKER, "EFNM" "Models\\Editor\\ShipMarker.tex"),
};
#define CShipMarker_componentsct ARRAYCOUNT(CShipMarker_components)

CEventHandlerEntry CShipMarker_handlers[] = {
 {1, -1, CEntity::pEventHandler(&CShipMarker::
#line 33 "V:/Programs/SamSDK/Sources/EntitiesMP/ShipMarker.es"
Main),DEBUGSTRING("CShipMarker::Main")},
};
#define CShipMarker_handlersct ARRAYCOUNT(CShipMarker_handlers)

CEntity *CShipMarker_New(void) { return new CShipMarker; };
void CShipMarker_OnInitClass(void) {};
void CShipMarker_OnEndClass(void) {};
void CShipMarker_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CShipMarker_OnWorldEnd(CWorld *pwo) {};
void CShipMarker_OnWorldInit(CWorld *pwo) {};
void CShipMarker_OnWorldTick(CWorld *pwo) {};
void CShipMarker_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CShipMarker, CMarker, "Ship Marker", "Thumbnails\\ShipMarker.tbn", 0x00000068);
DECLARE_CTFILENAME(_fnmCShipMarker_tbn, "Thumbnails\\ShipMarker.tbn");
