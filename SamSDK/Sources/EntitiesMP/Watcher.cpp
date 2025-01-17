/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"

#include "StdH.h"

#include "EntitiesMP/EnemyBase.h"

#include <EntitiesMP/Watcher.h>
#include <EntitiesMP/Watcher_tables.h>
CEntityEvent *EWatcherInit::MakeCopy(void) { CEntityEvent *peeCopy = new EWatcherInit(*this); return peeCopy;}
EWatcherInit::EWatcherInit() : CEntityEvent(EVENTCODE_EWatcherInit) {;
 ClearToDefault(penOwner);
};
CEntityEvent *EWatch::MakeCopy(void) { CEntityEvent *peeCopy = new EWatch(*this); return peeCopy;}
EWatch::EWatch() : CEntityEvent(EVENTCODE_EWatch) {;
 ClearToDefault(penSeen);
};
void CWatcher::SetDefaultProperties(void) {
  m_penOwner = NULL;
  m_tmDelay = 5.0f;
  m_fClosestPlayer = UpperLimit(0.0f);
  m_iPlayerToCheck = 0;
  m_penPrediction = NULL;
  CRationalEntity::SetDefaultProperties();
}
  
#line 38 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
class CEnemyBase * CWatcher::GetOwner(void) 
#line 39 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
{
#line 40 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
ASSERT  (m_penOwner  != NULL );
#line 41 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return (CEnemyBase  *) & * m_penOwner ;
#line 42 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
  
#line 45 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
INDEX CWatcher::GetRandomPlayer(void) 
#line 46 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
{
#line 49 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
INDEX ctMaxPlayers  = GetMaxPlayers  ();
#line 51 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
INDEX ctActivePlayers  = 0;
#line 52 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
{for(INDEX i  = 0;i  < ctMaxPlayers ;i  ++){
#line 53 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(GetPlayerEntity  (i ) != NULL ){
#line 54 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
ctActivePlayers  ++;
#line 55 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 56 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}}
#line 59 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(ctActivePlayers  == 0){
#line 61 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return 0;
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 66 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
INDEX iChosenActivePlayer  = IRnd  () % ctActivePlayers ;
#line 70 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
INDEX iActivePlayer  = 0;
#line 71 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
{for(INDEX i  = 0;i  < ctMaxPlayers ;i  ++){
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(GetPlayerEntity  (i ) != NULL ){
#line 73 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(iActivePlayer  == iChosenActivePlayer ){
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return i ;
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
iActivePlayer  ++;
#line 78 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 79 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}}
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
ASSERT  (FALSE );
#line 81 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return 0;
#line 82 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
  
#line 85 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
CEntity * CWatcher::FindClosestPlayer(void) 
#line 86 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
{
#line 87 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
CEntity  * penClosestPlayer  = NULL ;
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fClosestPlayer  = UpperLimit  (0.0f);
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
for(INDEX iPlayer  = 0;iPlayer  < GetMaxPlayers  ();iPlayer  ++){
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
CEntity  * penPlayer  = GetPlayerEntity  (iPlayer );
#line 93 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(penPlayer  != NULL  && penPlayer  -> GetFlags  () & ENF_ALIVE  && ! (penPlayer  -> GetFlags  () & ENF_INVISIBLE )){
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fDistance  = 
#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
(penPlayer  -> GetPlacement  () . pl_PositionVector  - m_penOwner  -> GetPlacement  () . pl_PositionVector ) . Length  ();
#line 98 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(fDistance  < fClosestPlayer ){
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
fClosestPlayer  = fDistance ;
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
penClosestPlayer  = penPlayer ;
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 102 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(penClosestPlayer  == NULL ){
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
fClosestPlayer  = 10.0f;
#line 108 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 109 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
m_fClosestPlayer  = fClosestPlayer ;
#line 110 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return penClosestPlayer ;
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
  
#line 114 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
void CWatcher::SendWatchEvent(CEntity * penPlayer) 
#line 115 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
{
#line 116 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
EWatch  eWatch ;
#line 117 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
eWatch  . penSeen  = penPlayer ;
#line 118 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
m_penOwner  -> SendEvent  (eWatch );
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
  
#line 121 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
void CWatcher::CheckIfPlayerVisible(void) 
#line 122 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
{
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(GetOwner  () -> m_bBlind ){
#line 126 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return ;
#line 127 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 130 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
INDEX ctPlayers  = GetMaxPlayers  ();
#line 132 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
CEntity  * penPlayer  = NULL ;
#line 133 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
m_iPlayerToCheck  = (m_iPlayerToCheck  + 1) % ctPlayers ;
#line 134 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
INDEX iFirstChecked  = m_iPlayerToCheck ;
#line 135 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FOREVER {
#line 136 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
penPlayer  = GetPlayerEntity  (m_iPlayerToCheck );
#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(penPlayer  != NULL ){
#line 138 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
break ;
#line 139 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 140 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
m_iPlayerToCheck  ++;
#line 141 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
m_iPlayerToCheck  %= ctPlayers ;
#line 142 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(m_iPlayerToCheck  == iFirstChecked ){
#line 143 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return ;
#line 144 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 148 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(! (penPlayer  -> GetFlags  () & ENF_ALIVE ) || (penPlayer  -> GetFlags  () & ENF_INVISIBLE )){
#line 150 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return ;
#line 151 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 154 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(GetOwner  () -> SeeEntity  (penPlayer  , Cos  (GetOwner  () -> m_fViewAngle  / 2.0f))){
#line 156 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
SendWatchEvent  (penPlayer );
#line 157 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 158 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
  
#line 161 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
void CWatcher::SetWatchDelays(void) 
#line 162 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
{
#line 163 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
const FLOAT tmMinDelay  = 0.1f;
#line 164 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
const FLOAT tmSeeDelay  = 5.0f;
#line 165 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
const FLOAT tmTick  = _pTimer  -> TickQuantum ;
#line 166 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fSeeDistance  = GetOwner  () -> m_fIgnoreRange ;
#line 167 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fNearDistance  = Min  (GetOwner  () -> m_fStopDistance  , GetOwner  () -> m_fCloseDistance );
#line 170 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(m_fClosestPlayer  <= fNearDistance ){
#line 172 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
m_tmDelay  = tmMinDelay ;
#line 174 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}else {
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
m_tmDelay  = tmMinDelay  + 
#line 177 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
(m_fClosestPlayer  - fNearDistance ) * (tmSeeDelay  - tmMinDelay ) / (fSeeDistance  - fNearDistance );
#line 179 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
m_tmDelay  = floor  (m_tmDelay  / tmTick ) * tmTick ;
#line 180 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 181 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
  
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
void CWatcher::Watch(void) 
#line 185 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
{
#line 187 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fOrgDistance  = m_fClosestPlayer ;
#line 190 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
CEntity  * penClosest  = FindClosestPlayer  ();
#line 192 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fSeeDistance  = GetOwner  () -> m_fIgnoreRange ;
#line 193 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fStopDistance  = Max  (fSeeDistance  * 1.5f , GetOwner  () -> m_fActivityRange );
#line 196 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(fOrgDistance  < fStopDistance  && m_fClosestPlayer  >= fStopDistance ){
#line 198 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
m_penOwner  -> SendEvent  (EStop  ());
#line 200 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}else if(fOrgDistance  >= fStopDistance  && m_fClosestPlayer  < fStopDistance ){
#line 202 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
m_penOwner  -> SendEvent  (EStart  ());
#line 203 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 206 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(m_fClosestPlayer  < fSeeDistance ){
#line 208 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
CheckIfPlayerVisible  ();
#line 209 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 212 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fSenseRange  = GetOwner  () -> m_fSenseRange ;
#line 213 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(penClosest  != NULL  && fSenseRange  > 0 && m_fClosestPlayer  < fSenseRange ){
#line 215 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
SendWatchEvent  (penClosest );
#line 216 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 219 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
SetWatchDelays  ();
#line 220 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
  
#line 223 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
CEntity * CWatcher::CheckCloserPlayer(CEntity * penCurrentTarget,FLOAT fRange) 
#line 224 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
{
#line 226 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(GetOwner  () -> m_bBlind ){
#line 228 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return NULL ;
#line 229 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 231 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
CEntity  * penClosestPlayer  = NULL ;
#line 232 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fClosestPlayer  = 
#line 233 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
(penCurrentTarget  -> GetPlacement  () . pl_PositionVector  - m_penOwner  -> GetPlacement  () . pl_PositionVector ) . Length  ();
#line 234 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
fClosestPlayer  = Min  (fClosestPlayer  , fRange );
#line 237 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
for(INDEX iPlayer  = 0;iPlayer  < GetMaxPlayers  ();iPlayer  ++){
#line 238 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
CEntity  * penPlayer  = GetPlayerEntity  (iPlayer );
#line 239 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(penPlayer  == NULL  || penPlayer  == penCurrentTarget ){
#line 240 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
continue ;
#line 241 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 243 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if((penPlayer  -> GetFlags  () & ENF_ALIVE ) && ! (penPlayer  -> GetFlags  () & ENF_INVISIBLE )){
#line 245 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fDistance  = 
#line 246 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
(penPlayer  -> GetPlacement  () . pl_PositionVector  - m_penOwner  -> GetPlacement  () . pl_PositionVector ) . Length  ();
#line 248 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(fDistance  < fClosestPlayer  && 
#line 249 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
GetOwner  () -> SeeEntity  (penPlayer  , Cos  (GetOwner  () -> m_fViewAngle  / 2.0f))){
#line 251 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
fClosestPlayer  = fDistance ;
#line 252 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
penClosestPlayer  = penPlayer ;
#line 253 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 254 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 255 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 257 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return penClosestPlayer ;
#line 258 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
  
#line 261 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
CEntity * CWatcher::CheckAnotherPlayer(CEntity * penCurrentTarget) 
#line 262 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
{
#line 264 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(GetOwner  () -> m_bBlind  || penCurrentTarget  == NULL ){
#line 266 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return NULL ;
#line 267 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 270 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
CEntity  * penClosestPlayer  = NULL ;
#line 271 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fCurrentDistance  = 
#line 272 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
(penCurrentTarget  -> GetPlacement  () . pl_PositionVector  - m_penOwner  -> GetPlacement  () . pl_PositionVector ) . Length  ();
#line 273 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fRange  = fCurrentDistance  * 1.5f;
#line 276 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
INDEX iOffset  = GetRandomPlayer  ();
#line 279 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
INDEX ctPlayers  = GetMaxPlayers  ();
#line 280 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
for(INDEX iPlayer  = 0;iPlayer  < ctPlayers ;iPlayer  ++){
#line 281 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
CEntity  * penPlayer  = GetPlayerEntity  ((iPlayer  + iOffset ) % ctPlayers );
#line 282 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(penPlayer  == NULL  || penPlayer  == penCurrentTarget ){
#line 283 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
continue ;
#line 284 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 286 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if((penPlayer  -> GetFlags  () & ENF_ALIVE ) && ! (penPlayer  -> GetFlags  () & ENF_INVISIBLE )){
#line 288 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
FLOAT fDistance  = 
#line 289 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
(penPlayer  -> GetPlacement  () . pl_PositionVector  - m_penOwner  -> GetPlacement  () . pl_PositionVector ) . Length  ();
#line 291 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(fDistance  < fRange  && 
#line 292 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
GetOwner  () -> SeeEntity  (penPlayer  , Cos  (GetOwner  () -> m_fViewAngle  / 2.0f))){
#line 294 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return penPlayer ;
#line 295 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 296 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 297 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 299 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return penCurrentTarget ;
#line 300 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
  
#line 305 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
SLONG CWatcher::GetUsedMemory(void) 
#line 306 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
{
#line 307 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return (sizeof  (CWatcher ) - sizeof  (CRationalEntity ) + CRationalEntity  :: GetUsedMemory  ());
#line 308 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
BOOL CWatcher::
#line 315 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
Active(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWatcher_Active
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWatcher::Active expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 317 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
Jump(STATE_CURRENT,0x02bc0005, FALSE, EInternal());return TRUE;}BOOL CWatcher::H0x02bc0005_Active_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02bc0005
if(!(TRUE )){ Jump(STATE_CURRENT,0x02bc0006, FALSE, EInternal());return TRUE;}
#line 319 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
Watch  ();
#line 321 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
SetTimerAfter(m_tmDelay );
Jump(STATE_CURRENT, 0x02bc0003, FALSE, EBegin());return TRUE;}BOOL CWatcher::H0x02bc0003_Active_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x02bc0003
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x02bc0004, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EStop):{const EStop&e= (EStop&)__eeInput;
Jump(STATE_CURRENT, STATE_CWatcher_Inactive, TRUE, EVoid());return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EStart):{const EStart&e= (EStart&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x02bc0004, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_ETeleport):{const ETeleport&e= (ETeleport&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x02bc0004, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 329 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}return TRUE;}BOOL CWatcher::H0x02bc0004_Active_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02bc0004
Jump(STATE_CURRENT,0x02bc0005, FALSE, EInternal());return TRUE;
#line 330 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}BOOL CWatcher::H0x02bc0006_Active_04(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02bc0006
 ASSERT(FALSE); return TRUE;};BOOL CWatcher::
#line 334 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
Inactive(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWatcher_Inactive
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWatcher::Inactive expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 335 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x02bc0008, FALSE, EBegin());return TRUE;}BOOL CWatcher::H0x02bc0008_Inactive_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x02bc0008
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EStart):{const EStart&e= (EStart&)__eeInput;
Jump(STATE_CURRENT, STATE_CWatcher_Active, TRUE, EVoid());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 338 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}return TRUE;}BOOL CWatcher::H0x02bc0009_Inactive_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02bc0009
 ASSERT(FALSE); return TRUE;};BOOL CWatcher::
#line 342 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
Dummy(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWatcher_Dummy
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWatcher::Dummy expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 345 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x02bc000b, FALSE, EBegin());return TRUE;}BOOL CWatcher::H0x02bc000b_Dummy_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x02bc000b
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;
return TRUE;}ASSERT(FALSE);break;default:{return TRUE;}ASSERT(FALSE);break;
#line 348 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}return TRUE;}BOOL CWatcher::H0x02bc000c_Dummy_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02bc000c
; ASSERT(FALSE); return TRUE;};BOOL CWatcher::
#line 351 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWatcher_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EWatcherInit, "CWatcher::Main expects 'EWatcherInit' as input!");  const EWatcherInit &eInit = (const EWatcherInit &)__eeInput;
#line 353 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
ASSERT  (eInit  . penOwner  != NULL );
#line 354 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
m_penOwner  = eInit  . penOwner ;
#line 357 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
InitAsVoid  ();
#line 358 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 359 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 362 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
if(GetSP  () -> sp_gmGameMode  == CSessionProperties  :: GM_FLYOVER ){
#line 364 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
Jump(STATE_CURRENT, STATE_CWatcher_Dummy, TRUE, EVoid());return TRUE;
#line 366 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
}
#line 370 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
m_iPlayerToCheck  = GetRandomPlayer  () - 1;
#line 373 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
STATE_CWatcher_Inactive, TRUE;
Jump(STATE_CURRENT, 0x02bc000d, FALSE, EBegin());return TRUE;}BOOL CWatcher::H0x02bc000d_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x02bc000d
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CWatcher_Inactive, TRUE, EVoid());return TRUE;case EVENTCODE_EEnd: Jump(STATE_CURRENT,0x02bc000e, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CWatcher::H0x02bc000e_Main_02(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x02bc000e
const EEnd&__e= (EEnd&)__eeInput;
;
#line 376 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
Destroy  ();
#line 378 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
Return(STATE_CURRENT,EVoid());
#line 378 "V:/Programs/SamSDK/Sources/EntitiesMP/Watcher.es"
return TRUE; ASSERT(FALSE); return TRUE;};