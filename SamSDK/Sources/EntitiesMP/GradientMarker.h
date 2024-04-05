/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_GradientMarker_INCLUDED
#define _EntitiesMP_GradientMarker_INCLUDED 1
#include <EntitiesMP/Marker.h>
#include <EntitiesMP/WorldBase.h>
extern "C" DECL_DLL CDLLEntityClass CGradientMarker_DLLClass;
class CGradientMarker : public CMarker {
public:
virtual BOOL IsImportant(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
  FLOAT m_fHeight;
  BOOL m_bDarkLight;
  COLOR m_colColor0;
  COLOR m_colColor1;
   
#line 27 "V:/Programs/SamSDK/Sources/EntitiesMP/GradientMarker.es"
const CTString & GetGradientName(void);
   
#line 32 "V:/Programs/SamSDK/Sources/EntitiesMP/GradientMarker.es"
BOOL GetGradient(INDEX iGradient,class CGradientParameters & gpGradient);
   
#line 49 "V:/Programs/SamSDK/Sources/EntitiesMP/GradientMarker.es"
void UncacheShadowsForGradient(void);
   
#line 61 "V:/Programs/SamSDK/Sources/EntitiesMP/GradientMarker.es"
void SetPlacement_internal(const CPlacement3D & plNew,const FLOATmatrix3D & mRotation,BOOL bNear);
   
#line 67 "V:/Programs/SamSDK/Sources/EntitiesMP/GradientMarker.es"
void OnEnd(void);
#define  STATE_CGradientMarker_Main 1
  BOOL 
#line 75 "V:/Programs/SamSDK/Sources/EntitiesMP/GradientMarker.es"
Main(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_GradientMarker_INCLUDED
