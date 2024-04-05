/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_TextFXHolder_INCLUDED
#define _EntitiesMP_TextFXHolder_INCLUDED 1
extern "C" DECL_DLL CDLLEntityClass CTextFXHolder_DLLClass;
class CTextFXHolder : public CRationalEntity {
public:
virtual BOOL IsTargetable(void) const { return TRUE; };
virtual const CTString &GetName(void) const { return m_strName; };
virtual BOOL IsImportant(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
  CTString m_strName;
  CTString m_strDescription;
  CTFileName m_fnmMessage;
  FLOAT m_tmFadeInStart;
  FLOAT m_tmFadeOutStart;
  FLOAT m_tmFadeInLen;
  FLOAT m_tmFadeOutLen;
  FLOAT m_tmAutoFadeOut;
  BOOL m_bDataError;
BOOL bDataLoaded;
   
#line 39 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
const CTString & GetDescription(void)const;
    CTextFXHolder(void);
   
#line 49 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
BOOL ReloadData(void);
   
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
BOOL LoadOneFile(const CTFileName & fnm);
   
#line 98 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
BOOL Text_On(CTFileName fnText);
   
#line 105 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
void Text_Off(void);
   
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
FLOAT TextFX_Render(CTextFXHolder * penThis,CDrawPort * pdp);
#define  STATE_CTextFXHolder_WaitAndFadeOut 0x00ef0000
  BOOL 
#line 178 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
WaitAndFadeOut(const CEntityEvent &__eeInput);
  BOOL H0x00ef0001_WaitAndFadeOut_01(const CEntityEvent &__eeInput);
  BOOL H0x00ef0002_WaitAndFadeOut_02(const CEntityEvent &__eeInput);
#define  STATE_CTextFXHolder_ApplyFadeOut 0x00ef0003
  BOOL 
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
ApplyFadeOut(const CEntityEvent &__eeInput);
  BOOL H0x00ef0004_ApplyFadeOut_01(const CEntityEvent &__eeInput);
  BOOL H0x00ef0005_ApplyFadeOut_02(const CEntityEvent &__eeInput);
  BOOL H0x00ef0006_ApplyFadeOut_03(const CEntityEvent &__eeInput);
#define  STATE_CTextFXHolder_Main 1
  BOOL 
#line 200 "V:/Programs/SamSDK/Sources/EntitiesMP/TextFXHolder.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x00ef0007_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x00ef0008_Main_02(const CEntityEvent &__eeInput);
  BOOL H0x00ef0009_Main_03(const CEntityEvent &__eeInput);
  BOOL H0x00ef000a_Main_04(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_TextFXHolder_INCLUDED