/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_AnimationHub_INCLUDED
#define _EntitiesMP_AnimationHub_INCLUDED 1
extern "C" DECL_DLL CDLLEntityClass CAnimationHub_DLLClass;
class CAnimationHub : public CRationalEntity {
public:
virtual const CTString &GetName(void) const { return m_strName; };
virtual BOOL IsTargetable(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
  CTString m_strName;
  CTString m_strDescription;
  FLOAT m_tmDelayEach;
  CEntityPointer m_penTarget0;
  CEntityPointer m_penTarget1;
  CEntityPointer m_penTarget2;
  CEntityPointer m_penTarget3;
  CEntityPointer m_penTarget4;
  CEntityPointer m_penTarget5;
  CEntityPointer m_penTarget6;
  CEntityPointer m_penTarget7;
  CEntityPointer m_penTarget8;
  CEntityPointer m_penTarget9;
  FLOAT m_tmDelay0;
  FLOAT m_tmDelay1;
  FLOAT m_tmDelay2;
  FLOAT m_tmDelay3;
  FLOAT m_tmDelay4;
  FLOAT m_tmDelay5;
  FLOAT m_tmDelay6;
  FLOAT m_tmDelay7;
  FLOAT m_tmDelay8;
  FLOAT m_tmDelay9;
  INDEX m_iModelAnim;
  BOOL m_bModelLoop;
  INDEX m_iTextureAnim;
  BOOL m_bTextureLoop;
  INDEX m_iLightAnim;
  BOOL m_bLightLoop;
  COLOR m_colAmbient;
  COLOR m_colDiffuse;
  INDEX m_iCounter;
   
#line 57 "V:/Programs/SamSDK/Sources/EntitiesMP/AnimationHub.es"
const CTString & GetDescription(void)const;
#define  STATE_CAnimationHub_RelayEvents 0x00e40000
  BOOL 
#line 66 "V:/Programs/SamSDK/Sources/EntitiesMP/AnimationHub.es"
RelayEvents(const CEntityEvent &__eeInput);
  BOOL H0x00e40001_RelayEvents_01(const CEntityEvent &__eeInput);
  BOOL H0x00e40002_RelayEvents_02(const CEntityEvent &__eeInput);
  BOOL H0x00e40003_RelayEvents_03(const CEntityEvent &__eeInput);
  BOOL H0x00e40004_RelayEvents_04(const CEntityEvent &__eeInput);
  BOOL H0x00e40005_RelayEvents_05(const CEntityEvent &__eeInput);
#define  STATE_CAnimationHub_WaitChange 0x00e40006
  BOOL 
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/AnimationHub.es"
WaitChange(const CEntityEvent &__eeInput);
  BOOL H0x00e40007_WaitChange_01(const CEntityEvent &__eeInput);
  BOOL H0x00e40008_WaitChange_02(const CEntityEvent &__eeInput);
  BOOL H0x00e40009_WaitChange_03(const CEntityEvent &__eeInput);
  BOOL H0x00e4000a_WaitChange_04(const CEntityEvent &__eeInput);
#define  STATE_CAnimationHub_Main 1
  BOOL 
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/AnimationHub.es"
Main(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_AnimationHub_INCLUDED
