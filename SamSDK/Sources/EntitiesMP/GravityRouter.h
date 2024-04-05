/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_GravityRouter_INCLUDED
#define _EntitiesMP_GravityRouter_INCLUDED 1
#include <EntitiesMP/Marker.h>
#define EVENTCODE_EChangeGravity 0x00e30000
class DECL_DLL EChangeGravity : public CEntityEvent {
public:
EChangeGravity();
CEntityEvent *MakeCopy(void);
CEntityPointer penNewGravity;
};
DECL_DLL inline void ClearToDefault(EChangeGravity &e) { e = EChangeGravity(); } ;
extern "C" DECL_DLL CDLLEntityClass CGravityRouter_DLLClass;
class CGravityRouter : public CMarker {
public:
virtual BOOL IsImportant(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
   
#line 26 "V:/Programs/SamSDK/Sources/EntitiesMP/GravityRouter.es"
const CTString & GetForceName(INDEX i);
   
#line 32 "V:/Programs/SamSDK/Sources/EntitiesMP/GravityRouter.es"
void GetForce(INDEX i,const FLOAT3D & vPoint,
#line 33 "V:/Programs/SamSDK/Sources/EntitiesMP/GravityRouter.es"
CForceStrength & fsGravity,CForceStrength & fsField);
   
#line 41 "V:/Programs/SamSDK/Sources/EntitiesMP/GravityRouter.es"
CEntity * GetForceController(INDEX iForce);
   
#line 47 "V:/Programs/SamSDK/Sources/EntitiesMP/GravityRouter.es"
BOOL HandleEvent(const CEntityEvent & ee);
#define  STATE_CGravityRouter_Main 1
  BOOL 
#line 60 "V:/Programs/SamSDK/Sources/EntitiesMP/GravityRouter.es"
Main(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_GravityRouter_INCLUDED
