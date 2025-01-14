/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"

#include "StdH.h"
#include "ModelsMP/Enemies/AirElemental/Twister.h"

#define ECF_TWISTER ( \
  ((ECBI_BRUSH|ECBI_MODEL|ECBI_CORPSE|ECBI_ITEM|ECBI_PROJECTILE_MAGIC|ECBI_PROJECTILE_SOLID)<<ECB_TEST) |\
  ((ECBI_MODEL|ECBI_CORPSE|ECBI_ITEM|ECBI_PROJECTILE_MAGIC|ECBI_PROJECTILE_SOLID)<<ECB_PASS) |\
  ((ECBI_MODEL)<<ECB_IS))
#define EPF_TWISTER ( \
  EPF_ONBLOCK_CLIMBORSLIDE|EPF_ORIENTEDBYGRAVITY|\
  EPF_TRANSLATEDBYGRAVITY|EPF_MOVABLE|EPF_ABSOLUTETRANSLATE)

#include <EntitiesMP/Twister.h>
#include <EntitiesMP/Twister_tables.h>
CEntityEvent *ETwister::MakeCopy(void) { CEntityEvent *peeCopy = new ETwister(*this); return peeCopy;}
ETwister::ETwister() : CEntityEvent(EVENTCODE_ETwister) {;
 ClearToDefault(penOwner);
 ClearToDefault(fSize);
 ClearToDefault(fDuration);
 ClearToDefault(sgnSpinDir);
 ClearToDefault(bGrow);
 ClearToDefault(bMovingAllowed);
};
#line 32 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"

static EntityInfo eiTwister = {
  EIBT_AIR, 0.0f,
  0.0f, 1.0f, 0.0f,
  0.0f, 0.75f, 0.0f,
};


#define MOVE_FREQUENCY 0.1f
#define ROTATE_SPEED 10000.0f
#define MOVE_SPEED 7.5f

void CTwister_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) 
{
  pdec->PrecacheClass(CLASS_SPINNER);
  pdec->PrecacheModel(MODEL_TWISTER);
  pdec->PrecacheTexture(TEXTURE_TWISTER);
  pdec->PrecacheSound(SOUND_SPIN);
}

void CTwister::SetDefaultProperties(void) {
  m_penOwner = NULL;
  m_fSize = 1.0f;
  m_vSpeed = FLOAT3D(0 , 0 , 0);
  m_sgnSpinDir = 1;
  m_bGrow = TRUE ;
  m_tmLastMove = 0.0f;
  m_aSpeedRotation = FLOAT3D(0 , 0 , 0);
  m_bMoving = FALSE ;
  m_bMovingAllowed = TRUE ;
  m_vDesiredPosition = FLOAT3D(0 , 0 , 0);
  m_vDesiredAngle = FLOAT3D(0 , 0 , 0);
  m_fStopTime = 0.0f;
  m_fActionRadius = 0.0f;
  m_fActionTime = 0.0f;
  m_fDiffMultiply = 0.0f;
  m_fUpMultiply = 0.0f;
  m_bFadeOut = FALSE ;
  m_fFadeStartTime = 1e6;
  m_fFadeTime = 2.0f;
  m_fStartTime = 0.0f;
  m_soSpin.SetOwner(this);
m_soSpin.Stop_internal();
  CMovableModelEntity::SetDefaultProperties();
}
  
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
void * CTwister::GetEntityInfo(void) {
#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
return & eiTwister ;
#line 97 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
  
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
void CTwister::ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection) 
#line 102 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
{
#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
return ;
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
  
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
void CTwister::RenderParticles(void) 
#line 108 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
{
#line 109 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(m_bMovingAllowed )
#line 110 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
{
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
Particles_Twister  (this  , m_fSize  / 15.0f , m_fStartTime  , m_fFadeStartTime  , 1.0f);
#line 112 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 113 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
else 
#line 114 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
{
#line 115 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
CEntity  * penParent  = GetParent  ();
#line 116 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
FLOAT fStretch  = 1.0f;
#line 117 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(penParent  != NULL )
#line 118 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
{
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
CAirElemental  * penAir  = (CAirElemental  *) penParent ;
#line 120 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
FLOAT fStretchRatio  = penAir  -> GetCurrentStretchRatio  ();
#line 121 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
fStretch  = 1.0f + (fStretchRatio ) * 6.0f;
#line 122 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 123 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
Particles_Twister  (this  , m_fSize  / 15.0f * fStretch  , m_fStartTime  , m_fFadeStartTime  , 0.5f * fStretch );
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 125 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
  
#line 130 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
BOOL CTwister::AdjustShadingParameters(FLOAT3D & vLightDirection,COLOR & colLight,COLOR & colAmbient) {
#line 132 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(m_bFadeOut ){
#line 133 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
FLOAT fTimeRemain  = m_fFadeStartTime  + m_fFadeTime  - _pTimer  -> CurrentTick  ();
#line 134 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(fTimeRemain  < 0.0f){fTimeRemain  = 0.0f;}
#line 135 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
COLOR colAlpha  = GetModelObject  () -> mo_colBlendColor ;
#line 136 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
colAlpha  = (colAlpha  & 0xffffff00) + (COLOR (fTimeRemain  / m_fFadeTime  * 0xff) & 0xff);
#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
GetModelObject  () -> mo_colBlendColor  = colAlpha ;
#line 138 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 139 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
return CMovableModelEntity  :: AdjustShadingParameters  (vLightDirection  , colLight  , colAmbient );
#line 140 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
  
#line 147 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
void CTwister::SpinEntity(CEntity * pen) {
#line 150 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(IsOfClass  (pen  , "AirElemental") || IsOfClass  (pen  , "Twister") 
#line 151 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
|| IsDerivedFromClass  (pen  , "Item")){
#line 152 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
return ;
#line 153 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 155 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(IsOfClass  (pen  , "Projectile")){
#line 156 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(((CProjectile  *) & * pen ) -> m_prtType  == PRT_AIRELEMENTAL_WIND )
#line 157 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
{
#line 158 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
return ;
#line 159 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 160 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 164 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(pen  -> GetPhysicsFlags  () & EPF_MOVABLE ){
#line 166 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
BOOL bNoSpinner  = TRUE ;
#line 167 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
{FOREACHINLIST  (CEntity  , en_lnInParent  , pen  -> en_lhChildren  , iten ){
#line 168 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(IsOfClass  (iten  , "Spinner"))
#line 169 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
{
#line 170 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
bNoSpinner  = FALSE ;
#line 171 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
return ;
#line 172 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 173 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}}
#line 174 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(bNoSpinner ){
#line 175 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
ESpinnerInit  esi ;
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
CEntityPointer penSpinner ;
#line 177 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . penParent  = pen ;
#line 178 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . penTwister  = this ;
#line 179 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . bImpulse  = FALSE ;
#line 182 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(IsOfClass  (pen  , "Projectile"))
#line 183 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
{
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
switch(((CProjectile  &) * pen ) . m_prtType ){
#line 185 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
case PRT_GRENADE : 
#line 186 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
case PRT_HEADMAN_BOMBERMAN : 
#line 187 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
case PRT_DEMON_FIREBALL : 
#line 188 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
case PRT_SHOOTER_FIREBALL : 
#line 189 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
case PRT_BEAST_PROJECTILE : 
#line 190 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
case PRT_BEAST_BIG_PROJECTILE : 
#line 191 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
case PRT_LAVA_COMET : 
#line 192 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . tmSpinTime  = 2.5f;
#line 193 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . vRotationAngle  = ANGLE3D (- m_sgnSpinDir  * 250.0f , 0 , 0);
#line 194 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . fUpSpeed  = m_fDiffMultiply  * 0.75;
#line 195 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
break ;
#line 196 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
default  : 
#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . tmSpinTime  = 1.5f;
#line 198 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . vRotationAngle  = ANGLE3D (- m_sgnSpinDir  * 180.0f , 0 , 0);
#line 199 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . fUpSpeed  = m_fDiffMultiply  / 5.0f;
#line 200 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
break ;
#line 201 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 203 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}else if(IsOfClass  (pen  , "Cannon ball")){
#line 204 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . tmSpinTime  = 0.2f;
#line 205 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . vRotationAngle  = ANGLE3D (- m_sgnSpinDir  * 500.0f , 0 , 0);
#line 206 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . fUpSpeed  = m_fDiffMultiply  * 3.0f;
#line 208 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}else if(IsOfClass  (pen  , "Player")){
#line 209 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . tmSpinTime  = 3.0f;
#line 210 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . vRotationAngle  = ANGLE3D (- m_sgnSpinDir  * 220.0f , 0 , 0);
#line 211 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . bImpulse  = TRUE ;
#line 212 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . fUpSpeed  = m_fDiffMultiply  * (0.4f + FRnd  () * 0.4f);
#line 213 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . tmImpulseDuration  = 1.4f + FRnd  () * 0.5f;
#line 215 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}else {
#line 216 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . tmSpinTime  = 0.5f;
#line 217 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . vRotationAngle  = ANGLE3D (- m_sgnSpinDir  * 180.0f , 0 , 0);
#line 218 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
esi  . fUpSpeed  = m_fDiffMultiply ;
#line 219 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 220 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
penSpinner  = CreateEntity  (pen  -> GetPlacement  () , CLASS_SPINNER );
#line 221 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
penSpinner  -> Initialize  (esi );
#line 222 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
penSpinner  -> SetParent  (pen );
#line 223 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 225 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
FLOAT3D vDirection ;
#line 226 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
AnglesToDirectionVector  (GetPlacement  () . pl_OrientationAngle  , vDirection );
#line 227 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
InflictDirectDamage  (pen  , m_penOwner  , DMT_IMPACT  , 2.0f , GetPlacement  () . pl_PositionVector  , vDirection );
#line 228 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 230 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
  
#line 232 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
void CTwister::PreMoving(void) {
#line 234 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(m_bMoving ){
#line 235 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
FLOATmatrix3D m ;
#line 236 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
ANGLE3D aRotation ;
#line 237 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
aRotation  = m_aSpeedRotation  * (_pTimer  -> CurrentTick  () - m_tmLastMove );
#line 238 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
MakeRotationMatrix  (m  , aRotation );
#line 239 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_vSpeed  = m_vSpeed  * m ;
#line 240 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
SetDesiredTranslation  (m_vSpeed );
#line 241 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_tmLastMove  = _pTimer  -> CurrentTick  ();
#line 242 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 243 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
CMovableModelEntity  :: PreMoving  ();
#line 244 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
BOOL CTwister::
#line 252 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CTwister_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_ETwister, "CTwister::Main expects 'ETwister' as input!");  const ETwister &et = (const ETwister &)__eeInput;
#line 254 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
ASSERT  (et  . penOwner  != NULL );
#line 255 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_penOwner  = et  . penOwner ;
#line 256 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_sgnSpinDir  = et  . sgnSpinDir ;
#line 257 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(m_sgnSpinDir  == 0){m_sgnSpinDir  = 1;};
#line 258 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_fSize  = et  . fSize ;
#line 259 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_fStopTime  = _pTimer  -> CurrentTick  () + et  . fDuration ;
#line 260 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_bGrow  = et  . bGrow ;
#line 261 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_bMovingAllowed  = et  . bMovingAllowed ;
#line 264 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
InitAsEditorModel  ();
#line 265 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
SetPhysicsFlags  (EPF_TWISTER );
#line 266 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
SetCollisionFlags  (ECF_TWISTER );
#line 267 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
SetFlags  (GetFlags  () | ENF_SEETHROUGH );
#line 268 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
SetModel  (MODEL_TWISTER );
#line 269 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
SetModelMainTexture  (TEXTURE_TWISTER );
#line 272 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_fActionRadius  = pow  (m_fSize  , 0.33333f) * 10.0f;
#line 273 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_fActionTime  = m_fActionRadius ;
#line 274 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_fUpMultiply  = m_fActionRadius  / 2.0f;
#line 275 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_fDiffMultiply  = sqrt  (m_fSize );
#line 276 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
GetModelObject  () -> StretchModel  (FLOAT3D (m_fSize  , m_fSize  , m_fSize ));
#line 277 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
ModelChangeNotify  ();
#line 279 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_fStartTime  = _pTimer  -> CurrentTick  ();
#line 282 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
SetTimerAfter(FRnd  () * 0.25f);
Jump(STATE_CURRENT, 0x01fb0001, FALSE, EBegin());return TRUE;}BOOL CTwister::H0x01fb0001_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fb0001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01fb0002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CTwister::H0x01fb0002_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fb0002
;
#line 284 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_soSpin  . Set3DParameters  (50.0f , 10.0f , 1.0f , 1.0f);
#line 285 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
PlaySound  (m_soSpin  , SOUND_SPIN  , SOF_3D  | SOF_LOOP );
#line 288 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
SetDesiredRotation  (ANGLE3D (m_sgnSpinDir  * (FRnd  () * 50.0f + 50.0f) , 0.0f , 0.0f));
#line 290 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(m_bGrow ){
#line 291 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
StartModelAnim  (TWISTER_ANIM_GROWING  , AOF_SMOOTHCHANGE  | AOF_NORESTART );
#line 292 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 293 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
SetTimerAfter(GetModelObject  () -> GetAnimLength  (TWISTER_ANIM_GROWING ));
Jump(STATE_CURRENT, 0x01fb0003, FALSE, EBegin());return TRUE;}BOOL CTwister::H0x01fb0003_Main_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fb0003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01fb0004, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CTwister::H0x01fb0004_Main_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fb0004
;
#line 296 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
FLOAT fR  = FRndIn  (5.0f , 10.0f);
#line 297 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
FLOAT fA  = FRnd  () * 360.0f;
#line 298 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_vSpeed  = FLOAT3D (CosFast  (fA ) * fR  , 0 , SinFast  (fA ) * fR );
#line 299 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_bMoving  = m_bMovingAllowed ;
#line 302 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
Jump(STATE_CURRENT,0x01fb0007, FALSE, EInternal());return TRUE;}BOOL CTwister::H0x01fb0007_Main_07(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fb0007
if(!(_pTimer  -> CurrentTick  () < m_fStopTime )){ Jump(STATE_CURRENT,0x01fb0008, FALSE, EInternal());return TRUE;}
#line 303 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
FLOAT fMoveTime  = FRndIn  (2.0f , 4.0f);
#line 304 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_aSpeedRotation  = FLOAT3D (FRndIn  (8.0f , 16.0f) , 0.0f , 0.0f);
#line 305 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_tmLastMove  = _pTimer  -> CurrentTick  ();
#line 308 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
SetTimerAfter(fMoveTime );
Jump(STATE_CURRENT, 0x01fb0005, FALSE, EBegin());return TRUE;}BOOL CTwister::H0x01fb0005_Main_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fb0005
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x01fb0006, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EPass):{const EPass&ep= (EPass&)__eeInput;

#line 312 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
if(ep  . penOther  -> GetRenderType  () & RT_MODEL  && 
#line 313 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
ep  . penOther  -> GetPhysicsFlags  () & EPF_MOVABLE  && 
#line 314 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
! IsOfClass  (ep  . penOther  , "Twister")){
#line 315 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
SpinEntity  (ep  . penOther );
#line 316 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}
#line 317 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
return TRUE;
#line 318 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 319 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}return TRUE;}BOOL CTwister::H0x01fb0006_Main_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fb0006
Jump(STATE_CURRENT,0x01fb0007, FALSE, EInternal());return TRUE;
#line 320 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
}BOOL CTwister::H0x01fb0008_Main_08(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fb0008

#line 323 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_fFadeStartTime  = _pTimer  -> CurrentTick  ();
#line 324 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_bFadeOut  = TRUE ;
#line 325 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
m_fFadeTime  = 2.0f;
#line 326 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
SetTimerAfter(m_fFadeTime );
Jump(STATE_CURRENT, 0x01fb0009, FALSE, EBegin());return TRUE;}BOOL CTwister::H0x01fb0009_Main_09(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fb0009
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01fb000a, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CTwister::H0x01fb000a_Main_10(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fb000a
;
#line 329 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
Destroy  ();
#line 331 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
Return(STATE_CURRENT,EVoid());
#line 331 "V:/Programs/SamSDK/Sources/EntitiesMP/Twister.es"
return TRUE; ASSERT(FALSE); return TRUE;};