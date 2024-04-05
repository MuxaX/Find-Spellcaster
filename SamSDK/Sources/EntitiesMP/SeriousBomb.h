/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_SeriousBomb_INCLUDED
#define _EntitiesMP_SeriousBomb_INCLUDED 1
#define EVENTCODE_ESeriousBomb 0x01620000
class DECL_DLL ESeriousBomb : public CEntityEvent {
public:
ESeriousBomb();
CEntityEvent *MakeCopy(void);
CEntityPointer penOwner;
};
DECL_DLL inline void ClearToDefault(ESeriousBomb &e) { e = ESeriousBomb(); } ;
extern "C" DECL_DLL CDLLEntityClass CSeriousBomb_DLLClass;
class CSeriousBomb : public CRationalEntity {
public:
  DECL_DLL virtual void SetDefaultProperties(void);
  CEntityPointer m_penOwner;
  CSoundObject m_soBlow;
   
#line 42 "V:/Programs/SamSDK/Sources/EntitiesMP/SeriousBomb.es"
void ShakeItBaby(FLOAT tmShaketime,FLOAT fPower,FLOAT fFade,BOOL bFadeIn);
   
#line 62 "V:/Programs/SamSDK/Sources/EntitiesMP/SeriousBomb.es"
void Glare(FLOAT fStart,FLOAT fEnd,FLOAT fFinR,FLOAT fFoutR);
   
#line 76 "V:/Programs/SamSDK/Sources/EntitiesMP/SeriousBomb.es"
void ExplodeBomb(void);
#define  STATE_CSeriousBomb_Main 1
  BOOL 
#line 93 "V:/Programs/SamSDK/Sources/EntitiesMP/SeriousBomb.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x01620001_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x01620002_Main_02(const CEntityEvent &__eeInput);
  BOOL H0x01620003_Main_03(const CEntityEvent &__eeInput);
  BOOL H0x01620004_Main_04(const CEntityEvent &__eeInput);
  BOOL H0x01620005_Main_05(const CEntityEvent &__eeInput);
  BOOL H0x01620006_Main_06(const CEntityEvent &__eeInput);
  BOOL H0x01620007_Main_07(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_SeriousBomb_INCLUDED
