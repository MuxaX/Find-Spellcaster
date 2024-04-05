/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"

#include "StdH.h"

#include <EntitiesMP/MeteorShower.h>
#include <EntitiesMP/MeteorShower_tables.h>
void CMeteorShower::SetDefaultProperties(void) {
  m_strName = "Meteor Shower";
  m_aAngle = ANGLE3D(AngleDeg  (0.0f) , AngleDeg  (0.0f) , AngleDeg  (0.0f));
  m_iPerTickLaunchChance = 10;
  m_fMinStretch = 1.0f;
  m_fMaxStretch = 1.1f;
  m_rSafeArea = 10.0f;
  m_rArea = 50.0f;
  m_fSpeed = 300.0f;
  m_fLaunchDistance = 500.0f;
  CRationalEntity::SetDefaultProperties();
}
  
#line 39 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
void CMeteorShower::Precache(void) {
#line 40 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
PrecacheClass  (CLASS_PROJECTILE  , PRT_METEOR );
#line 41 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
}
  
#line 44 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
void CMeteorShower::SpawnProjectile(const CPlacement3D & pl) 
#line 45 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
{
#line 46 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
CEntityPointer pen  = CreateEntity  (pl  , CLASS_PROJECTILE );
#line 49 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
ELaunchProjectile  eLaunch ;
#line 50 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
eLaunch  . penLauncher  = this ;
#line 51 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
eLaunch  . prtType  = PRT_METEOR ;
#line 52 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
eLaunch  . fStretch  = Lerp  (m_fMinStretch  , m_fMaxStretch  , FRnd  ());
#line 53 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
eLaunch  . fSpeed  = m_fSpeed ;
#line 54 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
pen  -> Initialize  (eLaunch );
#line 55 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
}
  
#line 57 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
void CMeteorShower::MaybeShootMeteor(void) 
#line 58 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
{
#line 59 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
INDEX iShoot  = IRnd  () % 100;
#line 61 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
if(iShoot  <= m_iPerTickLaunchChance )
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
{
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
CPlacement3D plFall ;
#line 65 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
plFall  . pl_PositionVector  = GetPlacement  () . pl_PositionVector ;
#line 66 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
FLOAT fR  = Lerp  (m_rSafeArea  , m_rArea  , FRnd  ());
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
FLOAT fA  = FRnd  () * 360.0f;
#line 68 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
plFall  . pl_PositionVector  += FLOAT3D (CosFast  (fA ) * fR  , 0.05f , SinFast  (fA ) * fR );
#line 69 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
FLOAT3D vDir ;
#line 70 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
AnglesToDirectionVector  (m_aAngle  , vDir );
#line 71 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
vDir  . Normalize  ();
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
CPlacement3D plLaunch  = plFall ;
#line 73 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
plLaunch  . pl_PositionVector  = plFall  . pl_PositionVector  - vDir  * m_fLaunchDistance ;
#line 74 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
plLaunch  . pl_OrientationAngle  = m_aAngle ;
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
SpawnProjectile  (plLaunch );
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
}
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
}
BOOL CMeteorShower::
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
Active(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CMeteorShower_Active
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CMeteorShower::Active expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 86 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
Jump(STATE_CURRENT,0x02670003, FALSE, EInternal());return TRUE;}BOOL CMeteorShower::H0x02670003_Active_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02670003
if(!(TRUE )){ Jump(STATE_CURRENT,0x02670004, FALSE, EInternal());return TRUE;}
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
SetTimerAfter(_pTimer  -> TickQuantum );
Jump(STATE_CURRENT, 0x02670001, FALSE, EBegin());return TRUE;}BOOL CMeteorShower::H0x02670001_Active_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x02670001
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
return TRUE;
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
}ASSERT(FALSE);break;case(EVENTCODE_EEnvironmentStop):{const EEnvironmentStop&e= (EEnvironmentStop&)__eeInput;

#line 93 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
Jump(STATE_CURRENT, STATE_CMeteorShower_Inactive, TRUE, EVoid());return TRUE;
#line 94 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;

#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
MaybeShootMeteor  ();
#line 97 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
UnsetTimer();Jump(STATE_CURRENT,0x02670002, FALSE, EInternal());return TRUE;
#line 98 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
}return TRUE;}BOOL CMeteorShower::H0x02670002_Active_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02670002
Jump(STATE_CURRENT,0x02670003, FALSE, EInternal());return TRUE;
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
}BOOL CMeteorShower::H0x02670004_Active_04(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02670004
 ASSERT(FALSE); return TRUE;};BOOL CMeteorShower::
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
Inactive(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CMeteorShower_Inactive
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CMeteorShower::Inactive expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x02670006, FALSE, EBegin());return TRUE;}BOOL CMeteorShower::H0x02670006_Inactive_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x02670006
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EEnvironmentStart):{const EEnvironmentStart&e= (EEnvironmentStart&)__eeInput;
Jump(STATE_CURRENT, STATE_CMeteorShower_Active, TRUE, EVoid());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 110 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
}return TRUE;}BOOL CMeteorShower::H0x02670007_Inactive_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02670007
 ASSERT(FALSE); return TRUE;};BOOL CMeteorShower::
#line 114 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CMeteorShower_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CMeteorShower::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 116 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
if(m_fMinStretch  > m_fMaxStretch ){m_fMinStretch  = m_fMaxStretch ;}
#line 117 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
if(m_rSafeArea  > m_rArea ){m_rSafeArea  = m_rArea ;}
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
InitAsEditorModel  ();
#line 120 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 121 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
SetModel  (MODEL_MARKER );
#line 125 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 127 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
SetTimerAfter(0.05f);
Jump(STATE_CURRENT, 0x02670008, FALSE, EBegin());return TRUE;}BOOL CMeteorShower::H0x02670008_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x02670008
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x02670009, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CMeteorShower::H0x02670009_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02670009
;
#line 129 "V:/Programs/SamSDK/Sources/EntitiesMP/MeteorShower.es"
Jump(STATE_CURRENT, STATE_CMeteorShower_Inactive, TRUE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};