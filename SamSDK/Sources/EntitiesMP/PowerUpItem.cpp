/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"

#include "StdH.h"
#include "Models/Items/ItemHolder/ItemHolder.h"

#include <EntitiesMP/PowerUpItem.h>
#include <EntitiesMP/PowerUpItem_tables.h>
CEntityEvent *EPowerUp::MakeCopy(void) { CEntityEvent *peeCopy = new EPowerUp(*this); return peeCopy;}
EPowerUp::EPowerUp() : CEntityEvent(EVENTCODE_EPowerUp) {;
 ClearToDefault(puitType);
};
void CPowerUpItem::SetDefaultProperties(void) {
  m_puitType = PUIT_INVULNER ;
  CItem::SetDefaultProperties();
}
  
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
void CPowerUpItem::Precache(void) 
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
{
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
switch(m_puitType ){
#line 78 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_INVISIB : 
#line 79 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_INVULNER : 
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_DAMAGE : 
#line 81 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_SPEED : 
#line 82 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
PrecacheSound  (SOUND_PICKUP );break ;
#line 83 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_BOMB : PrecacheSound  (SOUND_BOMB );break ;
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 85 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
  
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
BOOL CPowerUpItem::FillEntityStatistics(EntityStats * pes) 
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
{
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
pes  -> es_strName  = "PowerUp";
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
pes  -> es_ctCount  = 1;
#line 92 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
pes  -> es_ctAmmount  = 1;
#line 93 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
pes  -> es_fValue  = 0;
#line 94 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
pes  -> es_iScore  = 0;
#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
switch(m_puitType ){
#line 97 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_INVISIB : pes  -> es_strName  += " invisibility";break ;
#line 98 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_INVULNER : pes  -> es_strName  += " invulnerability";break ;
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_DAMAGE : pes  -> es_strName  += " serious damage";break ;
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_SPEED : pes  -> es_strName  += " serious speed";break ;
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_BOMB : pes  -> es_strName  = "Serious Bomb!";
#line 102 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
return TRUE ;
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
  
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
void CPowerUpItem::RenderParticles(void) 
#line 108 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
{
#line 110 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
if(GetRenderType  () != CEntity  :: RT_MODEL  || GetSP  () -> sp_gmGameMode  > CSessionProperties  :: GM_COOPERATIVE  
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
|| ! ShowItemParticles  ()){
#line 112 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
return ;
#line 113 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 114 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
switch(m_puitType ){
#line 115 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_INVISIB : 
#line 116 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
Particles_Stardust  (this  , 2.0f * 0.75f , 1.00f * 0.75f , PT_STAR08  , 320);
#line 117 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
break ;
#line 118 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_INVULNER : 
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
Particles_Stardust  (this  , 2.0f * 0.75f , 1.00f * 0.75f , PT_STAR08  , 192);
#line 120 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
break ;
#line 121 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_DAMAGE : 
#line 122 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
Particles_Stardust  (this  , 1.0f * 0.75f , 0.75f * 0.75f , PT_STAR08  , 128);
#line 123 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
break ;
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_SPEED : 
#line 125 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
Particles_Stardust  (this  , 1.0f * 0.75f , 0.75f * 0.75f , PT_STAR08  , 128);
#line 126 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
break ;
#line 127 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_BOMB : 
#line 128 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
Particles_Atomic  (this  , 2.0f * 0.75f , 2.0f * 0.95f , PT_STAR05  , 12);
#line 129 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
break ;
#line 130 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 131 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
  
#line 134 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
void CPowerUpItem::SetProperties(void) 
#line 135 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
{
#line 136 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
switch(m_puitType )
#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
{
#line 138 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_INVISIB : 
#line 139 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
StartModelAnim  (ITEMHOLDER_ANIM_SMALLOSCILATION  , AOF_LOOPING  | AOF_NORESTART );
#line 140 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_BIG );
#line 141 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 40.0f;
#line 142 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_strDescription  . PrintF  ("Invisibility");
#line 143 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
AddItem  (MODEL_INVISIB  , TEXTURE_REFLECTION_METAL  , 0 , TEXTURE_SPECULAR_STRONG  , 0);
#line 144 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.2f , 0) , FLOAT3D (1 , 1 , 0.3f));
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
StretchItem  (FLOAT3D (1.0f * 0.75f , 1.0f * 0.75f , 1.0f * 0.75));
#line 146 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
break ;
#line 147 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_INVULNER : 
#line 148 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
StartModelAnim  (ITEMHOLDER_ANIM_SMALLOSCILATION  , AOF_LOOPING  | AOF_NORESTART );
#line 149 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_BIG );
#line 150 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 60.0f;
#line 151 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_strDescription  . PrintF  ("Invulnerability");
#line 152 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
AddItem  (MODEL_INVULNER  , TEXTURE_REFLECTION_GOLD  , TEXTURE_REFLECTION_METAL  , TEXTURE_SPECULAR_MEDIUM  , 0);
#line 153 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.2f , 0) , FLOAT3D (1 , 1 , 0.3f));
#line 154 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
StretchItem  (FLOAT3D (1.0f * 0.75f , 1.0f * 0.75f , 1.0f * 0.75));
#line 155 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
break ;
#line 156 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_DAMAGE : 
#line 157 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
StartModelAnim  (ITEMHOLDER_ANIM_SMALLOSCILATION  , AOF_LOOPING  | AOF_NORESTART );
#line 158 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_BIG );
#line 159 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 40.0f;
#line 160 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_strDescription  . PrintF  ("SeriousDamage");
#line 161 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
AddItem  (MODEL_DAMAGE  , TEXTURE_DAMAGE  , 0 , TEXTURE_SPECULAR_STRONG  , 0);
#line 162 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.2f , 0) , FLOAT3D (1 , 1 , 0.3f));
#line 163 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
StretchItem  (FLOAT3D (1.0f * 0.75f , 1.0f * 0.75f , 1.0f * 0.75));
#line 164 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
break ;
#line 165 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_SPEED : 
#line 166 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
StartModelAnim  (ITEMHOLDER_ANIM_SMALLOSCILATION  , AOF_LOOPING  | AOF_NORESTART );
#line 167 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_BIG );
#line 168 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 40.0f;
#line 169 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_strDescription  . PrintF  ("SeriousSpeed");
#line 170 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
AddItem  (MODEL_SPEED  , TEXTURE_SPEED  , 0 , 0 , 0);
#line 171 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.2f , 0) , FLOAT3D (1 , 1 , 0.3f));
#line 172 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
StretchItem  (FLOAT3D (1.0f * 0.75f , 1.0f * 0.75f , 1.0f * 0.75));
#line 173 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
break ;
#line 174 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_BOMB : 
#line 175 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
StartModelAnim  (ITEMHOLDER_ANIM_SMALLOSCILATION  , AOF_LOOPING  | AOF_NORESTART );
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_BIG );
#line 177 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 40.0f;
#line 178 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_strDescription  . PrintF  ("Serious Bomb!");
#line 179 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
AddItem  (MODEL_BOMB  , TEXTURE_BOMB  , 0 , 0 , 0);
#line 180 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.2f , 0) , FLOAT3D (1 , 1 , 0.3f));
#line 181 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
StretchItem  (FLOAT3D (1.0f * 3.0f , 1.0f * 3.0f , 1.0f * 3.0));
#line 182 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
break ;
#line 183 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
BOOL CPowerUpItem::
#line 189 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
ItemCollected(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CPowerUpItem_ItemCollected
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EPass, "CPowerUpItem::ItemCollected expects 'EPass' as input!");  const EPass &epass = (const EPass &)__eeInput;
#line 191 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
ASSERT  (epass  . penOther  != NULL );
#line 194 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
if(m_puitType  == PUIT_BOMB ){
#line 195 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
if(IsOfClass  (epass  . penOther  , "Player")){
#line 196 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
if(((CPlayer  &) * epass  . penOther ) . m_iSeriousBombCount  >= 3){
#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
Return(STATE_CURRENT,EVoid());
#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
return TRUE;
#line 198 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 199 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 200 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 202 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
if(! (m_bPickupOnce  || m_bRespawn )){
#line 204 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
BOOL bWasPicked  = MarkPickedBy  (epass  . penOther );
#line 205 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
if(bWasPicked ){
#line 207 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
Return(STATE_CURRENT,EVoid());
#line 207 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
return TRUE;
#line 208 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 209 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 212 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
EPowerUp  ePowerUp ;
#line 213 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
ePowerUp  . puitType  = m_puitType ;
#line 215 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
if(epass  . penOther  -> ReceiveItem  (ePowerUp )){
#line 217 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
if(_pNetwork  -> IsPlayerLocal  (epass  . penOther ))
#line 218 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
{
#line 219 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
switch(m_puitType )
#line 220 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
{
#line 221 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_INVISIB : IFeel_PlayEffect  ("PU_Invulnerability");break ;
#line 222 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_INVULNER : IFeel_PlayEffect  ("PU_Invulnerability");break ;
#line 223 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_DAMAGE : IFeel_PlayEffect  ("PU_Invulnerability");break ;
#line 224 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_SPEED : IFeel_PlayEffect  ("PU_FastShoes");break ;
#line 225 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
case PUIT_BOMB : IFeel_PlayEffect  ("PU_SeriousBomb");break ;
#line 226 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 227 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 230 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_soPick  . Set3DParameters  (50.0f , 1.0f , 2.0f , 1.0f);
#line 231 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
if(m_puitType  == PUIT_BOMB ){
#line 232 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
PlaySound  (m_soPick  , SOUND_BOMB  , SOF_3D );
#line 233 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_fPickSoundLen  = GetSoundLength  (SOUND_BOMB );
#line 234 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}else if(TRUE ){
#line 235 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
PlaySound  (m_soPick  , SOUND_PICKUP  , SOF_3D );
#line 236 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
m_fPickSoundLen  = GetSoundLength  (SOUND_PICKUP );
#line 237 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 238 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
if((m_bPickupOnce  || m_bRespawn )){Jump(STATE_CURRENT, STATE_CItem_ItemReceived, FALSE, EVoid());return TRUE;}
#line 239 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
}
#line 240 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
Return(STATE_CURRENT,EVoid());
#line 240 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CPowerUpItem::
#line 244 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CPowerUpItem_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CPowerUpItem::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 246 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
Initialize  ();
#line 247 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
SetProperties  ();
#line 248 "V:/Programs/SamSDK/Sources/EntitiesMP/PowerUpItem.es"
Jump(STATE_CURRENT, STATE_CItem_ItemLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};