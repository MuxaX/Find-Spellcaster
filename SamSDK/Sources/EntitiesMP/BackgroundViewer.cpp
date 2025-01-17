/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"

#include "StdH.h"

#include <EntitiesMP/BackgroundViewer.h>
#include <EntitiesMP/BackgroundViewer_tables.h>
void CBackgroundViewer::SetDefaultProperties(void) {
  m_bActive = TRUE ;
  m_penWorldSettingsController = NULL;
  CMarker::SetDefaultProperties();
}
  
#line 23 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
BOOL CBackgroundViewer::IsTargetValid(SLONG slPropertyOffset,CEntity * penTarget) 
#line 24 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
{
#line 25 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
if(penTarget  == NULL )
#line 26 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
{
#line 27 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
return FALSE ;
#line 28 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
}
#line 30 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
if(slPropertyOffset  == offsetof  (CBackgroundViewer  , m_penWorldSettingsController ))
#line 31 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
{
#line 32 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
return IsOfClass  (penTarget  , "WorldSettingsController");
#line 33 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
}
#line 34 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
return TRUE ;
#line 35 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
}
  
#line 37 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
BOOL CBackgroundViewer::HandleEvent(const CEntityEvent & ee) {
#line 38 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
if(ee  . ee_slEvent  == EVENTCODE_EStart ){
#line 39 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
GetWorld  () -> SetBackgroundViewer  (this );
#line 40 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
return TRUE ;
#line 41 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
}
#line 43 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
return FALSE ;
#line 44 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
}
BOOL CBackgroundViewer::
#line 47 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBackgroundViewer_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBackgroundViewer::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 49 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
InitAsEditorModel  ();
#line 50 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 51 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 54 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
SetModel  (MODEL_MARKER );
#line 55 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 58 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
if(m_strName  == "Marker"){
#line 59 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
m_strName  = "Background Viewer";
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
}
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
if(m_bActive ){
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
GetWorld  () -> SetBackgroundViewer  (this );
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
}
#line 65 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
Return(STATE_CURRENT,EVoid());
#line 65 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
return TRUE; ASSERT(FALSE); return TRUE;};