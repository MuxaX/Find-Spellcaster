/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_TouchField_INCLUDED
#define _EntitiesMP_TouchField_INCLUDED 1
extern "C" DECL_DLL CDLLEntityClass CTouchField_DLLClass;
class CTouchField : public CRationalEntity {
public:
virtual const CTString &GetName(void) const { return m_strName; };
virtual BOOL IsTargetable(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
  CTString m_strName;
  CEntityPointer m_penEnter;
  enum EventEType m_eetEnter;
  CEntityPointer m_penExit;
  enum EventEType m_eetExit;
  BOOL m_bActive;
  BOOL m_bPlayersOnly;
  FLOAT m_tmExitCheck;
  BOOL m_bBlockNonPlayers;
  CEntityPointer m_penLastIn;
CFieldSettings m_fsField;
   
#line 49 "V:/Programs/SamSDK/Sources/EntitiesMP/TouchField.es"
void SetupFieldSettings(void);
   
#line 55 "V:/Programs/SamSDK/Sources/EntitiesMP/TouchField.es"
CFieldSettings * GetFieldSettings(void);
   
#line 64 "V:/Programs/SamSDK/Sources/EntitiesMP/TouchField.es"
SLONG GetUsedMemory(void);
#define  STATE_CTouchField_WaitingEntry 0x00ce0000
  BOOL 
#line 77 "V:/Programs/SamSDK/Sources/EntitiesMP/TouchField.es"
WaitingEntry(const CEntityEvent &__eeInput);
  BOOL H0x00ce0001_WaitingEntry_01(const CEntityEvent &__eeInput);
  BOOL H0x00ce0002_WaitingEntry_02(const CEntityEvent &__eeInput);
#define  STATE_CTouchField_WaitingExit 0x00ce0003
  BOOL 
#line 116 "V:/Programs/SamSDK/Sources/EntitiesMP/TouchField.es"
WaitingExit(const CEntityEvent &__eeInput);
  BOOL H0x00ce0004_WaitingExit_01(const CEntityEvent &__eeInput);
  BOOL H0x00ce0005_WaitingExit_02(const CEntityEvent &__eeInput);
  BOOL H0x00ce0006_WaitingExit_03(const CEntityEvent &__eeInput);
  BOOL H0x00ce0007_WaitingExit_04(const CEntityEvent &__eeInput);
#define  STATE_CTouchField_Frozen 0x00ce0008
  BOOL 
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/TouchField.es"
Frozen(const CEntityEvent &__eeInput);
  BOOL H0x00ce0009_Frozen_01(const CEntityEvent &__eeInput);
  BOOL H0x00ce000a_Frozen_02(const CEntityEvent &__eeInput);
#define  STATE_CTouchField_Main 1
  BOOL 
#line 154 "V:/Programs/SamSDK/Sources/EntitiesMP/TouchField.es"
Main(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_TouchField_INCLUDED
