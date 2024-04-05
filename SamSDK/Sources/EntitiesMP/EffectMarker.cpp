/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"

#include "StdH.h"
#include "EntitiesMP/Effector.h"
#include "EntitiesMP/BackgroundViewer.h"
#include "EntitiesMP/WorldSettingsController.h"

#include <EntitiesMP/EffectMarker.h>
#include <EntitiesMP/EffectMarker_tables.h>
#line 29 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"

extern void CBasicEffect_OnPrecache(CDLLEntityClass *pdec, INDEX iUser);

void CEffectMarker::SetDefaultProperties(void) {
  m_emtType = EMT_NONE ;
  m_penModel = NULL;
  m_tmEffectLife = 10.0f;
  m_penModel2 = NULL;
  m_penEffector = NULL;
  m_fShakeFalloff = 250.0f;
  m_fShakeFade = 3.0f;
  m_fShakeIntensityY = 0.1f;
  m_fShakeFrequencyY = 5.0f;
  m_fShakeIntensityB = 2.5f;
  m_fShakeFrequencyB = 7.2f;
  m_fShakeIntensityZ = 0.0f;
  m_fShakeFrequencyZ = 5.0f;
  m_betType = BET_ROCKET ;
  m_fStretch = 1.0f;
  m_colColor = COLOR(C_WHITE  | CT_TRANSPARENT );
  CMarker::SetDefaultProperties();
}
  
#line 66 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
void CEffectMarker::Precache(void) 
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 68 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
switch(m_betType )
#line 69 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 70 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_BASIC_EFFECT : 
#line 71 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CDLLEntityClass  * pdec  = & CBasicEffect_DLLClass ;
#line 73 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CBasicEffect_OnPrecache  (pdec  , m_emtType );
#line 74 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
  
#line 79 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
BOOL CEffectMarker::IsTargetValid(SLONG slPropertyOffset,CEntity * penTarget) 
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 81 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(penTarget  == NULL )
#line 82 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 83 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
return FALSE ;
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 86 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(slPropertyOffset  == offsetof  (CEffectMarker  , m_penModel ) || 
#line 87 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
slPropertyOffset  == offsetof  (CEffectMarker  , m_penModel2 ))
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
return IsOfClass  (penTarget  , "ModelHolder2");
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
return TRUE ;
#line 92 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
  
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
BOOL CEffectMarker::HandleEvent(const CEntityEvent & ee) 
#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 97 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(ee  . ee_slEvent  == EVENTCODE_ETrigger )
#line 98 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
switch(m_emtType )
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_SET_PLACEMENT : 
#line 102 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && m_penModel2  != NULL )
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penModel  -> Teleport  (m_penModel2  -> GetPlacement  () , FALSE );
#line 106 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 108 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 109 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_SET_PARENT : 
#line 110 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && m_penModel2  != NULL )
#line 112 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 113 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penModel  -> SetParent  (m_penModel2 );
#line 114 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 115 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 116 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 117 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_CLEAR_PARENT : 
#line 118 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL )
#line 120 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 121 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penModel  -> SetParent  (NULL );
#line 122 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 123 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 125 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_SHAKE_IT_BABY : 
#line 126 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 128 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CWorldSettingsController  * pwsc  = NULL ;
#line 130 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CBackgroundViewer  * penBcgViewer  = (CBackgroundViewer  *) GetWorld  () -> GetBackgroundViewer  ();
#line 131 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(penBcgViewer  != NULL  && penBcgViewer  -> m_penWorldSettingsController  != NULL )
#line 132 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 133 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  = (CWorldSettingsController  *) & * penBcgViewer  -> m_penWorldSettingsController ;
#line 134 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_tmShakeStarted  = _pTimer  -> CurrentTick  ();
#line 135 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_vShakePos  = GetPlacement  () . pl_PositionVector ;
#line 136 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fShakeFalloff  = m_fShakeFalloff ;
#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fShakeFade  = m_fShakeFade ;
#line 138 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fShakeIntensityZ  = m_fShakeIntensityZ ;
#line 139 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_tmShakeFrequencyZ  = m_fShakeFrequencyZ ;
#line 140 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fShakeIntensityY  = m_fShakeIntensityY ;
#line 141 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_tmShakeFrequencyY  = m_fShakeFrequencyY ;
#line 142 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fShakeIntensityB  = m_fShakeIntensityB ;
#line 143 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_tmShakeFrequencyB  = m_fShakeFrequencyB ;
#line 144 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_bShakeFadeIn  = FALSE ;
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 146 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 147 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 148 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_HIDE_ENTITY : 
#line 149 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 150 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penTarget  != NULL )
#line 151 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 152 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penTarget  -> SetFlags  (m_penTarget  -> GetFlags  () | ENF_HIDDEN );
#line 153 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 154 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 155 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 156 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_SHOW_ENTITY : 
#line 157 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 158 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penTarget  != NULL )
#line 159 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 160 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penTarget  -> SetFlags  (m_penTarget  -> GetFlags  () & ~ ENF_HIDDEN );
#line 161 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 162 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 163 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 164 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_PLAYER_APPEAR : 
#line 165 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && IsOfClass  (m_penModel  , "ModelHolder2"))
#line 166 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 167 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo  = m_penModel  -> GetModelObject  ();
#line 168 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(pmo  != NULL )
#line 169 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 171 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = m_penModel  -> GetPlacement  ();
#line 172 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 173 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 174 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 175 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_PORTAL_LIGHTNING ;
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel  = m_penModel ;
#line 177 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 178 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 179 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 180 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 181 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_APPEARING_BIG_BLUE_FLARE : 
#line 182 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = GetPlacement  ();
#line 185 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 186 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 187 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 188 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . fSize  = 1.0f;
#line 189 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_SIZING_BIG_BLUE_FLARE ;
#line 190 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 191 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 192 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 193 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_BLEND_MODELS : 
#line 194 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && IsOfClass  (m_penModel  , "ModelHolder2") && 
#line 195 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penModel2  != NULL  && IsOfClass  (m_penModel2  , "ModelHolder2"))
#line 196 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penEffector  == NULL )
#line 198 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 199 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo1  = m_penModel  -> GetModelObject  ();
#line 200 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo2  = m_penModel2  -> GetModelObject  ();
#line 201 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(pmo1  != NULL  && pmo2  != NULL )
#line 202 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 204 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = m_penModel  -> GetPlacement  ();
#line 205 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 206 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 207 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 208 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_MORPH_MODELS ;
#line 209 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel  = m_penModel ;
#line 210 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel2  = m_penModel2 ;
#line 211 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 212 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  = penFX ;
#line 213 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 214 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 215 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
else 
#line 216 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 217 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  -> SendEvent  (ETrigger  ());
#line 218 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 219 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 220 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 221 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_DISAPPEAR_MODEL : 
#line 222 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && IsOfClass  (m_penModel  , "ModelHolder2"))
#line 223 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 224 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penEffector  == NULL )
#line 225 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 226 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo  = m_penModel  -> GetModelObject  ();
#line 227 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(pmo  != NULL )
#line 228 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 230 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = m_penModel  -> GetPlacement  ();
#line 231 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 232 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 233 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 234 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_DISAPPEAR_MODEL ;
#line 235 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel  = m_penModel ;
#line 236 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 237 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  = penFX ;
#line 238 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 239 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 240 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
else 
#line 241 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 242 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  -> SendEvent  (ETrigger  ());
#line 243 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 244 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 245 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 246 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_APPEAR_MODEL : 
#line 247 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && IsOfClass  (m_penModel  , "ModelHolder2"))
#line 248 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 249 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penEffector  == NULL )
#line 250 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 251 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo  = m_penModel  -> GetModelObject  ();
#line 252 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(pmo  != NULL )
#line 253 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 255 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = m_penModel  -> GetPlacement  ();
#line 256 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 257 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 258 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 259 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_APPEAR_MODEL ;
#line 260 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel  = m_penModel ;
#line 261 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 262 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  = penFX ;
#line 263 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 264 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 265 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
else 
#line 266 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 267 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  -> SendEvent  (ETrigger  ());
#line 268 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 269 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 270 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 271 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_BASIC_EFFECT : 
#line 272 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 274 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plEffect  = GetPlacement  ();
#line 275 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CEntityPointer penEffect  = CreateEntity  (plEffect  , CLASS_BASIC_EFFECT );
#line 276 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffect  eSpawnEffect ;
#line 277 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnEffect  . colMuliplier  = C_WHITE  | CT_OPAQUE ;
#line 278 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnEffect  . betType  = m_betType ;
#line 279 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnEffect  . vStretch  = FLOAT3D (m_fStretch  , m_fStretch  , m_fStretch );
#line 280 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
penEffect  -> Initialize  (eSpawnEffect );
#line 281 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 282 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 283 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_GLARE : 
#line 284 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 285 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(pwsc  != NULL )
#line 286 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 287 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_colGlade  = m_colColor ;
#line 288 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_tmGlaringStarted  = _pTimer  -> CurrentTick  ();
#line 289 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_tmGlaringEnded  = pwsc  -> m_tmGlaringStarted  + m_tmEffectLife  , 
#line 290 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fGlaringFadeInRatio  = 0.2f;
#line 291 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fGlaringFadeOutRatio  = 0.7f;
#line 292 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 293 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 294 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 295 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 296 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
else if(ee  . ee_slEvent  == EVENTCODE_EActivate )
#line 297 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 298 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
switch(m_emtType )
#line 299 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 300 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_APPEAR_DISAPPEAR : 
#line 301 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && IsOfClass  (m_penModel  , "ModelHolder2"))
#line 302 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 303 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo  = m_penModel  -> GetModelObject  ();
#line 304 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(pmo  != NULL )
#line 305 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 307 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = m_penModel  -> GetPlacement  ();
#line 308 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 309 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 310 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 311 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_APPEAR_MODEL_NOW ;
#line 312 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel  = m_penModel ;
#line 313 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 314 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  = penFX ;
#line 315 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 316 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 317 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 318 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 319 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 320 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
else if(ee  . ee_slEvent  == EVENTCODE_EDeactivate )
#line 321 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 322 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
switch(m_emtType )
#line 323 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 324 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
case EMT_APPEAR_DISAPPEAR : 
#line 325 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && IsOfClass  (m_penModel  , "ModelHolder2"))
#line 326 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 327 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo  = m_penModel  -> GetModelObject  ();
#line 328 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
if(pmo  != NULL )
#line 329 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
{
#line 331 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = m_penModel  -> GetPlacement  ();
#line 332 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 333 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 334 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 335 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_DISAPPEAR_MODEL_NOW ;
#line 336 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel  = m_penModel ;
#line 337 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 338 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  = penFX ;
#line 339 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 340 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 341 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 342 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 343 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
#line 344 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
return FALSE ;
#line 345 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
}
BOOL CEffectMarker::
#line 349 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEffectMarker_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEffectMarker::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 352 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
InitAsEditorModel  ();
#line 353 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 354 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 357 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
SetModel  (MODEL_MARKER );
#line 358 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 360 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  = NULL ;
#line 361 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
Return(STATE_CURRENT,EVoid());
#line 361 "V:/Programs/SamSDK/Sources/EntitiesMP/EffectMarker.es"
return TRUE; ASSERT(FALSE); return TRUE;};