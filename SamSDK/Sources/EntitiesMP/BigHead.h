/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_BigHead_INCLUDED
#define _EntitiesMP_BigHead_INCLUDED 1
#include <EntitiesMP/EnemyBase.h>
#include <EntitiesMP/BasicEffects.h>
extern DECL_DLL CEntityPropertyEnumType BigHeadType_enum;
enum BigHeadType {
  BHT_NORMAL = 0,
  BHT_ZOMBIE = 1,
  BHT_SAINT = 2,
};
DECL_DLL inline void ClearToDefault(BigHeadType &e) { e = (BigHeadType)0; } ;
extern "C" DECL_DLL CDLLEntityClass CBigHead_DLLClass;
class CBigHead : public CEnemyBase {
public:
  DECL_DLL virtual void SetDefaultProperties(void);
  CTFileName m_fnmHeadTex;
  CTFileName m_fnmNameSnd;
  FLOAT m_tmLastGreetTime;
  enum BigHeadType m_bhtType;
  BOOL m_bIgnorePlayer;
  BOOL m_bPlayingWalkSound;
  BOOL m_bSleeping;
  FLOAT m_tmLastWalkingSoundTime;
  FLOAT m_tmWalkingSound;
CAutoPrecacheSound m_aps;
CAutoPrecacheTexture m_apt;
   
#line 72 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
BOOL HandleEvent(const CEntityEvent & ee);
   
#line 86 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
void * GetEntityInfo(void);
   
#line 91 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
void Precache(void);
   
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
INDEX GetWalkAnim(void);
   
#line 116 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
INDEX AnimForDamage(FLOAT fDamage);
   
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
INDEX AnimForDeath(void);
   
#line 131 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
void DeathNotify(void);
   
#line 137 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
void StandingAnim(void);
   
#line 140 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
void WalkingAnim(void);
   
#line 149 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
void RunningAnim(void);
   
#line 154 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
void RotatingAnim(void);
   
#line 158 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
void PlayWalkSound(void);
   
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
void IdleSound(void);
   
#line 184 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
void SightSound(void);
   
#line 188 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
void WoundSound(void);
   
#line 192 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
void DeathSound(void);
#define  STATE_CBigHead_Fire 0x01540000
  BOOL 
#line 198 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
Fire(const CEntityEvent &__eeInput);
  BOOL H0x01540001_Fire_01(const CEntityEvent &__eeInput);
  BOOL H0x01540002_Fire_02(const CEntityEvent &__eeInput);
  BOOL H0x01540003_Fire_03(const CEntityEvent &__eeInput);
#define  STATE_CBigHead_Sleep 0x01540004
  BOOL 
#line 218 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
Sleep(const CEntityEvent &__eeInput);
  BOOL H0x01540005_Sleep_01(const CEntityEvent &__eeInput);
  BOOL H0x01540006_Sleep_02(const CEntityEvent &__eeInput);
#define  STATE_CBigHead_WakeUp 0x01540007
  BOOL 
#line 243 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
WakeUp(const CEntityEvent &__eeInput);
  BOOL H0x01540008_WakeUp_01(const CEntityEvent &__eeInput);
  BOOL H0x01540009_WakeUp_02(const CEntityEvent &__eeInput);
#define  STATE_CBigHead_PreMainLoop 0x0154000a
  BOOL 
#line 257 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
PreMainLoop(const CEntityEvent &__eeInput);
  BOOL H0x0154000b_PreMainLoop_01(const CEntityEvent &__eeInput);
  BOOL H0x0154000c_PreMainLoop_02(const CEntityEvent &__eeInput);
  BOOL H0x0154000d_PreMainLoop_03(const CEntityEvent &__eeInput);
#define  STATE_CBigHead_Main 1
  BOOL 
#line 283 "V:/Programs/SamSDK/Sources/EntitiesMP/BigHead.es"
Main(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_BigHead_INCLUDED
