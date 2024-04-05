/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"

#include "StdH.h"
#include "EntitiesMP/WorldSettingsController.h"
#include "EntitiesMP/BackgroundViewer.h"

#include <EntitiesMP/HudPicHolder.h>
#include <EntitiesMP/HudPicHolder_tables.h>
#line 9 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"

BOOL _bDataLoaded = FALSE;
BOOL _bDataError = FALSE;
CTextureObject _toTexture;

void CHudPicHolder::SetDefaultProperties(void) {
  m_strName = "Hud pic holder";
  m_strDescription = "";
  m_fnmPicture = CTString("");
  m_tmFadeInStart = 1e6;
  m_tmFadeOutStart = 1e6;
  m_tmFadeInLen = 0.5f;
  m_tmFadeOutLen = 0.5f;
  m_tmAutoFadeOut = -1.0f;
  m_fYRatio = 0.5f;
  m_fXRatio = 0.5f;
  m_fPictureStretch = 1.0f;
  CRationalEntity::SetDefaultProperties();
}
  
#line 39 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
const CTString & CHudPicHolder::GetDescription(void)const {
#line 40 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
((CTString &) m_strDescription ) . PrintF  ("%s" , m_fnmPicture  . FileName  ());
#line 41 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return m_strDescription ;
#line 42 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
  
#line 44 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
BOOL CHudPicHolder::ReloadData(void) 
#line 45 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 46 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
_bDataError  = FALSE ;
#line 47 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(! Picture_On  (m_fnmPicture ))
#line 48 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 49 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
Picture_Off  ();
#line 50 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return FALSE ;
#line 51 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
#line 52 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return TRUE ;
#line 53 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
  
#line 55 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
BOOL CHudPicHolder::LoadOneFile(const CTFileName & fnm) 
#line 56 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 57 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(fnm  == ""){return FALSE ;}
#line 58 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
try 
#line 59 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
_toTexture  . SetData_t  (fnm );
#line 61 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return TRUE ;
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
catch  (char  * strError )
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 65 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
CPrintF  ("%s\n" , strError );
#line 66 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return FALSE ;
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
#line 68 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
  
#line 71 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
BOOL CHudPicHolder::Picture_On(CTFileName fnPic) 
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 73 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return LoadOneFile  (fnPic );
#line 74 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
  
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
void CHudPicHolder::Picture_Off(void) 
#line 78 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 79 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
_toTexture  . SetData  (NULL );
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
  
#line 83 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
FLOAT CHudPicHolder::HudPic_Render(CHudPicHolder * penThis,CDrawPort * pdp) 
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 85 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(_bDataError ){return 0;}
#line 87 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(! _bDataLoaded ){
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(! ReloadData  ()){
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
_bDataError  = TRUE ;
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return 0;
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
#line 92 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
_bDataLoaded  = TRUE ;
#line 93 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return 1;
#line 94 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
#line 96 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
FLOAT fNow  = _pTimer  -> CurrentTick  ();
#line 97 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(fNow  < m_tmFadeInStart ){return 0;}
#line 98 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(fNow  > m_tmFadeOutStart  + m_tmFadeOutLen ){return 0;}
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
CDrawPort  * pdpCurr  = pdp ;
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
pdp  -> Unlock  ();
#line 102 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
pdpCurr  -> Lock  ();
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
FLOAT fRatio  = 1.0f;
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(fNow  > m_tmFadeOutStart )
#line 106 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
fRatio  = CalculateRatio  (fNow  , m_tmFadeOutStart  , m_tmFadeOutStart  + m_tmFadeOutLen  , 0 , 1);
#line 108 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
#line 109 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(fNow  < m_tmFadeInStart  + m_tmFadeInLen )
#line 110 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
fRatio  = CalculateRatio  (fNow  , m_tmFadeInStart  , m_tmFadeInStart  + m_tmFadeInLen  , 1 , 0);
#line 112 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
#line 113 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
UBYTE  ubA  = ClampUp  (UBYTE  (fRatio  * 255.0f) , UBYTE  (255));
#line 115 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
CTextureData  * ptd  = (CTextureData  *) _toTexture  . GetData  ();
#line 117 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
FLOAT fResScale  = (FLOAT) pdpCurr  -> GetHeight  () / 480.0f;
#line 118 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
const MEX  mexTexW  = ptd  -> GetWidth  ();
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
const MEX  mexTexH  = ptd  -> GetHeight  ();
#line 120 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
FLOAT fPicRatioW  , fPicRatioH ;
#line 121 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(mexTexW  > mexTexH ){
#line 122 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
fPicRatioW  = mexTexW  / mexTexH ;
#line 123 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
fPicRatioH  = 1.0f;
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}else {
#line 125 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
fPicRatioW  = 1.0f;
#line 126 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
fPicRatioH  = mexTexH  / mexTexW ;
#line 127 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
#line 128 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
PIX  picW  = 128 * m_fPictureStretch  * fResScale  * fPicRatioW ;
#line 129 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
PIX  picH  = 128 * m_fPictureStretch  * fResScale  * fPicRatioH ;
#line 131 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
FLOAT fXCenter  = m_fXRatio  * pdpCurr  -> GetWidth  ();
#line 132 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
FLOAT fYCenter  = m_fYRatio  * pdpCurr  -> GetHeight  ();
#line 133 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
PIXaabbox2D  boxScr  = PIXaabbox2D  (
#line 134 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
PIX2D  (fXCenter  - picW  / 2 , fYCenter  - picH  / 2) , 
#line 135 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
PIX2D  (fXCenter  + picW  / 2 , fYCenter  + picH  / 2));
#line 136 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
pdpCurr  -> PutTexture  (& _toTexture  , boxScr  , C_WHITE  | ubA );
#line 138 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
pdpCurr  -> Unlock  ();
#line 139 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
pdp  -> Lock  ();
#line 141 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return 1;
#line 142 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
BOOL CHudPicHolder::
#line 147 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
WaitAndFadeOut(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CHudPicHolder_WaitAndFadeOut
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CHudPicHolder::WaitAndFadeOut expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 149 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
SetTimerAfter(m_tmAutoFadeOut );
Jump(STATE_CURRENT, 0x00f10001, FALSE, EBegin());return TRUE;}BOOL CHudPicHolder::H0x00f10001_WaitAndFadeOut_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f10001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00f10002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CHudPicHolder::H0x00f10002_WaitAndFadeOut_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f10002
;
#line 150 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
Jump(STATE_CURRENT, STATE_CHudPicHolder_ApplyFadeOut, TRUE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};BOOL CHudPicHolder::
#line 153 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
ApplyFadeOut(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CHudPicHolder_ApplyFadeOut
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CHudPicHolder::ApplyFadeOut expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 155 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
m_tmFadeOutStart  = _pTimer  -> CurrentTick  ();
#line 156 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 157 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(!(pwsc  != NULL )){ Jump(STATE_CURRENT,0x00f10006, FALSE, EInternal());return TRUE;}
#line 159 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
SetTimerAfter(m_tmFadeOutLen );
Jump(STATE_CURRENT, 0x00f10004, FALSE, EBegin());return TRUE;}BOOL CHudPicHolder::H0x00f10004_ApplyFadeOut_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f10004
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00f10005, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CHudPicHolder::H0x00f10005_ApplyFadeOut_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f10005
;
#line 160 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 161 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
ETextFX  etfx ;
#line 162 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
etfx  . bStart  = FALSE ;
#line 163 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
etfx  . penSender  = this ;
#line 164 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
pwsc  -> SendEvent  (etfx );Jump(STATE_CURRENT,0x00f10006, FALSE, EInternal());return TRUE;}BOOL CHudPicHolder::H0x00f10006_ApplyFadeOut_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f10006

#line 166 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
Return(STATE_CURRENT,EReturn  ());
#line 166 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CHudPicHolder::
#line 169 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CHudPicHolder_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CHudPicHolder::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 171 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
InitAsEditorModel  ();
#line 172 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 173 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
SetModel  (MODEL_MARKER );
#line 177 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 179 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
SetTimerAfter(0.05f);
Jump(STATE_CURRENT, 0x00f10007, FALSE, EBegin());return TRUE;}BOOL CHudPicHolder::H0x00f10007_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f10007
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00f10008, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CHudPicHolder::H0x00f10008_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f10008
;
#line 181 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(! Picture_On  (m_fnmPicture ))
#line 182 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 183 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
Picture_Off  ();
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
Return(STATE_CURRENT,EVoid());
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return TRUE;
#line 185 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
#line 186 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
_bDataError  = FALSE ;
#line 188 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x00f10009, FALSE, EBegin());return TRUE;}BOOL CHudPicHolder::H0x00f10009_Main_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f10009
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):
#line 190 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{const EBegin&e= (EBegin&)__eeInput;

#line 191 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return TRUE;
#line 192 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStart):
#line 194 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{const EStart&eStart= (EStart&)__eeInput;

#line 195 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 196 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(pwsc  != NULL )
#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 198 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
m_tmFadeInStart  = _pTimer  -> CurrentTick  ();
#line 199 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
EHudPicFX  etfx ;
#line 200 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
etfx  . bStart  = TRUE ;
#line 201 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
etfx  . penSender  = this ;
#line 202 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
pwsc  -> SendEvent  (etfx );
#line 203 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
if(m_tmAutoFadeOut  != - 1)
#line 204 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{
#line 205 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
Call(STATE_CURRENT, STATE_CHudPicHolder_WaitAndFadeOut, TRUE, EVoid());return TRUE;
#line 206 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
#line 207 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}
#line 208 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return TRUE;
#line 209 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStop):
#line 211 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{const EStop&eStop= (EStop&)__eeInput;

#line 212 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
Call(STATE_CURRENT, STATE_CHudPicHolder_ApplyFadeOut, TRUE, EVoid());return TRUE;
#line 213 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return TRUE;
#line 214 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EReturn):
#line 216 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
{const EReturn&e= (EReturn&)__eeInput;

#line 217 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return TRUE;
#line 218 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 219 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
}return TRUE;}BOOL CHudPicHolder::H0x00f1000a_Main_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f1000a

#line 220 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
Picture_Off  ();
#line 221 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
Return(STATE_CURRENT,EVoid());
#line 221 "V:/Programs/SamSDK/Sources/EntitiesMP/HudPicHolder.es"
return TRUE; ASSERT(FALSE); return TRUE;};