/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"

#include "StdH.h"
#include "EntitiesMP/WorldSettingsController.h"
#include "EntitiesMP/BackgroundViewer.h"

#include <EntitiesMP/TextFXHolder.h>
#include <EntitiesMP/TextFXHolder_tables.h>
#line 8 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"

static CStaticStackArray<CTString> _astrLines;
static CTFileName _fnLastLoaded;

void CTextFXHolder::SetDefaultProperties(void) {
  m_strName = "Text FX holder";
  m_strDescription = "";
  m_fnmMessage = CTString("");
  m_tmFadeInStart = 1e6;
  m_tmFadeOutStart = 1e6;
  m_tmFadeInLen = 0.5f;
  m_tmFadeOutLen = 0.5f;
  m_tmAutoFadeOut = -1.0f;
  m_bDataError = FALSE ;
  CRationalEntity::SetDefaultProperties();
}
  
#line 39 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
const CTString & CTextFXHolder::GetDescription(void)const {
#line 40 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
((CTString &) m_strDescription ) . PrintF  ("%s" , m_fnmMessage  . FileName  ());
#line 41 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return m_strDescription ;
#line 42 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
   CTextFXHolder::CTextFXHolder(void) 
#line 45 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 46 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
bDataLoaded  = FALSE ;
#line 47 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
  
#line 49 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
BOOL CTextFXHolder::ReloadData(void) 
#line 50 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 51 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
m_bDataError  = FALSE ;
#line 52 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(! Text_On  (m_fnmMessage ))
#line 53 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 54 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
Text_Off  ();
#line 55 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return FALSE ;
#line 56 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 57 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return TRUE ;
#line 58 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
  
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
BOOL CTextFXHolder::LoadOneFile(const CTFileName & fnm) 
#line 61 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(fnm  == ""){return FALSE ;}
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
try 
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 66 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
CTFileStream  strm ;
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
strm  . Open_t  (fnm );
#line 70 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
INDEX ctLines  = 0;
#line 71 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
while(! strm  . AtEOF  ())
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 73 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
CTString strLine ;
#line 74 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
strm  . GetLine_t  (strLine );
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
ctLines  ++;
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
strm  . SetPos_t  (0);
#line 80 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
CTString * astr  = _astrLines  . Push  (ctLines );
#line 82 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
for(INDEX iLine  = 0;iLine  < ctLines  && ! strm  . AtEOF  ();iLine  ++)
#line 83 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
strm  . GetLine_t  (astr  [ iLine  ]);
#line 85 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 86 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
strm  . Close  ();
#line 87 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return TRUE ;
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 89 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
catch  (char  * strError )
#line 90 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
CPrintF  ("%s\n" , strError );
#line 92 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return FALSE ;
#line 93 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 94 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
_fnLastLoaded  = fnm ;
#line 95 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
  
#line 98 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
BOOL CTextFXHolder::Text_On(CTFileName fnText) 
#line 99 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 100 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
_astrLines  . PopAll  ();
#line 101 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return LoadOneFile  (fnText );
#line 102 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
  
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
void CTextFXHolder::Text_Off(void) 
#line 106 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 107 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
_astrLines  . Clear  ();
#line 108 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
  
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
FLOAT CTextFXHolder::TextFX_Render(CTextFXHolder * penThis,CDrawPort * pdp) 
#line 112 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 113 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(m_bDataError ){return 0;}
#line 115 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(! bDataLoaded ){
#line 116 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(! ReloadData  ()){
#line 117 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
m_bDataError  = TRUE ;
#line 118 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return 0;
#line 119 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 120 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
bDataLoaded  = TRUE ;
#line 121 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return 1;
#line 122 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
FLOAT fNow  = _pTimer  -> CurrentTick  ();
#line 125 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(fNow  < m_tmFadeInStart ){return 0;}
#line 126 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(fNow  > m_tmFadeOutStart  + m_tmFadeOutLen ){return 0;}
#line 128 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
PIX  pixW  = 0;
#line 129 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
PIX  pixH  = 0;
#line 130 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
PIX  pixJ  = 0;
#line 131 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
FLOAT fResolutionScaling ;
#line 132 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
PIX  pixLineHeight ;
#line 133 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
CTString strEmpty ;
#line 135 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
CDrawPort  * pdpCurr  = pdp ;
#line 136 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pdp  -> Unlock  ();
#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pdpCurr  -> Lock  ();
#line 139 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pixW  = pdpCurr  -> GetWidth  ();
#line 140 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pixH  = pdpCurr  -> GetHeight  ();
#line 141 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
fResolutionScaling  = (FLOAT) pixH  / 360.0f;
#line 142 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pdpCurr  -> SetFont  (_pfdDisplayFont );
#line 143 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pixLineHeight  = floor  (20 * fResolutionScaling );
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
INDEX ctMaxLinesOnScreen  = pixH  / pixLineHeight ;
#line 146 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
INDEX ctLines  = ClampUp  (_astrLines  . Count  () , ctMaxLinesOnScreen );
#line 148 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pixJ  = PIX  (pixH  / 2 - ctLines  / 2.0f * pixLineHeight );
#line 149 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
for(INDEX iLine  = 0;iLine  < ctLines ;iLine  ++)
#line 150 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 151 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
CTString * pstr  = & _astrLines  [ iLine  ];
#line 152 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pdp  -> SetFont  (_pfdDisplayFont );
#line 153 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pdp  -> SetTextScaling  (fResolutionScaling );
#line 154 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pdp  -> SetTextAspect  (1.0f);
#line 155 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
FLOAT fRatio  = 1.0f;
#line 156 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(fNow  > m_tmFadeOutStart )
#line 157 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 158 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
fRatio  = CalculateRatio  (fNow  , m_tmFadeOutStart  , m_tmFadeOutStart  + m_tmFadeOutLen  , 0 , 1);
#line 159 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 160 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(fNow  < m_tmFadeInStart  + m_tmFadeInLen )
#line 161 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 162 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
fRatio  = CalculateRatio  (fNow  , m_tmFadeInStart  , m_tmFadeInStart  + m_tmFadeInLen  , 1 , 0);
#line 163 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 164 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
UBYTE  ubA  = ClampUp  (UBYTE  (fRatio  * 255.0f) , UBYTE  (255));
#line 165 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pdp  -> PutTextC  (* pstr  , pixW  / 2 , pixJ  , C_WHITE  | ubA );
#line 166 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pixJ  += pixLineHeight ;
#line 167 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 169 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pdpCurr  -> Unlock  ();
#line 170 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pdp  -> Lock  ();
#line 172 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return 1;
#line 173 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
BOOL CTextFXHolder::
#line 178 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
WaitAndFadeOut(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CTextFXHolder_WaitAndFadeOut
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CTextFXHolder::WaitAndFadeOut expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 180 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
SetTimerAfter(m_tmAutoFadeOut );
Jump(STATE_CURRENT, 0x00ef0001, FALSE, EBegin());return TRUE;}BOOL CTextFXHolder::H0x00ef0001_WaitAndFadeOut_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00ef0002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CTextFXHolder::H0x00ef0002_WaitAndFadeOut_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0002
;
#line 181 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
Jump(STATE_CURRENT, STATE_CTextFXHolder_ApplyFadeOut, TRUE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};BOOL CTextFXHolder::
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
ApplyFadeOut(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CTextFXHolder_ApplyFadeOut
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CTextFXHolder::ApplyFadeOut expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 186 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
m_tmFadeOutStart  = _pTimer  -> CurrentTick  ();
#line 187 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 188 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(!(pwsc  != NULL )){ Jump(STATE_CURRENT,0x00ef0006, FALSE, EInternal());return TRUE;}
#line 190 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
SetTimerAfter(m_tmFadeOutLen );
Jump(STATE_CURRENT, 0x00ef0004, FALSE, EBegin());return TRUE;}BOOL CTextFXHolder::H0x00ef0004_ApplyFadeOut_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0004
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00ef0005, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CTextFXHolder::H0x00ef0005_ApplyFadeOut_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0005
;
#line 191 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 192 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
ETextFX  etfx ;
#line 193 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
etfx  . bStart  = FALSE ;
#line 194 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
etfx  . penSender  = this ;
#line 195 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pwsc  -> SendEvent  (etfx );Jump(STATE_CURRENT,0x00ef0006, FALSE, EInternal());return TRUE;}BOOL CTextFXHolder::H0x00ef0006_ApplyFadeOut_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0006

#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
Return(STATE_CURRENT,EReturn  ());
#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CTextFXHolder::
#line 200 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CTextFXHolder_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CTextFXHolder::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 202 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
InitAsEditorModel  ();
#line 203 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 204 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 207 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
SetModel  (MODEL_MARKER );
#line 208 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 210 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
SetTimerAfter(0.05f);
Jump(STATE_CURRENT, 0x00ef0007, FALSE, EBegin());return TRUE;}BOOL CTextFXHolder::H0x00ef0007_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0007
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00ef0008, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CTextFXHolder::H0x00ef0008_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0008
;
#line 212 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(! Text_On  (m_fnmMessage ))
#line 213 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 214 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
Text_Off  ();
#line 215 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
Return(STATE_CURRENT,EVoid());
#line 215 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return TRUE;
#line 216 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 217 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
m_bDataError  = FALSE ;
#line 219 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x00ef0009, FALSE, EBegin());return TRUE;}BOOL CTextFXHolder::H0x00ef0009_Main_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0009
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):
#line 221 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{const EBegin&e= (EBegin&)__eeInput;

#line 222 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return TRUE;
#line 223 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStart):
#line 225 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{const EStart&eStart= (EStart&)__eeInput;

#line 226 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 227 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(pwsc  != NULL )
#line 228 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 229 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
m_tmFadeInStart  = _pTimer  -> CurrentTick  ();
#line 230 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
ETextFX  etfx ;
#line 231 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
etfx  . bStart  = TRUE ;
#line 232 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
etfx  . penSender  = this ;
#line 233 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
pwsc  -> SendEvent  (etfx );
#line 234 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
if(m_tmAutoFadeOut  != - 1)
#line 235 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{
#line 236 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
Call(STATE_CURRENT, STATE_CTextFXHolder_WaitAndFadeOut, TRUE, EVoid());return TRUE;
#line 237 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 238 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}
#line 239 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return TRUE;
#line 240 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStop):
#line 242 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{const EStop&eStop= (EStop&)__eeInput;

#line 243 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
Call(STATE_CURRENT, STATE_CTextFXHolder_ApplyFadeOut, TRUE, EVoid());return TRUE;
#line 244 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return TRUE;
#line 245 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EReturn):
#line 247 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
{const EReturn&e= (EReturn&)__eeInput;

#line 248 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return TRUE;
#line 249 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 250 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
}return TRUE;}BOOL CTextFXHolder::H0x00ef000a_Main_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef000a

#line 251 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
Text_Off  ();
#line 252 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
Return(STATE_CURRENT,EVoid());
#line 252 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
return TRUE; ASSERT(FALSE); return TRUE;};