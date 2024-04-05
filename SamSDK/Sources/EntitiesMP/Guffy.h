/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_Guffy_INCLUDED
#define _EntitiesMP_Guffy_INCLUDED 1
#include <EntitiesMP/EnemyBase.h>
#include <EntitiesMP/Projectile.h>
extern "C" DECL_DLL CDLLEntityClass CGuffy_DLLClass;
class CGuffy : public CEnemyBase {
public:
  DECL_DLL virtual void SetDefaultProperties(void);
  INDEX m_iLoopCounter;
  FLOAT m_fSize;
  BOOL m_bWalkSoundPlaying;
  FLOAT m_fThreatDistance;
  BOOL m_bEnemyToTheLeft;
  CSoundObject m_soFire1;
  CSoundObject m_soFire2;
  
#line 63 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
virtual CTString GetPlayerKillDescription(const CTString & strPlayerName,const EDeath & eDeath);
  
#line 70 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
virtual const CTFileName & GetComputerMessageName(void)const;
   
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void Precache(void);
   
#line 111 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void * GetEntityInfo(void);
   
#line 124 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 125 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection);
   
#line 135 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void StandingAnim(void);
   
#line 142 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void RunningAnim(void);
   
#line 145 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void WalkingAnim(void);
   
#line 148 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void RotatingAnim(void);
   
#line 153 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void IdleSound(void);
   
#line 156 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void SightSound(void);
   
#line 159 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void WoundSound(void);
   
#line 162 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void DeathSound(void);
   
#line 167 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void FireRocket(FLOAT3D & vPos);
   
#line 180 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
void EnemyPostInit(void);
   
#line 189 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
INDEX AnimForDamage(FLOAT fDamage);
   
#line 197 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
INDEX AnimForDeath(void);
   
#line 213 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
FLOAT WaitForDust(FLOAT3D & vStretch);
#define  STATE_CGuffy_Fire 0x01580000
  BOOL 
#line 230 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
Fire(const CEntityEvent &__eeInput);
  BOOL H0x01580001_Fire_01(const CEntityEvent &__eeInput);
  BOOL H0x01580002_Fire_02(const CEntityEvent &__eeInput);
  BOOL H0x01580003_Fire_03(const CEntityEvent &__eeInput);
  BOOL H0x01580004_Fire_04(const CEntityEvent &__eeInput);
  BOOL H0x01580005_Fire_05(const CEntityEvent &__eeInput);
  BOOL H0x01580006_Fire_06(const CEntityEvent &__eeInput);
#define  STATE_CGuffy_Main 1
  BOOL 
#line 296 "V:/Programs/SamSDK/Sources/EntitiesMP/Guffy.es"
Main(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_Guffy_INCLUDED
