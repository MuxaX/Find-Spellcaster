/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 3 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"

#include "StdH.h"
#include "ModelsMP/Enemies/Demon/Demon.h"

#include <EntitiesMP/Demon.h>
#include <EntitiesMP/Demon_tables.h>
#line 12 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"

#define REMINDER_DEATTACH_FIREBALL 666
#define CLOSE_ATTACK_RANGE 10.0f
#define DEMON_STRETCH 2.5f
FLOAT3D vFireballLaunchPos = (FLOAT3D(0.06f, 2.6f, 0.15f)*DEMON_STRETCH);
static _tmLastStandingAnim =0.0f;  

// info structure
static EntityInfo eiDemon = {
  EIBT_FLESH, 1600.0f,
  0.0f, 2.0f, 0.0f,     // source (eyes)
  0.0f, 1.5f, 0.0f,     // target (body)
};

void CDemon::SetDefaultProperties(void) {
  m_iCounter = 0;
  m_penFireFX = NULL;
  CEnemyBase::SetDefaultProperties();
}
  
#line 54 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
BOOL CDemon::HandleEvent(const CEntityEvent & ee) 
#line 55 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
{
#line 59 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
if(ee  . ee_slEvent  == EVENTCODE_EReminder )
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
{
#line 61 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
EReminder  eReminder  = ((EReminder  &) ee );
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
if(eReminder  . iValue  == REMINDER_DEATTACH_FIREBALL )
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
{
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
RemoveAttachment  (DEMON_ATTACHMENT_FIREBALL );
#line 65 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
#line 66 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
return TRUE ;
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
#line 68 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
return CEnemyBase  :: HandleEvent  (ee );
#line 69 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  CTString CDemon::GetPlayerKillDescription(const CTString & strPlayerName,const EDeath & eDeath) 
#line 73 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
{
#line 74 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
CTString str ;
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
str  . PrintF  (TRANS  ("A Demon executed %s") , strPlayerName );
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
return str ;
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  const CTFileName & CDemon::GetComputerMessageName(void)const {
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
static DECLARE_CTFILENAME  (fnmDemon  , "DataMP\\Messages\\Enemies\\Demon.txt");
#line 81 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
return fnmDemon ;
#line 82 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void CDemon::Precache(void) {
#line 85 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
CEnemyBase  :: Precache  ();
#line 86 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PrecacheSound  (SOUND_IDLE );
#line 87 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PrecacheSound  (SOUND_SIGHT );
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PrecacheSound  (SOUND_WOUND );
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PrecacheSound  (SOUND_DEATH );
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PrecacheSound  (SOUND_CAST );
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PrecacheModel  (MODEL_DEMON );
#line 92 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PrecacheTexture  (TEXTURE_DEMON );
#line 93 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PrecacheModel  (MODEL_FIREBALL );
#line 94 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PrecacheTexture  (TEXTURE_FIREBALL );
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PrecacheClass  (CLASS_PROJECTILE  , PRT_BEAST_PROJECTILE );
#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void * CDemon::GetEntityInfo(void) {
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
return & eiDemon ;
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
BOOL CDemon::ForcesCannonballToExplode(void) 
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
{
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
return TRUE ;
#line 106 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 117 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void CDemon::ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 118 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection) 
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
{
#line 121 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
if(dmtType  == DMT_BULLET  && fDamageAmmount  > 100.0f)
#line 122 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
{
#line 123 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
fDamageAmmount  *= 0.5f;
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
#line 127 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
if(! IsOfClass  (penInflictor  , "Demon")){
#line 128 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
CEnemyBase  :: ReceiveDamage  (penInflictor  , dmtType  , fDamageAmmount  , vHitPoint  , vDirection );
#line 129 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
#line 130 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 134 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
INDEX CDemon::AnimForDamage(FLOAT fDamage) {
#line 135 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
RemoveAttachment  (DEMON_ATTACHMENT_FIREBALL );
#line 136 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
StartModelAnim  (DEMON_ANIM_WOUND  , 0);
#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
return DEMON_ANIM_WOUND ;
#line 138 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 141 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
INDEX CDemon::AnimForDeath(void) {
#line 142 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
if(m_penFireFX  != NULL )
#line 143 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
{
#line 144 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_penFireFX  -> SendEvent  (EStop  ());
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_penFireFX  = NULL ;
#line 146 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
#line 148 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
RemoveAttachment  (DEMON_ATTACHMENT_FIREBALL );
#line 149 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
StartModelAnim  (DEMON_ANIM_DEATHFORWARD  , 0);
#line 150 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
return DEMON_ANIM_DEATHFORWARD ;
#line 151 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 153 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
FLOAT CDemon::WaitForDust(FLOAT3D & vStretch) 
#line 154 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
{
#line 155 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
vStretch  = FLOAT3D (1 , 1 , 2) * 3.0f;
#line 156 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
return 1.1f;
#line 157 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 159 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void CDemon::DeathNotify(void) {
#line 160 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
ChangeCollisionBoxIndexWhenPossible  (DEMON_COLLISION_BOX_DEATH );
#line 161 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
en_fDensity  = 500.0f;
#line 162 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 165 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void CDemon::StandingAnim(void) {
#line 167 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
StartModelAnim  (DEMON_ANIM_IDLE  , AOF_LOOPING  | AOF_NORESTART );
#line 168 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 170 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void CDemon::WalkingAnim(void) {
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
RunningAnim  ();
#line 177 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 179 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void CDemon::RunningAnim(void) {
#line 180 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
StartModelAnim  (DEMON_ANIM_RUN  , AOF_LOOPING  | AOF_NORESTART );
#line 181 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 182 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void CDemon::RotatingAnim(void) {
#line 183 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
StartModelAnim  (DEMON_ANIM_RUN  , AOF_LOOPING  | AOF_NORESTART );
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 187 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void CDemon::IdleSound(void) {
#line 188 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PlaySound  (m_soSound  , SOUND_IDLE  , SOF_3D );
#line 189 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 190 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void CDemon::SightSound(void) {
#line 191 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PlaySound  (m_soSound  , SOUND_SIGHT  , SOF_3D );
#line 192 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 193 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void CDemon::WoundSound(void) {
#line 194 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PlaySound  (m_soSound  , SOUND_WOUND  , SOF_3D );
#line 195 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 196 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void CDemon::DeathSound(void) {
#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PlaySound  (m_soSound  , SOUND_DEATH  , SOF_3D );
#line 198 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
  
#line 202 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
void CDemon::EnemyPostInit(void) 
#line 203 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
{
#line 204 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_soSound  . Set3DParameters  (160.0f , 50.0f , 2.0f , 1.0f);
#line 205 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
BOOL CDemon::
#line 211 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
Fire(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDemon_Fire
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CDemon::Fire expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 215 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
if(m_fMoveSpeed  > 0.0f){
#line 216 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetDesiredTranslation  (FLOAT3D (0.0f , 0.0f , - m_fMoveSpeed ));
#line 217 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
#line 220 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
StartModelAnim  (DEMON_ANIM_ATTACK  , 0);
#line 221 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
STATE_CMovableModelEntity_WaitUntilScheduledAnimStarts, FALSE;
Jump(STATE_CURRENT, 0x01500001, FALSE, EBegin());return TRUE;}BOOL CDemon::H0x01500001_Fire_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01500001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CMovableModelEntity_WaitUntilScheduledAnimStarts, FALSE, EVoid());return TRUE;case EVENTCODE_EReturn: Jump(STATE_CURRENT,0x01500002, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CDemon::H0x01500002_Fire_02(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x01500002
const EReturn&__e= (EReturn&)__eeInput;
;
#line 223 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetDesiredTranslation  (FLOAT3D (0.0f , 0.0f , 0.0f));
#line 225 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PlaySound  (m_soSound  , SOUND_CAST  , SOF_3D );
#line 226 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SpawnReminder  (this  , 3.0f , REMINDER_DEATTACH_FIREBALL );
#line 228 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetTimerAfter(1.0f);
Jump(STATE_CURRENT, 0x01500003, FALSE, EBegin());return TRUE;}BOOL CDemon::H0x01500003_Fire_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01500003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01500004, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CDemon::H0x01500004_Fire_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01500004
;
#line 231 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
CPlacement3D plFX  = GetPlacement  ();
#line 232 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
const FLOATmatrix3D & m  = GetRotationMatrix  ();
#line 233 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
plFX  . pl_PositionVector  = plFX  . pl_PositionVector  + vFireballLaunchPos  * m ;
#line 234 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
ESpawnEffect  ese ;
#line 235 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
ese  . colMuliplier  = C_WHITE  | CT_OPAQUE ;
#line 236 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
ese  . betType  = BET_COLLECT_ENERGY ;
#line 237 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
ese  . vStretch  = FLOAT3D (1.0f , 1.0f , 1.0f);
#line 238 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_penFireFX  = CreateEntity  (plFX  , CLASS_BASIC_EFFECT );
#line 239 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_penFireFX  -> Initialize  (ese );
#line 241 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetTimerAfter(1.4f);
Jump(STATE_CURRENT, 0x01500005, FALSE, EBegin());return TRUE;}BOOL CDemon::H0x01500005_Fire_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01500005
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01500006, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CDemon::H0x01500006_Fire_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01500006
;
#line 243 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
AddAttachment  (DEMON_ATTACHMENT_FIREBALL  , MODEL_FIREBALL  , TEXTURE_FIREBALL );
#line 244 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
CModelObject * pmoFire  = & GetModelObject  () -> GetAttachmentModel  (DEMON_ATTACHMENT_FIREBALL ) -> amo_moModelObject ;
#line 245 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
pmoFire  -> StretchModel  (FLOAT3D (DEMON_STRETCH  , DEMON_STRETCH  , DEMON_STRETCH ));
#line 246 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetTimerAfter(2.94f - 2.4f);
Jump(STATE_CURRENT, 0x01500007, FALSE, EBegin());return TRUE;}BOOL CDemon::H0x01500007_Fire_07(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01500007
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01500008, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CDemon::H0x01500008_Fire_08(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01500008
;
#line 248 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
RemoveAttachment  (DEMON_ATTACHMENT_FIREBALL );
#line 249 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
MaybeSwitchToAnotherPlayer  ();
#line 251 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
if(IsVisible  (m_penEnemy )){
#line 252 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
ShootProjectile  (PRT_DEMON_FIREBALL  , vFireballLaunchPos  , ANGLE3D (0.0f , 0.0f , 0.0f));
#line 253 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
#line 254 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
else {
#line 255 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
ShootProjectileAt  (m_vPlayerSpotted  , PRT_DEMON_FIREBALL  , vFireballLaunchPos  , ANGLE3D (0.0f , 0.0f , 0.0f));
#line 256 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
#line 258 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetTimerAfter(1.0f);
Jump(STATE_CURRENT, 0x01500009, FALSE, EBegin());return TRUE;}BOOL CDemon::H0x01500009_Fire_09(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01500009
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0150000a, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CDemon::H0x0150000a_Fire_10(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0150000a
;
#line 260 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
Return(STATE_CURRENT,EReturn  ());
#line 260 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CDemon::
#line 263 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
Hit(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDemon_Hit
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CDemon::Hit expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 265 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
if(!(CalcDist  (m_penEnemy ) < 6.0f)){ Jump(STATE_CURRENT,0x01500011, FALSE, EInternal());return TRUE;}
#line 266 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
StartModelAnim  (DEMON_ANIM_WOUND  , 0);
#line 267 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetTimerAfter(0.45f);
Jump(STATE_CURRENT, 0x0150000c, FALSE, EBegin());return TRUE;}BOOL CDemon::H0x0150000c_Hit_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0150000c
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0150000d, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CDemon::H0x0150000d_Hit_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0150000d
;
#line 268 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
PlaySound  (m_soSound  , SOUND_WOUND  , SOF_3D );
#line 269 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
if(CalcDist  (m_penEnemy ) < CLOSE_ATTACK_RANGE  
#line 270 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
&& IsInPlaneFrustum  (m_penEnemy  , CosFast  (60.0f)))
#line 271 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
{
#line 272 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
FLOAT3D vDirection  = m_penEnemy  -> GetPlacement  () . pl_PositionVector  - GetPlacement  () . pl_PositionVector ;
#line 273 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
vDirection  . Normalize  ();
#line 274 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
InflictDirectDamage  (m_penEnemy  , this  , DMT_CLOSERANGE  , 50.0f , FLOAT3D (0 , 0 , 0) , vDirection );
#line 275 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}
#line 276 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetTimerAfter(1.5f);
Jump(STATE_CURRENT, 0x0150000e, FALSE, EBegin());return TRUE;}BOOL CDemon::H0x0150000e_Hit_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0150000e
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0150000f, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CDemon::H0x0150000f_Hit_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0150000f
;
#line 277 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
MaybeSwitchToAnotherPlayer  ();Jump(STATE_CURRENT,0x01500010, FALSE, EInternal());return TRUE;}BOOL CDemon::H0x01500011_Hit_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01500011
{
#line 280 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fShootTime  = _pTimer  -> CurrentTick  () + 0.5f;
#line 281 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
}Jump(STATE_CURRENT,0x01500010, FALSE, EInternal());return TRUE;}
BOOL CDemon::H0x01500010_Hit_05(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01500010

#line 282 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
Return(STATE_CURRENT,EReturn  ());
#line 282 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CDemon::
#line 289 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDemon_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CDemon::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 291 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
InitAsModel  ();
#line 292 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetPhysicsFlags  (EPF_MODEL_WALKING );
#line 293 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetCollisionFlags  (ECF_MODEL );
#line 294 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetFlags  (GetFlags  () | ENF_ALIVE );
#line 296 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
en_fDensity  = 1100.0f;
#line 298 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetModel  (MODEL_DEMON );
#line 299 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
StandingAnim  ();
#line 301 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fWalkSpeed  = FRnd  () / 1.0f + 12.0f;
#line 302 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_aWalkRotateSpeed  = AngleDeg  (FRnd  () * 20.0f + 50.0f);
#line 303 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fCloseRunSpeed  = FRnd  () / 1.0f + 13.0f;
#line 304 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_aCloseRotateSpeed  = AngleDeg  (FRnd  () * 100 + 900.0f);
#line 305 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fAttackRunSpeed  = FRnd  () / 1.0f + 9.0f;
#line 306 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_aAttackRotateSpeed  = AngleDeg  (FRnd  () * 100.0f + 900.0f);
#line 308 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fAttackDistance  = 650.0f;
#line 309 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fCloseDistance  = 12.0f;
#line 310 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fStopDistance  = 0.0f;
#line 311 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fAttackFireTime  = 5.0f;
#line 312 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fCloseFireTime  = 1.0f;
#line 313 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fIgnoreRange  = 800.0f;
#line 314 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fStopDistance  = 5.0f;
#line 315 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_tmGiveUp  = Max  (m_tmGiveUp  , 10.0f);
#line 318 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetHealth  (500.0f);
#line 319 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fMaxHealth  = GetHealth  ();
#line 320 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
SetModelMainTexture  (TEXTURE_DEMON );
#line 321 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fBlowUpAmount  = 10000.0f;
#line 322 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fBodyParts  = 4;
#line 323 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fDamageWounded  = 1000.0f;
#line 324 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_iScore  = 5000;
#line 325 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
m_fLockOnEnemyTime  = 3.0f;
#line 328 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
GetModelObject  () -> StretchModel  (FLOAT3D (4.2f , 4.2f , 4.2f));
#line 329 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
ModelChangeNotify  ();
#line 332 "V:/Programs/SamSDK/Sources/EntitiesMP/Demon.es"
Jump(STATE_CURRENT, STATE_CEnemyBase_MainLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};