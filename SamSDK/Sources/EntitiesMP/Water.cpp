/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"

#include "StdH.h"

#include <EntitiesMP/Water.h>
#include <EntitiesMP/Water_tables.h>
CEntityEvent *EWater::MakeCopy(void) { CEntityEvent *peeCopy = new EWater(*this); return peeCopy;}
EWater::EWater() : CEntityEvent(EVENTCODE_EWater) {;
 ClearToDefault(penLauncher);
 ClearToDefault(EwsSize);
};
#line 22 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"

#define FLY_TIME 5.0f

void CWater::SetDefaultProperties(void) {
  m_penLauncher = NULL;
  m_EwsSize = WTS_SMALL ;
  m_fDamageAmount = 0.0f;
  m_fIgnoreTime = 0.0f;
  m_fPushAwayFactor = 0.0f;
  CMovableModelEntity::SetDefaultProperties();
}
  
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
void CWater::Read_t(CTStream * istr) 
#line 61 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
{
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
CRationalEntity  :: Read_t  (istr );
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
SetupLightSource  ();
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}
  
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
CLightSource * CWater::GetLightSource(void) 
#line 68 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
{
#line 69 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
if(! IsPredictor  ()){
#line 70 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
return & m_lsLightSource ;
#line 71 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}else {
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
return NULL ;
#line 73 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}
#line 74 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}
  
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
void CWater::SetupLightSource(void) 
#line 78 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
{
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
CLightSource  lsNew ;
#line 81 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
lsNew  . ls_ulFlags  = LSF_NONPERSISTENT  | LSF_DYNAMIC ;
#line 82 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
lsNew  . ls_colColor  = C_lBLUE ;
#line 83 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
lsNew  . ls_rFallOff  = 1.0f;
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
lsNew  . ls_rHotSpot  = 0.2f;
#line 85 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
lsNew  . ls_plftLensFlare  = NULL ;
#line 86 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
lsNew  . ls_ubPolygonalMask  = 0;
#line 87 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
lsNew  . ls_paoLightAnimation  = NULL ;
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
m_lsLightSource  . ls_penEntity  = this ;
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
m_lsLightSource  . SetLightSource  (lsNew );
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}
  
#line 94 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
void CWater::RenderParticles(void) {
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}
  
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
void CWater::WaterTouch(CEntityPointer penHit) {
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
FLOAT3D vDirection ;
#line 102 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
AnglesToDirectionVector  (GetPlacement  () . pl_OrientationAngle  , vDirection );
#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
InflictDirectDamage  (penHit  , m_penLauncher  , DMT_PROJECTILE  , m_fDamageAmount  , 
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
GetPlacement  () . pl_PositionVector  , vDirection );
#line 106 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
FLOAT3D vSpeed ;
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
GetHeadingDirection  (0.0f , vSpeed );
#line 108 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
vSpeed  = vSpeed  * m_fPushAwayFactor ;
#line 109 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
KickEntity  (penHit  , vSpeed );
#line 110 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}
BOOL CWater::
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
WaterFly(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWater_WaterFly
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWater::WaterFly expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 121 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
SetTimerAfter(FLY_TIME );
Jump(STATE_CURRENT, 0x01fc0002, FALSE, EBegin());return TRUE;}BOOL CWater::H0x01fc0002_WaterFly_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fc0002
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EPass):{const EPass&epass= (EPass&)__eeInput;

#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
BOOL bHit ;
#line 126 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
bHit  = epass  . penOther  != m_penLauncher  || _pTimer  -> CurrentTick  () > m_fIgnoreTime ;
#line 128 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
bHit  &= ! (IsOfClass  (epass  . penOther  , "Water"));
#line 129 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
if(bHit ){
#line 130 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
WaterTouch  (epass  . penOther );
#line 131 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
UnsetTimer();Jump(STATE_CURRENT,0x01fc0003, FALSE, EInternal());return TRUE;
#line 132 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}
#line 133 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
return TRUE;
#line 134 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETouch):{const ETouch&etouch= (ETouch&)__eeInput;

#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
m_fIgnoreTime  = 0.0f;
#line 139 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
BOOL bHit ;
#line 140 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
bHit  = ! (etouch  . penOther  -> GetRenderType  () & RT_BRUSH );
#line 142 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
bHit  &= ! (IsOfClass  (etouch  . penOther  , "Water"));
#line 143 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
if(bHit ){
#line 144 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
WaterTouch  (etouch  . penOther );
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
UnsetTimer();Jump(STATE_CURRENT,0x01fc0003, FALSE, EInternal());return TRUE;
#line 146 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}
#line 148 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
if(en_vCurrentTranslationAbsolute  . Length  () < 0.25f * en_vDesiredTranslationRelative  . Length  ()){
#line 149 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
UnsetTimer();Jump(STATE_CURRENT,0x01fc0003, FALSE, EInternal());return TRUE;
#line 150 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}
#line 151 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
return TRUE;
#line 152 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}ASSERT(FALSE);break;case(EVENTCODE_EDeath):{const EDeath&e= (EDeath&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x01fc0003, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x01fc0003, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 155 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}return TRUE;}BOOL CWater::H0x01fc0003_WaterFly_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fc0003

#line 156 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
Return(STATE_CURRENT,EEnd  ());
#line 156 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CWater::
#line 161 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWater_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EWater, "CWater::Main expects 'EWater' as input!");  const EWater &ew = (const EWater &)__eeInput;
#line 163 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
ASSERT  (ew  . penLauncher  != NULL );
#line 164 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
m_penLauncher  = ew  . penLauncher ;
#line 165 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
m_EwsSize  = ew  . EwsSize ;
#line 168 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
InitAsModel  ();
#line 169 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
SetPhysicsFlags  (EPF_ONBLOCK_SLIDE  | EPF_PUSHABLE  | EPF_MOVABLE );
#line 170 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
SetCollisionFlags  (ECF_PROJECTILE_MAGIC );
#line 171 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
SetComponents  (this  , * GetModelObject  () , MODEL_WATER  , TEXTURE_WATER  , 0 , TEX_SPEC_STRONG  , 0);
#line 174 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
switch(m_EwsSize ){
#line 175 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
case WTS_SMALL : 
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
m_fDamageAmount  = 10.0f;
#line 177 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
m_fPushAwayFactor  = 10.0f;
#line 178 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
LaunchAsPropelledProjectile  (FLOAT3D (0.0f , 0.0f , - 30.0f) , (CMovableEntity  *) (CEntity  *) m_penLauncher );
#line 179 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
break ;
#line 180 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
case WTS_BIG : 
#line 181 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
m_fDamageAmount  = 20.0f;
#line 182 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
m_fPushAwayFactor  = 20.0f;
#line 183 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
GetModelObject  () -> StretchModel  (FLOAT3D (4.0f , 4.0f , 4.0f));
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
LaunchAsPropelledProjectile  (FLOAT3D (0.0f , 0.0f , - 50.0f) , (CMovableEntity  *) (CEntity  *) m_penLauncher );
#line 185 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
break ;
#line 186 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
case WTS_LARGE : 
#line 187 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
m_fDamageAmount  = 40.0f;
#line 188 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
m_fPushAwayFactor  = 40.0f;
#line 189 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
GetModelObject  () -> StretchModel  (FLOAT3D (16.0f , 16.0f , 16.0f));
#line 190 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
LaunchAsPropelledProjectile  (FLOAT3D (0.0f , 0.0f , - 80.0f) , (CMovableEntity  *) (CEntity  *) m_penLauncher );
#line 191 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
break ;
#line 192 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
}
#line 193 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
ModelChangeNotify  ();
#line 196 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
SetupLightSource  ();
#line 199 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
m_fIgnoreTime  = _pTimer  -> CurrentTick  () + 1.0f;
#line 202 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
STATE_CWater_WaterFly, TRUE;
Jump(STATE_CURRENT, 0x01fc0004, FALSE, EBegin());return TRUE;}BOOL CWater::H0x01fc0004_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fc0004
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CWater_WaterFly, TRUE, EVoid());return TRUE;case EVENTCODE_EEnd: Jump(STATE_CURRENT,0x01fc0005, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CWater::H0x01fc0005_Main_02(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x01fc0005
const EEnd&__e= (EEnd&)__eeInput;
;
#line 205 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
Destroy  ();
#line 207 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
Return(STATE_CURRENT,EVoid());
#line 207 "V:/Programs/SamSDK/Sources/EntitiesMP/Water.es"
return TRUE; ASSERT(FALSE); return TRUE;};