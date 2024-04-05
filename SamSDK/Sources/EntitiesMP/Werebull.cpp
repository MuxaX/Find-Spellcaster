/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"

#include "StdH.h"
#include "Models/Enemies/Werebull/Werebull.h"

#include <EntitiesMP/Werebull.h>
#include <EntitiesMP/Werebull_tables.h>
#line 15 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"

// info structure
static EntityInfo eiWerebull = {
  EIBT_FLESH, 500.0f,
  0.0f, 3.0f, 0.0f,     // source (eyes)
  0.0f, 1.5f, 0.0f,     // target (body)
};

#define HIT_DISTANCE 5.0f

void CWerebull::SetDefaultProperties(void) {
  m_bRunAttack = FALSE ;
  m_bHornHit = FALSE ;
  m_penLastTouched = NULL;
  m_soFeet.SetOwner(this);
m_soFeet.Stop_internal();
  m_bRunSoundPlaying = FALSE ;
  CEnemyRunInto::SetDefaultProperties();
}
  CTString CWerebull::GetPlayerKillDescription(const CTString & strPlayerName,const EDeath & eDeath) 
#line 56 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
{
#line 57 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
CTString str ;
#line 58 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
str  . PrintF  (TRANS  ("Sirian werebull sent %s flying") , strPlayerName );
#line 59 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
return str ;
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::Precache(void) {
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
CEnemyBase  :: Precache  ();
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
PrecacheSound  (SOUND_IDLE );
#line 65 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
PrecacheSound  (SOUND_SIGHT );
#line 66 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
PrecacheSound  (SOUND_KICKHORN );
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
PrecacheSound  (SOUND_IMPACT );
#line 68 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
PrecacheSound  (SOUND_DEATH );
#line 69 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
PrecacheSound  (SOUND_RUN );
#line 70 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 73 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void * CWerebull::GetEntityInfo(void) {
#line 74 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
return & eiWerebull ;
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
FLOAT CWerebull::GetCrushHealth(void) 
#line 78 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
{
#line 79 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
return 60.0f;
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  const CTFileName & CWerebull::GetComputerMessageName(void)const {
#line 83 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
static DECLARE_CTFILENAME  (fnm  , "Data\\Messages\\Enemies\\Bull.txt");
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
return fnm ;
#line 85 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::RenderParticles(void) 
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
{
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
Particles_RunningDust  (this );
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
CEnemyBase  :: RenderParticles  ();
#line 92 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection) 
#line 97 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
{
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(! IsOfClass  (penInflictor  , "Werebull")){
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
CEnemyBase  :: ReceiveDamage  (penInflictor  , dmtType  , fDamageAmmount  , vHitPoint  , vDirection );
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
#line 102 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::AdjustDifficulty(void) 
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
{
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 110 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
INDEX CWerebull::AnimForDeath(void) {
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
INDEX iAnim ;
#line 112 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(en_vCurrentTranslationAbsolute  . Length  () > 5.0f){
#line 113 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
iAnim  = WEREBULL_ANIM_DEATHRUN ;
#line 114 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}else {
#line 115 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
iAnim  = WEREBULL_ANIM_DEATH ;
#line 116 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
#line 117 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
StartModelAnim  (iAnim  , 0);
#line 118 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
DeactivateRunningSound  ();
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
return iAnim ;
#line 120 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 122 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
FLOAT CWerebull::WaitForDust(FLOAT3D & vStretch) {
#line 123 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(GetModelObject  () -> GetAnim  () == WEREBULL_ANIM_DEATHRUN )
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
{
#line 125 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
vStretch  = FLOAT3D (1 , 1 , 2) * 2.0f;
#line 126 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
return 0.6f;
#line 127 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
#line 128 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
else if(GetModelObject  () -> GetAnim  () == WEREBULL_ANIM_DEATH )
#line 129 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
{
#line 130 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
vStretch  = FLOAT3D (1 , 1 , 2) * 2.0f;
#line 131 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
return 0.7f;
#line 132 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
#line 133 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
return - 1.0f;
#line 134 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 136 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::DeathNotify() {
#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
ChangeCollisionBoxIndexWhenPossible  (WEREBULL_COLLISION_BOX_DEATH );
#line 138 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
SetCollisionFlags  (ECF_MODEL );
#line 139 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 142 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::StandingAnim(void) {
#line 143 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
StartModelAnim  (WEREBULL_ANIM_IDLE  , AOF_LOOPING  | AOF_NORESTART );
#line 144 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
DeactivateRunningSound  ();
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 146 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::WalkingAnim(void) {
#line 147 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
StartModelAnim  (WEREBULL_ANIM_WALK  , AOF_LOOPING  | AOF_NORESTART );
#line 148 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
DeactivateRunningSound  ();
#line 149 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 150 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::RunningAnim(void) {
#line 151 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
StartModelAnim  (WEREBULL_ANIM_RUN  , AOF_LOOPING  | AOF_NORESTART );
#line 152 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
ActivateRunningSound  ();
#line 153 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 154 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::RotatingAnim(void) {
#line 155 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
StartModelAnim  (WEREBULL_ANIM_RUN  , AOF_LOOPING  | AOF_NORESTART );
#line 157 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
ActivateRunningSound  ();
#line 158 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 161 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::IdleSound(void) {
#line 162 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
PlaySound  (m_soSound  , SOUND_IDLE  , SOF_3D );
#line 163 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 164 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::SightSound(void) {
#line 165 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
PlaySound  (m_soSound  , SOUND_SIGHT  , SOF_3D );
#line 166 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 167 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::WoundSound(void) {
#line 168 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 169 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::DeathSound(void) {
#line 170 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
PlaySound  (m_soSound  , SOUND_DEATH  , SOF_3D );
#line 171 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 175 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::ActivateRunningSound(void) 
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
{
#line 177 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(! m_bRunSoundPlaying ){
#line 178 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
PlaySound  (m_soFeet  , SOUND_RUN  , SOF_3D  | SOF_LOOP );
#line 179 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_bRunSoundPlaying  = TRUE ;
#line 180 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
#line 181 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 182 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::DeactivateRunningSound(void) 
#line 183 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
{
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_soFeet  . Stop  ();
#line 185 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_bRunSoundPlaying  = FALSE ;
#line 186 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 193 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::LiveEntityTouched(ETouch etouch) {
#line 194 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(m_penLastTouched  != etouch  . penOther  || _pTimer  -> CurrentTick  () >= m_fLastTouchedTime  + 0.25f){
#line 196 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
FLOAT3D vDirection  = en_vCurrentTranslationAbsolute ;
#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
vDirection  . Normalize  ();
#line 198 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
ANGLE aHitAngle  = FLOAT3D (etouch  . plCollision ) % vDirection ;
#line 200 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(aHitAngle  < 0.0f){
#line 202 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(! IsOfSameClass  (this  , etouch  . penOther )){
#line 203 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
IncreaseKickedMass  (etouch  . penOther );
#line 204 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
#line 205 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
PlaySound  (m_soSound  , SOUND_IMPACT  , SOF_3D );
#line 207 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_penLastTouched  = etouch  . penOther ;
#line 208 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fLastTouchedTime  = _pTimer  -> CurrentTick  ();
#line 210 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
FLOAT3D vDirection  = m_penEnemy  -> GetPlacement  () . pl_PositionVector  - GetPlacement  () . pl_PositionVector ;
#line 211 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
vDirection  . Normalize  ();
#line 212 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
InflictDirectDamage  (etouch  . penOther  , this  , DMT_CLOSERANGE  , - aHitAngle  * 40.0f , 
#line 213 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
FLOAT3D (0 , 0 , 0) , vDirection );
#line 215 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
FLOAT3D vSpeed  = - FLOAT3D (etouch  . plCollision );
#line 216 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
vSpeed  = vSpeed  * 10.0f;
#line 217 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
const FLOATmatrix3D & m  = GetRotationMatrix  ();
#line 218 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
FLOAT3D vSpeedRel  = vSpeed  * ! m ;
#line 219 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(vSpeedRel  (1) < - 0.1f){
#line 220 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
vSpeedRel  (1) -= 15.0f;
#line 221 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}else {
#line 222 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
vSpeedRel  (1) += 15.0f;
#line 223 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
#line 224 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
vSpeedRel  (2) = 15.0f;
#line 226 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
vSpeed  = vSpeedRel  * m ;
#line 227 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
KickEntity  (etouch  . penOther  , vSpeed );
#line 228 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
#line 229 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
#line 230 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 233 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
BOOL CWerebull::HigherMass(void) {
#line 234 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
return (m_fMassKicked  > 500.0f);
#line 235 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
  
#line 238 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
void CWerebull::EnemyPostInit(void) 
#line 239 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
{
#line 241 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_soFeet  . Set3DParameters  (500.0f , 50.0f , 1.0f , 1.0f);
#line 242 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_bRunSoundPlaying  = FALSE ;
#line 243 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_soSound  . Set3DParameters  (160.0f , 50.0f , 1.0f , 1.0f);
#line 244 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
BOOL CWerebull::
#line 251 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
Hit(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWerebull_Hit
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWerebull::Hit expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 252 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(!(CalcDist  (m_penEnemy ) < HIT_DISTANCE )){ Jump(STATE_CURRENT,0x01330007, FALSE, EInternal());return TRUE;}
#line 254 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
StartModelAnim  (WEREBULL_ANIM_ATTACKHORNS  , 0);
#line 255 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
DeactivateRunningSound  ();
#line 256 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_bHornHit  = FALSE ;
#line 257 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
SetTimerAfter(0.4f);
Jump(STATE_CURRENT, 0x01330001, FALSE, EBegin());return TRUE;}BOOL CWerebull::H0x01330001_Hit_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01330001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01330002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CWerebull::H0x01330002_Hit_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01330002
;
#line 258 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
PlaySound  (m_soSound  , SOUND_KICKHORN  , SOF_3D );
#line 259 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(CalcDist  (m_penEnemy ) < HIT_DISTANCE ){m_bHornHit  = TRUE ;}
#line 260 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x01330003, FALSE, EBegin());return TRUE;}BOOL CWerebull::H0x01330003_Hit_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01330003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01330004, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CWerebull::H0x01330004_Hit_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01330004
;
#line 261 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(CalcDist  (m_penEnemy ) < HIT_DISTANCE ){m_bHornHit  = TRUE ;}
#line 262 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x01330005, FALSE, EBegin());return TRUE;}BOOL CWerebull::H0x01330005_Hit_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01330005
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01330006, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CWerebull::H0x01330006_Hit_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01330006
;
#line 263 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(CalcDist  (m_penEnemy ) < HIT_DISTANCE ){m_bHornHit  = TRUE ;}
#line 264 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(m_bHornHit ){
#line 265 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
FLOAT3D vDirection  = m_penEnemy  -> GetPlacement  () . pl_PositionVector  - GetPlacement  () . pl_PositionVector ;
#line 266 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
vDirection  . Normalize  ();
#line 267 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
InflictDirectDamage  (m_penEnemy  , this  , DMT_CLOSERANGE  , 20.0f , FLOAT3D (0 , 0 , 0) , vDirection );
#line 268 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
FLOAT3D vSpeed ;
#line 269 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
GetPitchDirection  (AngleDeg  (90.0f) , vSpeed );
#line 270 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
vSpeed  = vSpeed  * 10.0f;
#line 271 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
KickEntity  (m_penEnemy  , vSpeed );
#line 272 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}Jump(STATE_CURRENT,0x01330007, FALSE, EInternal());return TRUE;}BOOL CWerebull::H0x01330007_Hit_07(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01330007

#line 276 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fShootTime  = _pTimer  -> CurrentTick  () + 0.5f;
#line 277 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
Return(STATE_CURRENT,EReturn  ());
#line 277 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CWerebull::
#line 285 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWerebull_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWerebull::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 287 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
InitAsModel  ();
#line 288 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
SetPhysicsFlags  (EPF_MODEL_WALKING );
#line 289 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
SetCollisionFlags  (ECF_MODEL );
#line 290 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
SetFlags  (GetFlags  () | ENF_ALIVE );
#line 291 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
SetHealth  (250.0f);
#line 292 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fMaxHealth  = 250.0f;
#line 293 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
en_fDensity  = 2000.0f;
#line 296 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
SetModel  (MODEL_WEREBULL );
#line 298 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
SetModelMainTexture  (TEXTURE_WEREBULL_SUMMER );
#line 302 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
StandingAnim  ();
#line 304 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fWalkSpeed  = FRnd  () + 2.5f;
#line 305 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_aWalkRotateSpeed  = AngleDeg  (FRnd  () * 25.0f + 45.0f);
#line 306 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fAttackRunSpeed  = FRnd  () * 5.0f + 22.5f;
#line 307 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fAttackRotateRunInto  = AngleDeg  (FRnd  () * 60 + 100.0f);
#line 308 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_aAttackRotateSpeed  = m_fAttackRotateRunInto ;
#line 309 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fCloseRunSpeed  = FRnd  () * 5.0f + 15.0f;
#line 310 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_aCloseRotateSpeed  = AngleDeg  (FRnd  () * 50 + 500.0f);
#line 312 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fAttackDistance  = 100.0f;
#line 313 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fCloseDistance  = 7.0f;
#line 314 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fStopDistance  = 0.0f;
#line 315 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fAttackFireTime  = 0.05f;
#line 316 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fCloseFireTime  = 1.0f;
#line 317 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fIgnoreRange  = 250.0f;
#line 319 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fBlowUpAmount  = 1E10f;
#line 320 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fBodyParts  = 12;
#line 321 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fDamageWounded  = 100000.0f;
#line 322 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_iScore  = 2000;
#line 323 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
if(m_fStepHeight  == - 1){
#line 324 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
m_fStepHeight  = 4.0f;
#line 325 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
}
#line 327 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
Particles_RunningDust_Prepare  (this );
#line 330 "V:/Programs/SamSDK/Sources/EntitiesMP/Werebull.es"
Jump(STATE_CURRENT, STATE_CEnemyRunInto_MainLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};