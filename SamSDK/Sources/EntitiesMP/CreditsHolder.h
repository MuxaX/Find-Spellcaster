/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_CreditsHolder_INCLUDED
#define _EntitiesMP_CreditsHolder_INCLUDED 1
extern "C" DECL_DLL CDLLEntityClass CCreditsHolder_DLLClass;
class CCreditsHolder : public CRationalEntity {
public:
virtual BOOL IsTargetable(void) const { return TRUE; };
virtual const CTString &GetName(void) const { return m_strName; };
virtual BOOL IsImportant(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
  CTString m_strName;
  CTString m_strDescription;
  CTFileName m_fnmMessage;
  FLOAT m_fMyTimer;
  FLOAT m_fMyTimerLast;
  FLOAT m_iTotalEntries;
  BOOL m_bEnd;
  CEntityPointer m_penEndCreditsTrigger;
  BOOL m_bDataError;
BOOL bDataLoaded;
CFontData _fdMedium;
   
#line 57 "V:/Programs/SamSDK/Sources/EntitiesMP/CreditsHolder.es"
const CTString & GetDescription(void)const;
    CCreditsHolder(void);
   
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/CreditsHolder.es"
BOOL ReloadData(void);
   
#line 84 "V:/Programs/SamSDK/Sources/EntitiesMP/CreditsHolder.es"
BOOL LoadOneFile(const CTFileName & fnm);
   
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/CreditsHolder.es"
BOOL LoadFont();
   
#line 160 "V:/Programs/SamSDK/Sources/EntitiesMP/CreditsHolder.es"
BOOL Credits_On(CTFileName fnCreditsText);
   
#line 167 "V:/Programs/SamSDK/Sources/EntitiesMP/CreditsHolder.es"
void Credits_Off(void);
   
#line 173 "V:/Programs/SamSDK/Sources/EntitiesMP/CreditsHolder.es"
FLOAT Credits_Render(CCreditsHolder * penThis,CDrawPort * pdp);
#define  STATE_CCreditsHolder_WaitScrollingToEnd 0x00f00000
  BOOL 
#line 325 "V:/Programs/SamSDK/Sources/EntitiesMP/CreditsHolder.es"
WaitScrollingToEnd(const CEntityEvent &__eeInput);
  BOOL H0x00f00001_WaitScrollingToEnd_01(const CEntityEvent &__eeInput);
  BOOL H0x00f00002_WaitScrollingToEnd_02(const CEntityEvent &__eeInput);
  BOOL H0x00f00003_WaitScrollingToEnd_03(const CEntityEvent &__eeInput);
  BOOL H0x00f00004_WaitScrollingToEnd_04(const CEntityEvent &__eeInput);
#define  STATE_CCreditsHolder_Main 1
  BOOL 
#line 336 "V:/Programs/SamSDK/Sources/EntitiesMP/CreditsHolder.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x00f00005_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x00f00006_Main_02(const CEntityEvent &__eeInput);
  BOOL H0x00f00007_Main_03(const CEntityEvent &__eeInput);
  BOOL H0x00f00008_Main_04(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_CreditsHolder_INCLUDED
