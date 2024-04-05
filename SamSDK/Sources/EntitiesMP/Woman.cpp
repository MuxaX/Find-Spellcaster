/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"

#include "StdH.h"
#include "ModelsMP/Enemies/Woman/Woman.h"
#include "Models/Enemies/Headman/Headman.h"
#include "EntitiesMP/Headman.h"

#include <EntitiesMP/Woman.h>
#include <EntitiesMP/Woman_tables.h>
#line 11 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"

// info structure
static EntityInfo eiWomanStand = {
  EIBT_FLESH, 100.0f,
  0.0f, 1.55f, 0.0f,
  0.0f, 1.0f, 0.0f,
};
static EntityInfo eiWomanFly = {
  EIBT_FLESH, 80.0f,
  0.0f, 0.0f, 0.0f,
  0.0f, 0.0f, 0.0f,
};

#define FIRE_AIR      FLOAT3D(0.0f, 0.25f, -0.65f)
#define FIRE_GROUND   FLOAT3D(0.0f, 1.3f, -0.5f)
#define KAMIKAZE_ATTACH FLOAT3D(0.0f, -0.43f, -0.28f)

void CWoman::SetDefaultProperties(void) {
  m_bKamikazeCarrier = FALSE ;
  m_rKamikazeDropDistance = 40.0f;
  m_bKamikazeAttached = FALSE ;
  CEnemyFly::SetDefaultProperties();
}
  CTString CWoman::GetPlayerKillDescription(const CTString & strPlayerName,const EDeath & eDeath) 
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
{
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
CTString str ;
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(eDeath  . eLastDamage  . dmtType  == DMT_CLOSERANGE ){
#line 65 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
str  . PrintF  (TRANS  ("%s was beaten by a Scythian Harpy") , strPlayerName );
#line 66 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}else {
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
str  . PrintF  (TRANS  ("A Scythian Harpy got %s spellbound") , strPlayerName );
#line 68 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 69 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return str ;
#line 70 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  const CTFileName & CWoman::GetComputerMessageName(void)const {
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
static DECLARE_CTFILENAME  (fnm  , "Data\\Messages\\Enemies\\Woman.txt");
#line 73 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return fnm ;
#line 74 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::Precache(void) {
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
CEnemyBase  :: Precache  ();
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PrecacheSound  (SOUND_IDLE );
#line 78 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PrecacheSound  (SOUND_SIGHT );
#line 79 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PrecacheSound  (SOUND_WOUND );
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PrecacheSound  (SOUND_FIRE );
#line 81 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PrecacheSound  (SOUND_KICK );
#line 82 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PrecacheSound  (SOUND_DEATH );
#line 83 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PrecacheClass  (CLASS_PROJECTILE  , PRT_WOMAN_FIRE );
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 87 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void * CWoman::GetEntityInfo(void) {
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(m_bInAir ){
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return & eiWomanFly ;
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}else {
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return & eiWomanStand ;
#line 92 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 93 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 97 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection) 
#line 98 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
{
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(! IsOfClass  (penInflictor  , "Woman")){
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
CEnemyFly  :: ReceiveDamage  (penInflictor  , dmtType  , fDamageAmmount  , vHitPoint  , vDirection );
#line 102 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
INDEX CWoman::AnimForDamage(FLOAT fDamage) {
#line 108 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
INDEX iAnim ;
#line 109 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(m_bInAir ){
#line 110 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
iAnim  = WOMAN_ANIM_AIRWOUND02 ;
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}else {
#line 112 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
iAnim  = WOMAN_ANIM_GROUNDWOUND04 ;
#line 113 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 114 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (iAnim  , 0);
#line 115 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return iAnim ;
#line 116 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
INDEX CWoman::AnimForDeath(void) {
#line 120 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
INDEX iAnim ;
#line 121 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(m_bInAir ){
#line 122 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
iAnim  = WOMAN_ANIM_AIRDEATH ;
#line 123 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}else {
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
iAnim  = WOMAN_ANIM_GROUNDDEATH01 ;
#line 125 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 126 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (iAnim  , 0);
#line 127 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return iAnim ;
#line 128 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 130 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
FLOAT CWoman::WaitForDust(FLOAT3D & vStretch) {
#line 131 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(GetModelObject  () -> GetAnim  () == WOMAN_ANIM_AIRDEATH )
#line 132 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
{
#line 133 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
vStretch  = FLOAT3D (1 , 1 , 2) * 1.0f;
#line 134 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return 0.6f;
#line 135 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 136 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
else if(GetModelObject  () -> GetAnim  () == WOMAN_ANIM_GROUNDDEATH01 )
#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
{
#line 138 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
vStretch  = FLOAT3D (1 , 1 , 2) * 0.75f;
#line 139 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return 0.525f;
#line 140 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 141 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return - 1.0f;
#line 142 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 144 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::DeathNotify(void) {
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
ChangeCollisionBoxIndexWhenPossible  (WOMAN_COLLISION_BOX_DEATH );
#line 146 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
en_fDensity  = 500.0f;
#line 147 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 150 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::StandingAnim(void) {
#line 151 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(m_bInAir ){
#line 152 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_AIRSTAND  , AOF_LOOPING  | AOF_NORESTART );
#line 153 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}else {
#line 154 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_GROUNDSTAND  , AOF_LOOPING  | AOF_NORESTART );
#line 155 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 156 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 157 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::WalkingAnim(void) {
#line 158 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(m_bInAir ){
#line 159 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_AIRFLY  , AOF_LOOPING  | AOF_NORESTART );
#line 160 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}else {
#line 161 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_GROUNDWALK  , AOF_LOOPING  | AOF_NORESTART );
#line 162 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 163 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 164 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::RunningAnim(void) {
#line 165 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(m_bInAir ){
#line 166 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_AIRFLY  , AOF_LOOPING  | AOF_NORESTART );
#line 167 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}else {
#line 168 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_GROUNDRUN  , AOF_LOOPING  | AOF_NORESTART );
#line 169 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 170 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 171 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::RotatingAnim(void) {
#line 172 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(m_bInAir ){
#line 173 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_AIRFLY  , AOF_LOOPING  | AOF_NORESTART );
#line 174 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}else {
#line 175 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_GROUNDWALK  , AOF_LOOPING  | AOF_NORESTART );
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 177 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 178 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
FLOAT CWoman::AirToGroundAnim(void) {
#line 179 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_AIRTOGROUND  , 0);
#line 180 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return (GetModelObject  () -> GetAnimLength  (WOMAN_ANIM_AIRTOGROUND ));
#line 181 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 182 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
FLOAT CWoman::GroundToAirAnim(void) {
#line 183 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_GROUNDTOAIR  , 0);
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return (GetModelObject  () -> GetAnimLength  (WOMAN_ANIM_GROUNDTOAIR ));
#line 185 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 186 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::ChangeCollisionToAir() {
#line 187 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
ChangeCollisionBoxIndexWhenPossible  (WOMAN_COLLISION_BOX_AIR );
#line 188 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 189 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::ChangeCollisionToGround() {
#line 190 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
ChangeCollisionBoxIndexWhenPossible  (WOMAN_COLLISION_BOX_GROUND );
#line 191 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 194 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::IdleSound(void) {
#line 195 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PlaySound  (m_soSound  , SOUND_IDLE  , SOF_3D );
#line 196 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::SightSound(void) {
#line 198 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PlaySound  (m_soSound  , SOUND_SIGHT  , SOF_3D );
#line 199 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 200 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::WoundSound(void) {
#line 201 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PlaySound  (m_soSound  , SOUND_WOUND  , SOF_3D );
#line 202 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 203 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::DeathSound(void) {
#line 204 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PlaySound  (m_soSound  , SOUND_DEATH  , SOF_3D );
#line 205 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 207 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::AttachKamikaze() 
#line 208 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
{
#line 209 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
AddAttachmentToModel  (this  , * GetModelObject  () , WOMAN_ATTACHMENT_KAMIKAZE  , MODEL_HEADMAN  , TEXTURE_HEADMAN  , 0 , 0 , 0);
#line 210 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
CModelObject & amo  = GetModelObject  () -> GetAttachmentModel  (WOMAN_ATTACHMENT_KAMIKAZE ) -> amo_moModelObject ;
#line 211 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
AddAttachmentToModel  (this  , amo  , HEADMAN_ATTACHMENT_BOMB_RIGHT_HAND  , MODEL_BOMB  , TEXTURE_BOMB  , 0 , 0 , 0);
#line 212 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
AddAttachmentToModel  (this  , amo  , HEADMAN_ATTACHMENT_BOMB_LEFT_HAND  , MODEL_BOMB  , TEXTURE_BOMB  , 0 , 0 , 0);
#line 213 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
amo  . PlayAnim  (HEADMAN_ANIM_KAMIKAZE_ATTACK  , AOF_LOOPING );
#line 214 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_bKamikazeAttached  = TRUE ;
#line 215 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 217 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::RemoveKamikaze() 
#line 218 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
{
#line 219 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
RemoveAttachmentFromModel  (* GetModelObject  () , WOMAN_ATTACHMENT_KAMIKAZE );
#line 220 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 222 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::DropKamikaze() 
#line 223 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
{
#line 224 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(! m_bKamikazeAttached ){return ;}
#line 226 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
CEntity  * pen  = NULL ;
#line 228 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
CPlacement3D pl ;
#line 229 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
pl  = GetPlacement  ();
#line 230 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
pl  . pl_PositionVector  += KAMIKAZE_ATTACH  * GetRotationMatrix  ();
#line 231 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
pen  = CreateEntity  (pl  , CLASS_HEADMAN );
#line 233 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
((CHeadman  *) & * pen ) -> m_hdtType  = HDT_KAMIKAZE ;
#line 236 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
pen  -> End  ();
#line 238 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
CEnemyBase  * peb  = ((CEnemyBase  *) pen );
#line 239 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
peb  -> m_bTemplate  = FALSE ;
#line 240 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
pen  -> Initialize  ();
#line 243 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_bKamikazeAttached  = FALSE ;
#line 246 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
RemoveKamikaze  ();
#line 247 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 250 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::PreMoving() {
#line 251 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(m_bKamikazeAttached  && m_bKamikazeCarrier ){
#line 253 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
INDEX ctMaxPlayers  = GetMaxPlayers  ();
#line 254 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
CEntity  * penPlayer ;
#line 255 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
for(INDEX i  = 0;i  < ctMaxPlayers ;i  ++){
#line 256 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
penPlayer  = GetPlayerEntity  (i );
#line 257 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(penPlayer  != NULL ){
#line 258 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(DistanceTo  (this  , penPlayer ) < m_rKamikazeDropDistance  && IsVisible  (penPlayer )){
#line 259 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
DropKamikaze  ();
#line 260 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 261 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 262 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 263 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 264 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
CEnemyFly  :: PreMoving  ();
#line 265 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
  
#line 267 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
void CWoman::BlowUp(void) 
#line 268 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
{
#line 269 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
DropKamikaze  ();
#line 270 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
CEnemyFly  :: BlowUp  ();
#line 271 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
BOOL CWoman::
#line 278 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
FlyFire(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWoman_FlyFire
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWoman::FlyFire expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 279 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(m_bKamikazeAttached ){Return(STATE_CURRENT,EReturn  ());return TRUE;}
#line 282 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_AIRATTACK02  , 0);
#line 283 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetTimerAfter(0.6f);
Jump(STATE_CURRENT, 0x01400001, FALSE, EBegin());return TRUE;}BOOL CWoman::H0x01400001_FlyFire_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01400002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CWoman::H0x01400002_FlyFire_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400002
;
#line 284 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
ShootProjectile  (PRT_WOMAN_FIRE  , FIRE_AIR  , ANGLE3D (0 , 0 , 0));
#line 285 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PlaySound  (m_soSound  , SOUND_FIRE  , SOF_3D );
#line 286 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetTimerAfter(0.6f);
Jump(STATE_CURRENT, 0x01400003, FALSE, EBegin());return TRUE;}BOOL CWoman::H0x01400003_FlyFire_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01400004, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CWoman::H0x01400004_FlyFire_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400004
;
#line 287 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StandingAnim  ();
#line 288 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetTimerAfter(FRnd  () / 2 + _pTimer  -> TickQuantum );
Jump(STATE_CURRENT, 0x01400005, FALSE, EBegin());return TRUE;}BOOL CWoman::H0x01400005_FlyFire_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400005
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01400006, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CWoman::H0x01400006_FlyFire_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400006
;
#line 290 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
Return(STATE_CURRENT,EReturn  ());
#line 290 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CWoman::
#line 293 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
FlyHit(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWoman_FlyHit
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWoman::FlyHit expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 294 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(m_bKamikazeAttached ){Return(STATE_CURRENT,EReturn  ());return TRUE;}
#line 297 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(CalcDist  (m_penEnemy ) <= 5.0f){
#line 299 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
CMovableEntity  * pen  = (CMovableEntity  *) & * m_penEnemy ;
#line 300 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
CContentType  & ctDn  = pen  -> en_pwoWorld  -> wo_actContentTypes  [ pen  -> en_iDnContent  ];
#line 301 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
BOOL bEnemySwimming  = ! (ctDn  . ct_ulFlags  & CTF_BREATHABLE_LUNGS );
#line 302 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(bEnemySwimming ){
#line 303 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
Jump(STATE_CURRENT, STATE_CWoman_FlyFire, TRUE, EVoid());return TRUE;
#line 304 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}else {
#line 305 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
Jump(STATE_CURRENT, STATE_CWoman_FlyOnEnemy, TRUE, EVoid());return TRUE;
#line 306 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 307 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 310 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fShootTime  = _pTimer  -> CurrentTick  () + 0.25f;
#line 311 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
Return(STATE_CURRENT,EReturn  ());
#line 311 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CWoman::
#line 317 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
Death(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWoman_Death
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWoman::Death expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 318 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
DropKamikaze  ();
#line 319 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
Jump(STATE_CURRENT, STATE_CEnemyFly_Death, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};BOOL CWoman::
#line 322 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
AirToGround(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWoman_AirToGround
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWoman::AirToGround expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 323 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
DropKamikaze  ();
#line 324 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
Jump(STATE_CURRENT, STATE_CEnemyFly_AirToGround, FALSE, EVoid  ());return TRUE; ASSERT(FALSE); return TRUE;};BOOL CWoman::
#line 327 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
FlyOnEnemy(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWoman_FlyOnEnemy
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWoman::FlyOnEnemy expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 328 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_AIRATTACK01  , 0);
#line 331 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
FLOAT3D vDir  = PlayerDestinationPos  ();
#line 332 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
vDir  = (vDir  - GetPlacement  () . pl_PositionVector ) . Normalize  ();
#line 333 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
vDir  *= ! GetRotationMatrix  ();
#line 334 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
vDir  *= m_fFlyCloseRunSpeed  * 1.9f;
#line 335 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetDesiredTranslation  (vDir );
#line 336 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PlaySound  (m_soSound  , SOUND_KICK  , SOF_3D );
#line 339 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SpawnReminder  (this  , 0.9f , 0);
#line 340 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_iChargeHitAnimation  = WOMAN_ANIM_AIRATTACK01 ;
#line 341 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fChargeHitDamage  = 20.0f;
#line 342 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fChargeHitAngle  = 0.0f;
#line 343 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fChargeHitSpeed  = 10.0f;
#line 344 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
STATE_CEnemyBase_ChargeHitEnemy, FALSE;
Jump(STATE_CURRENT, 0x0140000b, FALSE, EBegin());return TRUE;}BOOL CWoman::H0x0140000b_FlyOnEnemy_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0140000b
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CEnemyBase_ChargeHitEnemy, FALSE, EVoid());return TRUE;case EVENTCODE_EReturn: Jump(STATE_CURRENT,0x0140000c, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CWoman::H0x0140000c_FlyOnEnemy_02(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x0140000c
const EReturn&__e= (EReturn&)__eeInput;
;
#line 346 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StandingAnim  ();
#line 347 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetTimerAfter(0.3f);
Jump(STATE_CURRENT, 0x0140000d, FALSE, EBegin());return TRUE;}BOOL CWoman::H0x0140000d_FlyOnEnemy_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0140000d
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0140000e, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CWoman::H0x0140000e_FlyOnEnemy_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0140000e
;
#line 348 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
Return(STATE_CURRENT,EReturn  ());
#line 348 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CWoman::
#line 351 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
GroundFire(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWoman_GroundFire
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWoman::GroundFire expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 353 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_GROUNDATTACK02  , 0);
#line 354 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetTimerAfter(0.3f);
Jump(STATE_CURRENT, 0x01400010, FALSE, EBegin());return TRUE;}BOOL CWoman::H0x01400010_GroundFire_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400010
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01400011, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CWoman::H0x01400011_GroundFire_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400011
;
#line 355 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
ShootProjectile  (PRT_WOMAN_FIRE  , FIRE_GROUND  , ANGLE3D (0 , 0 , 0));
#line 356 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PlaySound  (m_soSound  , SOUND_FIRE  , SOF_3D );
#line 357 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetTimerAfter(0.3f);
Jump(STATE_CURRENT, 0x01400012, FALSE, EBegin());return TRUE;}BOOL CWoman::H0x01400012_GroundFire_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400012
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01400013, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CWoman::H0x01400013_GroundFire_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400013
;
#line 358 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StandingAnim  ();
#line 359 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetTimerAfter(FRnd  () / 2 + _pTimer  -> TickQuantum );
Jump(STATE_CURRENT, 0x01400014, FALSE, EBegin());return TRUE;}BOOL CWoman::H0x01400014_GroundFire_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400014
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01400015, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CWoman::H0x01400015_GroundFire_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400015
;
#line 361 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
Return(STATE_CURRENT,EReturn  ());
#line 361 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CWoman::
#line 364 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
GroundHit(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWoman_GroundHit
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWoman::GroundHit expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 365 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StartModelAnim  (WOMAN_ANIM_GROUNDATTACK01  , 0);
#line 368 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
FLOAT3D vDir  = (m_penEnemy  -> GetPlacement  () . pl_PositionVector  - 
#line 369 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
GetPlacement  () . pl_PositionVector ) . Normalize  ();
#line 370 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
vDir  *= ! GetRotationMatrix  ();
#line 371 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
vDir  *= m_fCloseRunSpeed  * 1.75f;
#line 372 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
vDir  (2) = 2.5f;
#line 373 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetDesiredTranslation  (vDir );
#line 374 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
PlaySound  (m_soSound  , SOUND_KICK  , SOF_3D );
#line 377 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SpawnReminder  (this  , 0.9f , 0);
#line 378 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_iChargeHitAnimation  = WOMAN_ANIM_GROUNDATTACK01 ;
#line 379 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fChargeHitDamage  = 20.0f;
#line 380 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fChargeHitAngle  = 0.0f;
#line 381 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fChargeHitSpeed  = 10.0f;
#line 382 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
STATE_CEnemyBase_ChargeHitEnemy, FALSE;
Jump(STATE_CURRENT, 0x01400017, FALSE, EBegin());return TRUE;}BOOL CWoman::H0x01400017_GroundHit_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400017
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CEnemyBase_ChargeHitEnemy, FALSE, EVoid());return TRUE;case EVENTCODE_EReturn: Jump(STATE_CURRENT,0x01400018, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CWoman::H0x01400018_GroundHit_02(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400018
const EReturn&__e= (EReturn&)__eeInput;
;
#line 384 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
StandingAnim  ();
#line 385 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetTimerAfter(0.3f);
Jump(STATE_CURRENT, 0x01400019, FALSE, EBegin());return TRUE;}BOOL CWoman::H0x01400019_GroundHit_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01400019
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0140001a, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CWoman::H0x0140001a_GroundHit_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0140001a
;
#line 386 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
Return(STATE_CURRENT,EReturn  ());
#line 386 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CWoman::
#line 394 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWoman_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWoman::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 396 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
InitAsModel  ();
#line 397 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetPhysicsFlags  (EPF_MODEL_WALKING  | EPF_HASLUNGS );
#line 398 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetCollisionFlags  (ECF_MODEL );
#line 399 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetFlags  (GetFlags  () | ENF_ALIVE );
#line 400 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetHealth  (100.0f);
#line 401 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fMaxHealth  = 100.0f;
#line 402 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
en_tmMaxHoldBreath  = 5.0f;
#line 403 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
en_fDensity  = 2000.0f;
#line 405 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_sptType  = SPT_FEATHER ;
#line 408 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetModel  (MODEL_WOMAN );
#line 409 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetModelMainTexture  (TEXTURE_WOMAN );
#line 411 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fWalkSpeed  = FRnd  () + 1.5f;
#line 412 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_aWalkRotateSpeed  = FRnd  () * 10.0f + 25.0f;
#line 413 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fAttackRunSpeed  = FRnd  () * 2.0f + 9.0f;
#line 414 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_aAttackRotateSpeed  = FRnd  () * 50 + 245.0f;
#line 415 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fCloseRunSpeed  = FRnd  () * 2.0f + 4.0f;
#line 416 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_aCloseRotateSpeed  = FRnd  () * 50 + 245.0f;
#line 418 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fAttackDistance  = 50.0f;
#line 419 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fCloseDistance  = 5.0f;
#line 420 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fStopDistance  = 0.0f;
#line 421 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fAttackFireTime  = 3.0f;
#line 422 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fCloseFireTime  = 2.0f;
#line 423 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fIgnoreRange  = 200.0f;
#line 425 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fFlyWalkSpeed  = FRnd  () / 2 + 1.0f;
#line 426 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_aFlyWalkRotateSpeed  = FRnd  () * 10.0f + 25.0f;
#line 427 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fFlyAttackRunSpeed  = FRnd  () * 2.0f + 10.0f;
#line 428 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_aFlyAttackRotateSpeed  = FRnd  () * 25 + 150.0f;
#line 429 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fFlyCloseRunSpeed  = FRnd  () * 2.0f + 10.0f;
#line 430 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_aFlyCloseRotateSpeed  = FRnd  () * 50 + 500.0f;
#line 431 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fGroundToAirSpeed  = m_fFlyCloseRunSpeed ;
#line 432 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fAirToGroundSpeed  = m_fFlyCloseRunSpeed ;
#line 433 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fAirToGroundMin  = 0.1f;
#line 434 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fAirToGroundMax  = 0.1f;
#line 436 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fFlyAttackDistance  = 50.0f;
#line 437 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fFlyCloseDistance  = 12.5f;
#line 438 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fFlyStopDistance  = 0.0f;
#line 439 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fFlyAttackFireTime  = 3.0f;
#line 440 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fFlyCloseFireTime  = 2.0f;
#line 441 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fFlyIgnoreRange  = 200.0f;
#line 443 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fBlowUpAmount  = 100.0f;
#line 444 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fBodyParts  = 4;
#line 445 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_fDamageWounded  = 20.0f;
#line 446 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
m_iScore  = 1000;
#line 448 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
if(m_bKamikazeCarrier ){
#line 449 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
AttachKamikaze  ();
#line 450 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
}
#line 452 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
SetTimerAfter(0.05f);
Jump(STATE_CURRENT, 0x0140001b, FALSE, EBegin());return TRUE;}BOOL CWoman::H0x0140001b_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0140001b
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0140001c, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CWoman::H0x0140001c_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0140001c
;
#line 455 "V:/Programs/SamSDK/Sources/EntitiesMP/Woman.es"
Jump(STATE_CURRENT, STATE_CEnemyFly_MainLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};