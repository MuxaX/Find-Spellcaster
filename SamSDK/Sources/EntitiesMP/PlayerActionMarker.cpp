/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"

#include "StdH.h"

#include <EntitiesMP/PlayerActionMarker.h>
#include <EntitiesMP/PlayerActionMarker_tables.h>
void CPlayerActionMarker::SetDefaultProperties(void) {
  m_paaAction = PAA_RUN ;
  m_tmWait = 0.0f;
  m_penDoorController = NULL;
  m_penTrigger = NULL;
  m_fSpeed = 1.0f;
  m_penItem = NULL;
  CMarker::SetDefaultProperties();
}
  
#line 57 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
const CTString & CPlayerActionMarker::GetDescription(void)const {
#line 58 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
CTString strAction  = PlayerAutoAction_enum  . NameForValue  (INDEX (m_paaAction ));
#line 59 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
if(m_penTarget  == NULL ){
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
((CTString &) m_strDescription ) . PrintF  ("%s (%s)-><none>" , m_strName  , strAction );
#line 61 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
}else {
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
((CTString &) m_strDescription ) . PrintF  ("%s (%s)->%s" , m_strName  , strAction  , 
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
m_penTarget  -> GetName  ());
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
}
#line 65 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
return m_strDescription ;
#line 66 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
}
  
#line 69 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
BOOL CPlayerActionMarker::DropsMarker(CTFileName & fnmMarkerClass,CTString & strTargetProperty)const {
#line 70 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
fnmMarkerClass  = CTFILENAME  ("Classes\\PlayerActionMarker.ecl");
#line 71 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
strTargetProperty  = "Target";
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
return TRUE ;
#line 73 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
}
  
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
BOOL CPlayerActionMarker::HandleEvent(const CEntityEvent & ee) 
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
{
#line 79 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
if(ee  . ee_slEvent  == EVENTCODE_ETrigger ){
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
ETrigger  & eTrigger  = (ETrigger  &) ee ;
#line 82 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
if(IsDerivedFromClass  (eTrigger  . penCaused  , "Player")){
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
EAutoAction  eAutoAction ;
#line 85 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
eAutoAction  . penFirstMarker  = this ;
#line 86 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
eTrigger  . penCaused  -> SendEvent  (eAutoAction );
#line 87 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
}
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
return TRUE ;
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
}
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
return FALSE ;
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
}
BOOL CPlayerActionMarker::
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CPlayerActionMarker_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CPlayerActionMarker::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 97 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
InitAsEditorModel  ();
#line 98 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 102 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
SetModel  (MODEL_MARKER );
#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
m_tmWait  = ClampDn  (m_tmWait  , 0.05f);
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
Return(STATE_CURRENT,EVoid());
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerActionMarker.es"
return TRUE; ASSERT(FALSE); return TRUE;};