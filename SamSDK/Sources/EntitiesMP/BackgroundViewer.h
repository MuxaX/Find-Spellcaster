/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_BackgroundViewer_INCLUDED
#define _EntitiesMP_BackgroundViewer_INCLUDED 1
#include <EntitiesMP/Marker.h>
extern "C" DECL_DLL CDLLEntityClass CBackgroundViewer_DLLClass;
class CBackgroundViewer : public CMarker {
public:
virtual BOOL IsImportant(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
  BOOL m_bActive;
  CEntityPointer m_penWorldSettingsController;
   
#line 23 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
BOOL IsTargetValid(SLONG slPropertyOffset,CEntity * penTarget);
   
#line 37 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
BOOL HandleEvent(const CEntityEvent & ee);
#define  STATE_CBackgroundViewer_Main 1
  BOOL 
#line 47 "V:/Programs/SamSDK/Sources/EntitiesMP/BackgroundViewer.es"
Main(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_BackgroundViewer_INCLUDED
