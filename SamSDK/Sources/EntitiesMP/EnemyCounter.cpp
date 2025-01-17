/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"

#include "StdH.h"
#include <EntitiesMP/MusicHolder.h>

#include <EntitiesMP/EnemyCounter.h>
#include <EntitiesMP/EnemyCounter_tables.h>
void CEnemyCounter::SetDefaultProperties(void) {
  m_penMainMusicHolder = NULL;
  m_strName = "";
  m_iCountFrom = 100;
  m_iCount = -1;
  CRationalEntity::SetDefaultProperties();
}
  
#line 24 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
class CMusicHolder * CEnemyCounter::GetMusicHolder() 
#line 25 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
{
#line 26 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
if(m_penMainMusicHolder  == NULL ){
#line 27 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
m_penMainMusicHolder  = _pNetwork  -> GetEntityWithName  ("MusicHolder" , 0);
#line 28 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}
#line 29 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
return (CMusicHolder  *) & * m_penMainMusicHolder ;
#line 30 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}
  
#line 31 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
void CEnemyCounter::StartCounting(void) 
#line 32 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
{
#line 33 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
CMusicHolder  * pmh  = GetMusicHolder  ();
#line 34 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
if(pmh  == NULL ){
#line 35 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
return ;
#line 36 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}
#line 37 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
pmh  -> m_penCounter  = this ;
#line 38 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
m_iCount  = m_iCountFrom ;
#line 39 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}
  
#line 40 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
void CEnemyCounter::CountOne(void) 
#line 41 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
{
#line 42 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
if(m_iCount  > 0){
#line 43 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
m_iCount  -= 1;
#line 44 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}
#line 45 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}
  
#line 46 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
void CEnemyCounter::StopCounting(void) 
#line 47 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
{
#line 48 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
CMusicHolder  * pmh  = GetMusicHolder  ();
#line 49 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
if(pmh  == NULL ){
#line 50 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
return ;
#line 51 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}
#line 52 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
m_iCount  = 0;
#line 53 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
pmh  -> m_penCounter  = NULL ;
#line 54 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}
BOOL CEnemyCounter::
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnemyCounter_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnemyCounter::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
InitAsEditorModel  ();
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
SetModel  (MODEL_MARKER );
#line 68 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 70 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x01530000, FALSE, EBegin());return TRUE;}BOOL CEnemyCounter::H0x01530000_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01530000
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01530001, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CEnemyCounter::H0x01530001_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01530001
;
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x01530002, FALSE, EBegin());return TRUE;}BOOL CEnemyCounter::H0x01530002_Main_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01530002
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 74 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
return TRUE;
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStart):{const EStart&e= (EStart&)__eeInput;

#line 78 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
StartCounting  ();
#line 79 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
return TRUE;
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStop):{const EStop&e= (EStop&)__eeInput;

#line 83 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
StopCounting  ();
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
return TRUE;
#line 85 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETrigger):{const ETrigger&e= (ETrigger&)__eeInput;

#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
if(m_iCount  == - 1){
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
StartCounting  ();
#line 92 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}
#line 93 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
CountOne  ();
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
if(m_iCount  == 0){
#line 97 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
StopCounting  ();
#line 98 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
return TRUE;
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
}return TRUE;}BOOL CEnemyCounter::H0x01530003_Main_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01530003

#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
Return(STATE_CURRENT,EVoid());
#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyCounter.es"
return TRUE; ASSERT(FALSE); return TRUE;};