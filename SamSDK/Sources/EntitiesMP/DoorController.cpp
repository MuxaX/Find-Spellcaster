/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"

#include "StdH.h"
#include <Engine/CurrentVersion.h>

#include <EntitiesMP/DoorController.h>
#include <EntitiesMP/DoorController_tables.h>
void CDoorController::SetDefaultProperties(void) {
  m_strName = "DoorController";
  m_strDescription = "";
  m_penTarget1 = NULL;
  m_penTarget2 = NULL;
  m_fWidth = 2.0f;
  m_fHeight = 3.0f;
  m_bPlayersOnly = TRUE ;
  m_dtType = DT_AUTO ;
  m_strLockedMessage = "";
  m_penLockedTarget = NULL;
  m_kitKey = KIT_BOOKOFWISDOM ;
  m_bTriggerOnAnything = FALSE ;
  m_bActive = TRUE ;
  m_bLocked = FALSE ;
  m_penCaused = NULL;
  CRationalEntity::SetDefaultProperties();
}
  
#line 51 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
CEntity * CDoorController::GetTarget(void)const {return m_penTarget1 ;}
  
#line 53 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
const CTString & CDoorController::GetDescription(void)const 
#line 54 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
{
#line 55 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(m_penTarget1  != NULL  && m_penTarget2  != NULL ){
#line 56 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
((CTString &) m_strDescription ) . PrintF  ("->%s,%s" , 
#line 57 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
m_penTarget1  -> GetName  () , m_penTarget2  -> GetName  ());
#line 58 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}else if(m_penTarget1  != NULL ){
#line 59 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
((CTString &) m_strDescription ) . PrintF  ("->%s" , 
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
m_penTarget1  -> GetName  ());
#line 61 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}else {
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
((CTString &) m_strDescription ) . PrintF  ("-><none>");
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return m_strDescription ;
#line 65 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
  
#line 68 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
BOOL CDoorController::CanReactOnEntity(CEntity * pen) 
#line 69 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
{
#line 70 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(pen  == NULL ){
#line 71 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return FALSE ;
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 74 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(! (pen  -> GetFlags  () & ENF_ALIVE )){
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return FALSE ;
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 78 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(m_bPlayersOnly  && ! IsDerivedFromClass  (pen  , "Player")){
#line 79 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return FALSE ;
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 82 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE ;
#line 83 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
  
#line 86 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
BOOL CDoorController::CanTriggerOnEntity(CEntity * pen) 
#line 87 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
{
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return m_bTriggerOnAnything  || CanReactOnEntity  (pen );
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
  
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
void CDoorController::TriggerDoor(void) 
#line 92 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
{
#line 93 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(m_penTarget1  != NULL ){
#line 94 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SendToTarget  (m_penTarget1  , EET_TRIGGER  , m_penCaused );
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(m_penTarget2  != NULL ){
#line 97 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SendToTarget  (m_penTarget2  , EET_TRIGGER  , m_penCaused );
#line 98 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
  
#line 102 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
void CDoorController::MirrorAndStretch(FLOAT fStretch,BOOL bMirrorX) 
#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
{
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
m_fWidth  *= fStretch ;
#line 106 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
m_fHeight  *= fStretch ;
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
  
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SLONG CDoorController::GetUsedMemory(void) 
#line 112 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
{
#line 114 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SLONG  slUsedMemory  = sizeof  (CDoorController ) - sizeof  (CRationalEntity ) + CRationalEntity  :: GetUsedMemory  ();
#line 116 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
slUsedMemory  += m_strDescription  . Length  ();
#line 117 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
slUsedMemory  += m_strName  . Length  ();
#line 118 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
slUsedMemory  += m_strLockedMessage  . Length  ();
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return slUsedMemory ;
#line 120 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
BOOL CDoorController::
#line 126 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
DoorAuto(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDoorController_DoorAuto
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CDoorController::DoorAuto expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 129 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(m_bActive ){
#line 130 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT, STATE_CDoorController_DoorAutoActive, TRUE, EVoid());return TRUE;
#line 131 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}else {
#line 132 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT, STATE_CDoorController_DoorAutoInactive, TRUE, EVoid());return TRUE;
#line 133 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
} ASSERT(FALSE); return TRUE;};BOOL CDoorController::
#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
DoorAutoActive(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDoorController_DoorAutoActive
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CDoorController::DoorAutoActive expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 139 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
ASSERT  (m_bActive );
#line 140 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT,0x00dd0006, FALSE, EInternal());return TRUE;}BOOL CDoorController::H0x00dd0006_DoorAutoActive_05(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0006
if(!(TRUE )){ Jump(STATE_CURRENT,0x00dd0007, FALSE, EInternal());return TRUE;}
#line 142 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x00dd0002, FALSE, EBegin());return TRUE;}BOOL CDoorController::H0x00dd0002_DoorAutoActive_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0002
switch(__eeInput.ee_slEvent){case(EVENTCODE_EPass):{const EPass&ePass= (EPass&)__eeInput;

#line 146 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(CanReactOnEntity  (ePass  . penOther )){
#line 148 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
m_penCaused  = ePass  . penOther ;
#line 149 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
TriggerDoor  ();
#line 153 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(_SE_DEMO  && GetSP  () -> sp_bCooperative  && ! GetSP  () -> sp_bSinglePlayer ){
#line 154 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(m_strName  == "Appear gold amon"){
#line 155 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
CPlayer  * penPlayer  = (CPlayer  *) & * ePass  . penOther ;
#line 156 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
penPlayer  -> SetGameEnd  ();
#line 157 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 158 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 160 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE;
#line 161 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 162 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE;
#line 163 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;case(EVENTCODE_EDeactivate):{const EDeactivate&e= (EDeactivate&)__eeInput;

#line 167 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
m_bActive  = FALSE ;
#line 168 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT, STATE_CDoorController_DoorAutoInactive, TRUE, EVoid());return TRUE;
#line 169 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;default:{
#line 171 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE;
#line 172 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;
#line 173 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}return TRUE;}BOOL CDoorController::H0x00dd0003_DoorAutoActive_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0003
;
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x00dd0004, FALSE, EBegin());return TRUE;}BOOL CDoorController::H0x00dd0004_DoorAutoActive_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0004
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00dd0005, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CDoorController::H0x00dd0005_DoorAutoActive_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0005
;Jump(STATE_CURRENT,0x00dd0006, FALSE, EInternal());return TRUE;
#line 177 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}BOOL CDoorController::H0x00dd0007_DoorAutoActive_06(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0007
 ASSERT(FALSE); return TRUE;};BOOL CDoorController::
#line 181 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
DoorAutoInactive(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDoorController_DoorAutoInactive
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CDoorController::DoorAutoInactive expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 183 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
ASSERT  (! m_bActive );
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT,0x00dd000d, FALSE, EInternal());return TRUE;}BOOL CDoorController::H0x00dd000d_DoorAutoInactive_05(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd000d
if(!(TRUE )){ Jump(STATE_CURRENT,0x00dd000e, FALSE, EInternal());return TRUE;}
#line 186 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x00dd0009, FALSE, EBegin());return TRUE;}BOOL CDoorController::H0x00dd0009_DoorAutoInactive_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0009
switch(__eeInput.ee_slEvent){case(EVENTCODE_EActivate):{const EActivate&e= (EActivate&)__eeInput;

#line 190 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
m_bActive  = TRUE ;
#line 191 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT, STATE_CDoorController_DoorAutoActive, TRUE, EVoid());return TRUE;
#line 192 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;default:{
#line 194 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE;
#line 195 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;
#line 196 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}return TRUE;}BOOL CDoorController::H0x00dd000a_DoorAutoInactive_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd000a
;
#line 199 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x00dd000b, FALSE, EBegin());return TRUE;}BOOL CDoorController::H0x00dd000b_DoorAutoInactive_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd000b
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00dd000c, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CDoorController::H0x00dd000c_DoorAutoInactive_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd000c
;Jump(STATE_CURRENT,0x00dd000d, FALSE, EInternal());return TRUE;
#line 200 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}BOOL CDoorController::H0x00dd000e_DoorAutoInactive_06(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd000e
 ASSERT(FALSE); return TRUE;};BOOL CDoorController::
#line 204 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
DoorDummy(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDoorController_DoorDummy
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CDoorController::DoorDummy expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 206 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x00dd0010, FALSE, EBegin());return TRUE;}BOOL CDoorController::H0x00dd0010_DoorDummy_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0010
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 208 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE;
#line 209 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;default:{
#line 211 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE;
#line 212 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;
#line 213 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}return TRUE;}BOOL CDoorController::H0x00dd0011_DoorDummy_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0011
 ASSERT(FALSE); return TRUE;};BOOL CDoorController::
#line 217 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
DoorTriggered(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDoorController_DoorTriggered
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CDoorController::DoorTriggered expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 219 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT,0x00dd0017, FALSE, EInternal());return TRUE;}BOOL CDoorController::H0x00dd0017_DoorTriggered_05(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0017
if(!(TRUE )){ Jump(STATE_CURRENT,0x00dd0018, FALSE, EInternal());return TRUE;}
#line 221 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x00dd0013, FALSE, EBegin());return TRUE;}BOOL CDoorController::H0x00dd0013_DoorTriggered_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0013
switch(__eeInput.ee_slEvent){case(EVENTCODE_EPass):{const EPass&ePass= (EPass&)__eeInput;

#line 223 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(CanReactOnEntity  (ePass  . penOther )){
#line 224 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(m_strLockedMessage  != ""){
#line 225 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
PrintCenterMessage  (this  , ePass  . penOther  , TranslateConst  (m_strLockedMessage ) , 3.0f , MSS_INFO );
#line 226 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 227 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(m_penLockedTarget  != NULL ){
#line 228 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SendToTarget  (m_penLockedTarget  , EET_TRIGGER  , ePass  . penOther );
#line 229 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 230 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE;
#line 231 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 232 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETrigger):{const ETrigger&eTrigger= (ETrigger&)__eeInput;

#line 234 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
m_penCaused  = eTrigger  . penCaused ;
#line 235 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
TriggerDoor  ();
#line 236 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT, STATE_CDoorController_DoorDummy, TRUE, EVoid());return TRUE;
#line 237 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;default:{
#line 239 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE;
#line 240 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;
#line 241 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}return TRUE;}BOOL CDoorController::H0x00dd0014_DoorTriggered_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0014
;
#line 244 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x00dd0015, FALSE, EBegin());return TRUE;}BOOL CDoorController::H0x00dd0015_DoorTriggered_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0015
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00dd0016, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CDoorController::H0x00dd0016_DoorTriggered_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0016
;Jump(STATE_CURRENT,0x00dd0017, FALSE, EInternal());return TRUE;
#line 245 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}BOOL CDoorController::H0x00dd0018_DoorTriggered_06(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0018
 ASSERT(FALSE); return TRUE;};BOOL CDoorController::
#line 249 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
DoorLocked(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDoorController_DoorLocked
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CDoorController::DoorLocked expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 251 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT,0x00dd001e, FALSE, EInternal());return TRUE;}BOOL CDoorController::H0x00dd001e_DoorLocked_05(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd001e
if(!(TRUE )){ Jump(STATE_CURRENT,0x00dd001f, FALSE, EInternal());return TRUE;}
#line 253 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x00dd001a, FALSE, EBegin());return TRUE;}BOOL CDoorController::H0x00dd001a_DoorLocked_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd001a
switch(__eeInput.ee_slEvent){case(EVENTCODE_EPass):{const EPass&ePass= (EPass&)__eeInput;

#line 255 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(IsDerivedFromClass  (ePass  . penOther  , "Player")){
#line 256 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
CPlayer  * penPlayer  = (CPlayer  *) & * ePass  . penOther ;
#line 258 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
ULONG  ulKey  = (1 << INDEX (m_kitKey ));
#line 259 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(penPlayer  -> m_ulKeys  & ulKey ){
#line 261 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
penPlayer  -> m_ulKeys  &= ~ ulKey ;
#line 263 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
TriggerDoor  ();
#line 272 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT, STATE_CDoorController_DoorAuto, TRUE, EVoid());return TRUE;
#line 274 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}else {
#line 275 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(m_penLockedTarget  != NULL ){
#line 276 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SendToTarget  (m_penLockedTarget  , EET_TRIGGER  , ePass  . penOther );
#line 277 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 278 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 279 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE;
#line 280 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 281 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;default:{
#line 283 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE;
#line 284 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;
#line 285 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}return TRUE;}BOOL CDoorController::H0x00dd001b_DoorLocked_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd001b
;
#line 288 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x00dd001c, FALSE, EBegin());return TRUE;}BOOL CDoorController::H0x00dd001c_DoorLocked_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd001c
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00dd001d, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CDoorController::H0x00dd001d_DoorLocked_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd001d
;Jump(STATE_CURRENT,0x00dd001e, FALSE, EInternal());return TRUE;
#line 289 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}BOOL CDoorController::H0x00dd001f_DoorLocked_06(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd001f
 ASSERT(FALSE); return TRUE;};BOOL CDoorController::
#line 293 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
DoorTriggeredAuto(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDoorController_DoorTriggeredAuto
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CDoorController::DoorTriggeredAuto expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 295 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT,0x00dd0025, FALSE, EInternal());return TRUE;}BOOL CDoorController::H0x00dd0025_DoorTriggeredAuto_05(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0025
if(!(TRUE )){ Jump(STATE_CURRENT,0x00dd0026, FALSE, EInternal());return TRUE;}
#line 297 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x00dd0021, FALSE, EBegin());return TRUE;}BOOL CDoorController::H0x00dd0021_DoorTriggeredAuto_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0021
switch(__eeInput.ee_slEvent){case(EVENTCODE_ETrigger):{const ETrigger&eTrigger= (ETrigger&)__eeInput;

#line 300 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT, STATE_CDoorController_DoorAuto, TRUE, EVoid());return TRUE;
#line 301 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;case(EVENTCODE_EPass):{const EPass&ePass= (EPass&)__eeInput;

#line 303 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(CanReactOnEntity  (ePass  . penOther )){
#line 304 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(m_strLockedMessage  != ""){
#line 305 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
PrintCenterMessage  (this  , ePass  . penOther  , TranslateConst  (m_strLockedMessage ) , 3.0f , MSS_INFO );
#line 306 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 307 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
if(m_penLockedTarget  != NULL ){
#line 308 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SendToTarget  (m_penLockedTarget  , EET_TRIGGER  , ePass  . penOther );
#line 309 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 310 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}
#line 311 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE;
#line 312 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;default:{
#line 314 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
return TRUE;
#line 315 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}ASSERT(FALSE);break;
#line 316 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}return TRUE;}BOOL CDoorController::H0x00dd0022_DoorTriggeredAuto_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0022
;
#line 319 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x00dd0023, FALSE, EBegin());return TRUE;}BOOL CDoorController::H0x00dd0023_DoorTriggeredAuto_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0023
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00dd0024, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CDoorController::H0x00dd0024_DoorTriggeredAuto_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0024
;Jump(STATE_CURRENT,0x00dd0025, FALSE, EInternal());return TRUE;
#line 320 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}BOOL CDoorController::H0x00dd0026_DoorTriggeredAuto_06(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0026
 ASSERT(FALSE); return TRUE;};BOOL CDoorController::
#line 323 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDoorController_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CDoorController::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 325 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
InitAsEditorModel  ();
#line 326 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 327 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetCollisionFlags  (ECF_TOUCHMODEL );
#line 330 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
GetModelObject  () -> StretchModel  (FLOAT3D (m_fWidth  , m_fHeight  , m_fWidth ));
#line 331 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetModel  (MODEL_DOORCONTROLLER );
#line 332 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetModelMainTexture  (TEXTURE_DOORCONTROLLER );
#line 333 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
ModelChangeNotify  ();
#line 336 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x00dd0027, FALSE, EBegin());return TRUE;}BOOL CDoorController::H0x00dd0027_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0027
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00dd0028, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CDoorController::H0x00dd0028_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00dd0028
;
#line 339 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
switch(m_dtType ){
#line 340 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
case DT_AUTO : {
#line 341 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT, STATE_CDoorController_DoorAuto, TRUE, EVoid());return TRUE;
#line 342 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}break ;
#line 343 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
case DT_TRIGGERED : {
#line 344 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT, STATE_CDoorController_DoorTriggered, TRUE, EVoid());return TRUE;
#line 345 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}break ;
#line 346 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
case DT_TRIGGEREDAUTO : {
#line 347 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT, STATE_CDoorController_DoorTriggeredAuto, TRUE, EVoid());return TRUE;
#line 348 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}break ;
#line 349 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
case DT_LOCKED : {
#line 350 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
Jump(STATE_CURRENT, STATE_CDoorController_DoorLocked, TRUE, EVoid());return TRUE;
#line 351 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
}break ;
#line 352 "V:/Programs/SamSDK/Sources/EntitiesMP/DoorController.es"
} ASSERT(FALSE); return TRUE;};