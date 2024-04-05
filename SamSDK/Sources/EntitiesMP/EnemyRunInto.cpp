/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"

#include "StdH.h"

#include <EntitiesMP/EnemyRunInto.h>
#include <EntitiesMP/EnemyRunInto_tables.h>
void CEnemyRunInto::SetDefaultProperties(void) {
  m_penLastTouched = NULL;
  m_fLastTouchedTime = 0.0f;
  m_bWhileLoop = FALSE ;
  m_fMassKicked = 0.0f;
  m_fInertionRunTime = 1.3f;
  m_fStopApproachDistance = 6.75f;
  m_fChargeDistance = 15.0f;
  m_bUseChargeAnimation = FALSE ;
  m_fAttackRotateRunInto = 1.0f;
  CEnemyBase::SetDefaultProperties();
}
  void CEnemyRunInto::AdjustDifficulty(void) 
#line 30 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
{
#line 31 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
FLOAT fMoveSpeed  = GetSP  () -> sp_fEnemyMovementSpeed ;
#line 32 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_fAttackRotateRunInto  *= fMoveSpeed ;
#line 34 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
CEnemyBase  :: AdjustDifficulty  ();
#line 35 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
  
#line 39 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
void CEnemyRunInto::IncreaseKickedMass(CEntity * pen) {
#line 40 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
EntityInfo  * peiTarget  = (EntityInfo  *) (pen  -> GetEntityInfo  ());
#line 41 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
if(peiTarget  != NULL ){
#line 42 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_fMassKicked  += peiTarget  -> fMass ;
#line 43 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
#line 44 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
  void CEnemyRunInto::LiveEntityTouched(ETouch etouch) {}
  BOOL CEnemyRunInto::HigherMass(void) {return FALSE ;}
  void CEnemyRunInto::ChargeAnim(void) {}
BOOL CEnemyRunInto::
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Fire(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnemyRunInto_Fire
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnemyRunInto::Fire expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 65 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_fMassKicked  = 0.0f;
#line 66 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_penLastTouched  = NULL ;
#line 68 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Jump(STATE_CURRENT, STATE_CEnemyRunInto_RotateToEnemy, TRUE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};BOOL CEnemyRunInto::
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
RotateToEnemy(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnemyRunInto_RotateToEnemy
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnemyRunInto::RotateToEnemy expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 74 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
if(! (m_penEnemy  -> GetFlags  () & ENF_ALIVE ) || m_penEnemy  -> GetFlags  () & ENF_DELETED ){
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
SetTargetNone  ();
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Return(STATE_CURRENT,EReturn  ());
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE;
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_bWhileLoop  = TRUE ;
#line 81 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Jump(STATE_CURRENT,0x01380004, FALSE, EInternal());return TRUE;}BOOL CEnemyRunInto::H0x01380004_RotateToEnemy_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01380004
if(!(m_penEnemy  != NULL  && m_bWhileLoop )){ Jump(STATE_CURRENT,0x01380005, FALSE, EInternal());return TRUE;}
#line 82 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_fMoveFrequency  = 0.1f;
#line 83 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
SetTimerAfter(m_fMoveFrequency );
Jump(STATE_CURRENT, 0x01380002, FALSE, EBegin());return TRUE;}BOOL CEnemyRunInto::H0x01380002_RotateToEnemy_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01380002
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 86 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_vDesiredPosition  = m_penEnemy  -> GetPlacement  () . pl_PositionVector ;
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
if(! IsInPlaneFrustum  (m_penEnemy  , CosFast  (15.0f))){
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_aRotateSpeed  = m_fAttackRotateRunInto ;
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_fMoveSpeed  = 0.0f;
#line 92 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
ULONG  ulFlags  = SetDesiredMovement  ();
#line 93 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
MovementAnimation  (ulFlags );
#line 94 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}else {
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_aRotateSpeed  = 0.0f;
#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_fMoveSpeed  = 0.0f;
#line 97 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_bWhileLoop  = FALSE ;
#line 98 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE;
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}ASSERT(FALSE);break;case(EVENTCODE_ESound):{const ESound&e= (ESound&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EWatch):{const EWatch&e= (EWatch&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x01380003, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}return TRUE;}BOOL CEnemyRunInto::H0x01380003_RotateToEnemy_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01380003
Jump(STATE_CURRENT,0x01380004, FALSE, EInternal());return TRUE;
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}BOOL CEnemyRunInto::H0x01380005_RotateToEnemy_04(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01380005

#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Jump(STATE_CURRENT, STATE_CEnemyRunInto_RunIntoEnemy, TRUE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};BOOL CEnemyRunInto::
#line 174 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
RunIntoEnemy(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnemyRunInto_RunIntoEnemy
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnemyRunInto::RunIntoEnemy expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
if(! (m_penEnemy  -> GetFlags  () & ENF_ALIVE ) || m_penEnemy  -> GetFlags  () & ENF_DELETED ){
#line 177 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
SetTargetNone  ();
#line 178 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Return(STATE_CURRENT,EReturn  ());
#line 178 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE;
#line 179 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
#line 182 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_bWhileLoop  = TRUE ;
#line 183 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Jump(STATE_CURRENT,0x01380009, FALSE, EInternal());return TRUE;}BOOL CEnemyRunInto::H0x01380009_RunIntoEnemy_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01380009
if(!(m_penEnemy  != NULL  && m_bWhileLoop )){ Jump(STATE_CURRENT,0x0138000a, FALSE, EInternal());return TRUE;}
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_fMoveFrequency  = 0.1f;
#line 185 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
SetTimerAfter(m_fMoveFrequency );
Jump(STATE_CURRENT, 0x01380007, FALSE, EBegin());return TRUE;}BOOL CEnemyRunInto::H0x01380007_RunIntoEnemy_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01380007
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 188 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
if(! SeeEntity  (m_penEnemy  , CosFast  (90.0f)) || CalcDist  (m_penEnemy ) < m_fStopApproachDistance ){
#line 190 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_bWhileLoop  = FALSE ;
#line 191 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
UnsetTimer();Jump(STATE_CURRENT,0x01380008, FALSE, EInternal());return TRUE;
#line 192 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
#line 194 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_fMoveSpeed  = m_fAttackRunSpeed ;
#line 195 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_aRotateSpeed  = m_fAttackRotateRunInto ;
#line 196 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_vDesiredPosition  = m_penEnemy  -> GetPlacement  () . pl_PositionVector ;
#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
SetDesiredMovement  ();
#line 198 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
if(m_bUseChargeAnimation  && CalcDist  (m_penEnemy ) < m_fChargeDistance ){
#line 199 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
ChargeAnim  ();
#line 200 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}else {
#line 201 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
RunningAnim  ();
#line 202 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
#line 204 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
AddToFuss  ();
#line 205 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE;
#line 206 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETouch):{const ETouch&etouch= (ETouch&)__eeInput;

#line 210 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
if(etouch  . penOther  -> GetFlags  () & ENF_ALIVE ){
#line 212 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
LiveEntityTouched  (etouch );
#line 214 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
if(HigherMass  ()){
#line 216 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_penLastTouched  = NULL ;
#line 217 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Return(STATE_CURRENT,EReturn  ());
#line 217 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE;
#line 218 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
#line 220 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
if(etouch  . penOther  == m_penEnemy ){
#line 222 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_bWhileLoop  = FALSE ;
#line 223 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
UnsetTimer();Jump(STATE_CURRENT,0x01380008, FALSE, EInternal());return TRUE;
#line 224 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
#line 226 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}else if(! (etouch  . penOther  -> GetPhysicsFlags  () & EPF_MOVABLE ) && 
#line 227 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
(FLOAT3D (etouch  . plCollision ) % - en_vGravityDir ) < CosFast  (50.0f)){
#line 229 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_penLastTouched  = NULL ;
#line 230 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Return(STATE_CURRENT,EReturn  ());
#line 230 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE;
#line 231 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
#line 232 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE;
#line 233 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x01380008, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EDeath):{const EDeath&e= (EDeath&)__eeInput;
return FALSE;}ASSERT(FALSE);break;default:{return TRUE;}ASSERT(FALSE);break;
#line 237 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}return TRUE;}BOOL CEnemyRunInto::H0x01380008_RunIntoEnemy_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01380008
Jump(STATE_CURRENT,0x01380009, FALSE, EInternal());return TRUE;
#line 238 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}BOOL CEnemyRunInto::H0x0138000a_RunIntoEnemy_04(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0138000a

#line 239 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Jump(STATE_CURRENT, STATE_CEnemyRunInto_RunAwayFromEnemy, TRUE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};BOOL CEnemyRunInto::
#line 242 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
RunAwayFromEnemy(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnemyRunInto_RunAwayFromEnemy
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnemyRunInto::RunAwayFromEnemy expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 244 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
if(! (m_penEnemy  -> GetFlags  () & ENF_ALIVE ) || m_penEnemy  -> GetFlags  () & ENF_DELETED ){
#line 245 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
SetTargetNone  ();
#line 246 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Return(STATE_CURRENT,EReturn  ());
#line 246 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE;
#line 247 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
#line 250 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
StopRotating  ();
#line 251 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
SetTimerAfter(m_fInertionRunTime );
Jump(STATE_CURRENT, 0x0138000c, FALSE, EBegin());return TRUE;}BOOL CEnemyRunInto::H0x0138000c_RunAwayFromEnemy_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0138000c
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_ETouch):{const ETouch&etouch= (ETouch&)__eeInput;

#line 255 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
if(etouch  . penOther  -> GetFlags  () & ENF_ALIVE ){
#line 256 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
LiveEntityTouched  (etouch );
#line 258 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
if(HigherMass  ()){
#line 259 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_penLastTouched  = NULL ;
#line 260 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Return(STATE_CURRENT,EReturn  ());
#line 260 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE;
#line 261 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
#line 263 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}else if(! (etouch  . penOther  -> GetPhysicsFlags  () & EPF_MOVABLE ) && 
#line 264 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
(FLOAT3D (etouch  . plCollision ) % - en_vGravityDir ) < CosFast  (50.0f)){
#line 265 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_penLastTouched  = NULL ;
#line 266 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Return(STATE_CURRENT,EReturn  ());
#line 266 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE;
#line 267 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}
#line 268 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE;
#line 269 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x0138000d, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EDeath):{const EDeath&e= (EDeath&)__eeInput;
return FALSE;}ASSERT(FALSE);break;default:{return TRUE;}ASSERT(FALSE);break;
#line 273 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
}return TRUE;}BOOL CEnemyRunInto::H0x0138000d_RunAwayFromEnemy_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0138000d

#line 275 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
m_penLastTouched  = NULL ;
#line 276 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
STATE_CEnemyRunInto_PostRunAwayFromEnemy, TRUE;
Jump(STATE_CURRENT, 0x0138000e, FALSE, EBegin());return TRUE;}BOOL CEnemyRunInto::H0x0138000e_RunAwayFromEnemy_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0138000e
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CEnemyRunInto_PostRunAwayFromEnemy, TRUE, EVoid());return TRUE;case EVENTCODE_EReturn: Jump(STATE_CURRENT,0x0138000f, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CEnemyRunInto::H0x0138000f_RunAwayFromEnemy_04(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x0138000f
const EReturn&__e= (EReturn&)__eeInput;
;
#line 277 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Return(STATE_CURRENT,EReturn  ());
#line 277 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CEnemyRunInto::
#line 280 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
PostRunAwayFromEnemy(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnemyRunInto_PostRunAwayFromEnemy
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnemyRunInto::PostRunAwayFromEnemy expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 281 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Return(STATE_CURRENT,EReturn  ());
#line 281 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CEnemyRunInto::
#line 285 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
MainLoop(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnemyRunInto_MainLoop
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnemyRunInto::MainLoop expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 286 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Jump(STATE_CURRENT, STATE_CEnemyBase_MainLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};BOOL CEnemyRunInto::
#line 290 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnemyRunInto_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnemyRunInto::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 291 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
Return(STATE_CURRENT,EVoid());
#line 291 "V:/Programs/SamSDK/Sources/EntitiesMP/EnemyRunInto.es"
return TRUE; ASSERT(FALSE); return TRUE;};