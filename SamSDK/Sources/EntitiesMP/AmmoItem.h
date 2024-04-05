/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_AmmoItem_INCLUDED
#define _EntitiesMP_AmmoItem_INCLUDED 1
#include <EntitiesMP/Item.h>
extern DECL_DLL CEntityPropertyEnumType AmmoItemType_enum;
enum AmmoItemType {
  AIT_SHELLS = 1,
  AIT_BULLETS = 2,
  AIT_ROCKETS = 3,
  AIT_GRENADES = 4,
  AIT_ELECTRICITY = 5,
  AIT_NUKEBALL = 6,
  AIT_IRONBALLS = 7,
  AIT_SERIOUSPACK = 8,
  AIT_BACKPACK = 9,
  AIT_NAPALM = 10,
  AIT_SNIPERBULLETS = 11,
  AIT_PISTOL = 12,
};
DECL_DLL inline void ClearToDefault(AmmoItemType &e) { e = (AmmoItemType)0; } ;
#define EVENTCODE_EAmmoItem 0x03230000
class DECL_DLL EAmmoItem : public CEntityEvent {
public:
EAmmoItem();
CEntityEvent *MakeCopy(void);
enum AmmoItemType EaitType;
INDEX iQuantity;
};
DECL_DLL inline void ClearToDefault(EAmmoItem &e) { e = EAmmoItem(); } ;
extern "C" DECL_DLL CDLLEntityClass CAmmoItem_DLLClass;
class CAmmoItem : public CItem {
public:
  DECL_DLL virtual void SetDefaultProperties(void);
  enum AmmoItemType m_EaitType;
   
#line 126 "V:/Programs/SamSDK/Sources/EntitiesMP/AmmoItem.es"
void Precache(void);
   
#line 131 "V:/Programs/SamSDK/Sources/EntitiesMP/AmmoItem.es"
void RenderParticles(void);
   
#line 176 "V:/Programs/SamSDK/Sources/EntitiesMP/AmmoItem.es"
BOOL FillEntityStatistics(EntityStats * pes);
   
#line 238 "V:/Programs/SamSDK/Sources/EntitiesMP/AmmoItem.es"
void SetProperties(void);
   
#line 368 "V:/Programs/SamSDK/Sources/EntitiesMP/AmmoItem.es"
void AdjustDifficulty(void);
#define  STATE_CAmmoItem_ItemCollected 0x03230001
  BOOL 
#line 378 "V:/Programs/SamSDK/Sources/EntitiesMP/AmmoItem.es"
ItemCollected(const CEntityEvent &__eeInput);
#define  STATE_CAmmoItem_Main 1
  BOOL 
#line 417 "V:/Programs/SamSDK/Sources/EntitiesMP/AmmoItem.es"
Main(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_AmmoItem_INCLUDED
