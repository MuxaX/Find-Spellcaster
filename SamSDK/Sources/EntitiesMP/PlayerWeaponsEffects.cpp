/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"

#include "StdH.h"
#define EPF_MODEL_SHELL (EPF_ONBLOCK_BOUNCE|EPF_TRANSLATEDBYGRAVITY|EPF_MOVABLE)
#define ECF_MODEL_SHELL ( \
  ((ECBI_BRUSH|ECBI_MODEL_HOLDER)<<ECB_TEST) |\
  ((ECBI_CORPSE)<<ECB_IS))

#include <EntitiesMP/PlayerWeaponsEffects.h>
#include <EntitiesMP/PlayerWeaponsEffects_tables.h>
CEntityEvent *EWeaponEffectInit::MakeCopy(void) { CEntityEvent *peeCopy = new EWeaponEffectInit(*this); return peeCopy;}
EWeaponEffectInit::EWeaponEffectInit() : CEntityEvent(EVENTCODE_EWeaponEffectInit) {;
 ClearToDefault(penOwner);
 ClearToDefault(EwetEffect);
};
#line 23 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"

void CPlayerWeaponsEffects_Precache(void)
{
  CDLLEntityClass *pdec = &CPlayerWeaponsEffects_DLLClass;
  pdec->PrecacheModel(MODEL_SG_SHELL);
  pdec->PrecacheTexture(TEXTURE_SG_SHELL);
  pdec->PrecacheModel(MODEL_MG_SHELL);
  pdec->PrecacheTexture(TEXTURE_MG_SHELL);
}

void CPlayerWeaponsEffects::SetDefaultProperties(void) {
  m_penOwner = NULL;
  m_EwetEffect = WET_SHOTGUNSHELL ;
  m_penPrediction = NULL;
  CMovableEntity::SetDefaultProperties();
}
BOOL CPlayerWeaponsEffects::
#line 53 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
ShotgunShell(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CPlayerWeaponsEffects_ShotgunShell
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CPlayerWeaponsEffects::ShotgunShell expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 55 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
InitAsModel  ();
#line 56 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
SetPhysicsFlags  (EPF_MODEL_SHELL );
#line 57 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
SetCollisionFlags  (ECF_MODEL_SHELL );
#line 59 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
GetModelObject  () -> StretchModel  (FLOAT3D (0.5f , 0.5f , 0.5f));
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
SetModel  (MODEL_SG_SHELL );
#line 61 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
ModelChangeNotify  ();
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
SetModelMainTexture  (TEXTURE_SG_SHELL );
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
LaunchAsFreeProjectile  (FLOAT3D (FRnd  () + 2.0f , FRnd  () + 5.0f , - FRnd  () - 2.0f) , (CMovableEntity  *) & * m_penOwner );
#line 66 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
SetTimerAfter(1.5f);
Jump(STATE_CURRENT, 0x01950002, FALSE, EBegin());return TRUE;}BOOL CPlayerWeaponsEffects::H0x01950002_ShotgunShell_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01950002
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01950003, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CPlayerWeaponsEffects::H0x01950003_ShotgunShell_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01950003
;
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
Return(STATE_CURRENT,EEnd  ());
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CPlayerWeaponsEffects::
#line 69 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
MachinegunShell(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CPlayerWeaponsEffects_MachinegunShell
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CPlayerWeaponsEffects::MachinegunShell expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 71 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
InitAsModel  ();
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
SetPhysicsFlags  (EPF_MODEL_SHELL );
#line 73 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
SetCollisionFlags  (ECF_MODEL_SHELL );
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
GetModelObject  () -> StretchModel  (FLOAT3D (0.5f , 0.5f , 0.5f));
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
SetModel  (MODEL_MG_SHELL );
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
ModelChangeNotify  ();
#line 78 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
SetModelMainTexture  (TEXTURE_MG_SHELL );
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
LaunchAsFreeProjectile  (FLOAT3D (FRnd  () + 2.0f , FRnd  () + 5.0f , - FRnd  () - 2.0f) , (CMovableEntity  *) & * m_penOwner );
#line 82 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
SetTimerAfter(0.5f);
Jump(STATE_CURRENT, 0x01950005, FALSE, EBegin());return TRUE;}BOOL CPlayerWeaponsEffects::H0x01950005_MachinegunShell_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01950005
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01950006, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CPlayerWeaponsEffects::H0x01950006_MachinegunShell_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01950006
;
#line 83 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
Return(STATE_CURRENT,EEnd  ());
#line 83 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CPlayerWeaponsEffects::
#line 86 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CPlayerWeaponsEffects_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EWeaponEffectInit, "CPlayerWeaponsEffects::Main expects 'EWeaponEffectInit' as input!");  const EWeaponEffectInit &eInit = (const EWeaponEffectInit &)__eeInput;
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
ASSERT  (eInit  . penOwner  != NULL );
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
m_penOwner  = eInit  . penOwner ;
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
m_EwetEffect  = eInit  . EwetEffect ;
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
SetFlags  (GetFlags  () | ENF_SEETHROUGH );
#line 92 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
SetPredictable  (TRUE );
#line 94 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
if(!(m_EwetEffect  == WET_SHOTGUNSHELL )){ Jump(STATE_CURRENT,0x0195000e, FALSE, EInternal());return TRUE;}
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
STATE_CPlayerWeaponsEffects_ShotgunShell, TRUE;
Jump(STATE_CURRENT, 0x01950007, FALSE, EBegin());return TRUE;}BOOL CPlayerWeaponsEffects::H0x01950007_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01950007
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CPlayerWeaponsEffects_ShotgunShell, TRUE, EVoid());return TRUE;case EVENTCODE_EEnd: Jump(STATE_CURRENT,0x01950008, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CPlayerWeaponsEffects::H0x01950008_Main_02(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x01950008
const EEnd&__e= (EEnd&)__eeInput;
;Jump(STATE_CURRENT,0x0195000d, FALSE, EInternal());return TRUE;}BOOL CPlayerWeaponsEffects::H0x0195000e_Main_08(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0195000e
if(!(m_EwetEffect  == WET_MACHINEGUNSHELL )){ Jump(STATE_CURRENT,0x0195000c, FALSE, EInternal());return TRUE;}
#line 97 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
STATE_CPlayerWeaponsEffects_MachinegunShell, TRUE;
Jump(STATE_CURRENT, 0x01950009, FALSE, EBegin());return TRUE;}BOOL CPlayerWeaponsEffects::H0x01950009_Main_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01950009
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CPlayerWeaponsEffects_MachinegunShell, TRUE, EVoid());return TRUE;case EVENTCODE_EEnd: Jump(STATE_CURRENT,0x0195000a, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CPlayerWeaponsEffects::H0x0195000a_Main_04(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x0195000a
const EEnd&__e= (EEnd&)__eeInput;
;Jump(STATE_CURRENT,0x0195000b, FALSE, EInternal());return TRUE;}BOOL CPlayerWeaponsEffects::H0x0195000c_Main_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0195000c
{
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
ASSERTALWAYS  ("Uknown weapon effect type");
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
}Jump(STATE_CURRENT,0x0195000b, FALSE, EInternal());return TRUE;}
BOOL CPlayerWeaponsEffects::H0x0195000b_Main_05(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0195000b
Jump(STATE_CURRENT,0x0195000d, FALSE, EInternal());return TRUE;}
BOOL CPlayerWeaponsEffects::H0x0195000d_Main_07(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0195000d

#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
Destroy  ();
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
Return(STATE_CURRENT,EVoid());
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/PlayerWeaponsEffects.es"
return TRUE; ASSERT(FALSE); return TRUE;};