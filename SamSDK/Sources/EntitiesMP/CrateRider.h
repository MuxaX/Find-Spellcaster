/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_CrateRider_INCLUDED
#define _EntitiesMP_CrateRider_INCLUDED 1
#include <EntitiesMP/EnemyBase.h>
#include <EntitiesMP/BasicEffects.h>
extern "C" DECL_DLL CDLLEntityClass CCrateRider_DLLClass;
class CCrateRider : public CEnemyBase {
public:
  DECL_DLL virtual void SetDefaultProperties(void);
  CTFileName m_fnmHeadTex1;
  CTFileName m_fnmHeadTex2;
  CTFileName m_fnmDriveSnd;
CAutoPrecacheSound m_aps;
CAutoPrecacheTexture m_apt1;
CAutoPrecacheTexture m_apt2;
   
#line 56 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
void * GetEntityInfo(void);
   
#line 61 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
void Precache(void);
   
#line 73 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
INDEX AnimForDamage(FLOAT fDamage);
   
#line 81 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
INDEX AnimForDeath(void);
   
#line 88 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
void DeathNotify(void);
   
#line 94 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
void StandingAnim(void);
   
#line 104 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
void WalkingAnim(void);
   
#line 108 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
void RunningAnim(void);
   
#line 120 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
void RotatingAnim(void);
   
#line 125 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
void IdleSound(void);
   
#line 129 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
void SightSound(void);
   
#line 132 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
void WoundSound(void);
   
#line 135 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
void DeathSound(void);
   
#line 139 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
void AddRider(INDEX i,const CTFileName & fnmHead);
#define  STATE_CCrateRider_Main 1
  BOOL 
#line 164 "V:/Programs/SamSDK/Sources/EntitiesMP/CrateRider.es"
Main(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_CrateRider_INCLUDED
