/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 5 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"

#include "StdH.h"

#include <EntitiesMP/SoundHolder.h>
#include <EntitiesMP/SoundHolder_tables.h>
void CSoundHolder::SetDefaultProperties(void) {
  m_fnSound = CTFILENAME("Sounds\\Default.wav");
  m_rFallOffRange = 100.0f;
  m_rHotSpotRange = 50.0f;
  m_fVolume = 1.0f;
  m_bLoop = TRUE ;
  m_bSurround = FALSE ;
  m_bVolumetric = TRUE ;
  m_strName = "";
  m_strDescription = "";
  m_bAutoStart = FALSE ;
  m_iPlayType = 0;
  m_soSound.SetOwner(this);
m_soSound.Stop_internal();
  m_bDestroyable = FALSE ;
  CRationalEntity::SetDefaultProperties();
}
  
#line 46 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
void CSoundHolder::Precache(void) 
#line 47 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
{
#line 48 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
m_aps  . Precache  (m_fnSound );
#line 49 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
}
  
#line 52 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
void CSoundHolder::MirrorAndStretch(FLOAT fStretch,BOOL bMirrorX) 
#line 53 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
{
#line 55 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
m_rFallOffRange  *= fStretch ;
#line 56 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
m_rHotSpotRange  *= fStretch ;
#line 58 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
}
  
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
SLONG CSoundHolder::GetUsedMemory(void) 
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
{
#line 65 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
SLONG  slUsedMemory  = sizeof  (CSoundHolder ) - sizeof  (CRationalEntity ) + CRationalEntity  :: GetUsedMemory  ();
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
slUsedMemory  += m_strName  . Length  ();
#line 68 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
slUsedMemory  += m_strDescription  . Length  ();
#line 69 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
slUsedMemory  += m_fnSound  . Length  ();
#line 70 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
slUsedMemory  += 1 * sizeof  (CSoundObject);
#line 71 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
return slUsedMemory ;
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
}
BOOL CSoundHolder::
#line 78 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CSoundHolder_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CSoundHolder::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 81 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
if(m_rHotSpotRange  < 0.0f){m_rHotSpotRange  = 0.0f;}
#line 82 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
if(m_rFallOffRange  < m_rHotSpotRange ){m_rFallOffRange  = m_rHotSpotRange ;}
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
if(m_fVolume  < FLOAT (SL_VOLUME_MIN )){m_fVolume  = FLOAT (SL_VOLUME_MIN );}
#line 85 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
if(m_fVolume  > FLOAT (SL_VOLUME_MAX )){m_fVolume  = FLOAT (SL_VOLUME_MAX );}
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
m_iPlayType  = SOF_3D ;
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
if(m_bLoop ){m_iPlayType  |= SOF_LOOP ;}
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
if(m_bSurround ){m_iPlayType  |= SOF_SURROUND ;}
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
if(m_bVolumetric ){m_iPlayType  |= SOF_VOLUMETRIC ;}
#line 94 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
InitAsEditorModel  ();
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
const float  SOUND_MINSIZE  = 1.0f;
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
FLOAT fFactor  = Log2  (m_rFallOffRange ) * SOUND_MINSIZE ;
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
if(fFactor  < SOUND_MINSIZE ){
#line 102 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
fFactor  = SOUND_MINSIZE ;
#line 103 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
}
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
GetModelObject  () -> mo_Stretch  = FLOAT3D (fFactor  , fFactor  , fFactor );
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
SetModel  (MODEL_MARKER );
#line 108 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 110 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
m_strDescription  . PrintF  ("%s" , (CTString &) m_fnSound  . FileName  ());
#line 113 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
if(!(_pTimer  -> CurrentTick  () <= 0.1f)){ Jump(STATE_CURRENT,0x00cc0002, FALSE, EInternal());return TRUE;}
#line 115 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
SetTimerAfter(0.5f);
Jump(STATE_CURRENT, 0x00cc0000, FALSE, EBegin());return TRUE;}BOOL CSoundHolder::H0x00cc0000_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00cc0000
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00cc0001, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CSoundHolder::H0x00cc0001_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00cc0001
;Jump(STATE_CURRENT,0x00cc0002, FALSE, EInternal());return TRUE;}BOOL CSoundHolder::H0x00cc0002_Main_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00cc0002

#line 118 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x00cc0003, FALSE, EBegin());return TRUE;}BOOL CSoundHolder::H0x00cc0003_Main_04(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00cc0003
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 121 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
if(m_bAutoStart ){
#line 122 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
m_soSound  . Set3DParameters  (FLOAT (m_rFallOffRange ) , FLOAT (m_rHotSpotRange ) , m_fVolume  , 1.0f);
#line 123 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
PlaySound  (m_soSound  , m_fnSound  , m_iPlayType );
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
}
#line 125 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
return TRUE;
#line 126 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStart):{const EStart&e= (EStart&)__eeInput;

#line 129 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
m_soSound  . Set3DParameters  (FLOAT (m_rFallOffRange ) , FLOAT (m_rHotSpotRange ) , m_fVolume  , 1.0f);
#line 130 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
PlaySound  (m_soSound  , m_fnSound  , m_iPlayType );
#line 131 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
return TRUE;
#line 132 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStop):{const EStop&e= (EStop&)__eeInput;

#line 135 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
m_soSound  . Stop  ();
#line 136 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
return TRUE;
#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_ERangeModelDestruction):{const ERangeModelDestruction&e= (ERangeModelDestruction&)__eeInput;

#line 141 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
if(m_bDestroyable ){
#line 143 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
m_soSound  . Stop  ();
#line 144 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
}
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
Return(STATE_CURRENT,TRUE );
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
return TRUE;
#line 146 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EEnd):{const EEnd&e= (EEnd&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x00cc0004, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 148 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
}return TRUE;}BOOL CSoundHolder::H0x00cc0004_Main_05(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00cc0004

#line 151 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
Destroy  ();
#line 152 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
Return(STATE_CURRENT,EVoid());
#line 152 "V:/Programs/SamSDK/Sources/EntitiesMP/SoundHolder.es"
return TRUE; ASSERT(FALSE); return TRUE;};