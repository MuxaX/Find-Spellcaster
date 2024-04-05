/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "V:/Programs/SamSDK/Sources/EntitiesMP/Global.es"

#include "StdH.h"

#include <EntitiesMP/Global.h>
#include <EntitiesMP/Global_tables.h>
CEntityEvent *EStop::MakeCopy(void) { CEntityEvent *peeCopy = new EStop(*this); return peeCopy;}
EStop::EStop() : CEntityEvent(EVENTCODE_EStop) {;
};
CEntityEvent *EStart::MakeCopy(void) { CEntityEvent *peeCopy = new EStart(*this); return peeCopy;}
EStart::EStart() : CEntityEvent(EVENTCODE_EStart) {;
 ClearToDefault(penCaused);
};
CEntityEvent *EActivate::MakeCopy(void) { CEntityEvent *peeCopy = new EActivate(*this); return peeCopy;}
EActivate::EActivate() : CEntityEvent(EVENTCODE_EActivate) {;
};
CEntityEvent *EDeactivate::MakeCopy(void) { CEntityEvent *peeCopy = new EDeactivate(*this); return peeCopy;}
EDeactivate::EDeactivate() : CEntityEvent(EVENTCODE_EDeactivate) {;
};
CEntityEvent *EEnvironmentStart::MakeCopy(void) { CEntityEvent *peeCopy = new EEnvironmentStart(*this); return peeCopy;}
EEnvironmentStart::EEnvironmentStart() : CEntityEvent(EVENTCODE_EEnvironmentStart) {;
};
CEntityEvent *EEnvironmentStop::MakeCopy(void) { CEntityEvent *peeCopy = new EEnvironmentStop(*this); return peeCopy;}
EEnvironmentStop::EEnvironmentStop() : CEntityEvent(EVENTCODE_EEnvironmentStop) {;
};
CEntityEvent *EEnd::MakeCopy(void) { CEntityEvent *peeCopy = new EEnd(*this); return peeCopy;}
EEnd::EEnd() : CEntityEvent(EVENTCODE_EEnd) {;
};
CEntityEvent *ETrigger::MakeCopy(void) { CEntityEvent *peeCopy = new ETrigger(*this); return peeCopy;}
ETrigger::ETrigger() : CEntityEvent(EVENTCODE_ETrigger) {;
 ClearToDefault(penCaused);
};
CEntityEvent *ETeleportMovingBrush::MakeCopy(void) { CEntityEvent *peeCopy = new ETeleportMovingBrush(*this); return peeCopy;}
ETeleportMovingBrush::ETeleportMovingBrush() : CEntityEvent(EVENTCODE_ETeleportMovingBrush) {;
};
CEntityEvent *EReminder::MakeCopy(void) { CEntityEvent *peeCopy = new EReminder(*this); return peeCopy;}
EReminder::EReminder() : CEntityEvent(EVENTCODE_EReminder) {;
 ClearToDefault(iValue);
};
CEntityEvent *EStartAttack::MakeCopy(void) { CEntityEvent *peeCopy = new EStartAttack(*this); return peeCopy;}
EStartAttack::EStartAttack() : CEntityEvent(EVENTCODE_EStartAttack) {;
};
CEntityEvent *EStopAttack::MakeCopy(void) { CEntityEvent *peeCopy = new EStopAttack(*this); return peeCopy;}
EStopAttack::EStopAttack() : CEntityEvent(EVENTCODE_EStopAttack) {;
};
CEntityEvent *EStopBlindness::MakeCopy(void) { CEntityEvent *peeCopy = new EStopBlindness(*this); return peeCopy;}
EStopBlindness::EStopBlindness() : CEntityEvent(EVENTCODE_EStopBlindness) {;
};
CEntityEvent *EStopDeafness::MakeCopy(void) { CEntityEvent *peeCopy = new EStopDeafness(*this); return peeCopy;}
EStopDeafness::EStopDeafness() : CEntityEvent(EVENTCODE_EStopDeafness) {;
};
CEntityEvent *EReceiveScore::MakeCopy(void) { CEntityEvent *peeCopy = new EReceiveScore(*this); return peeCopy;}
EReceiveScore::EReceiveScore() : CEntityEvent(EVENTCODE_EReceiveScore) {;
 ClearToDefault(iPoints);
};
CEntityEvent *EKilledEnemy::MakeCopy(void) { CEntityEvent *peeCopy = new EKilledEnemy(*this); return peeCopy;}
EKilledEnemy::EKilledEnemy() : CEntityEvent(EVENTCODE_EKilledEnemy) {;
};
CEntityEvent *ESecretFound::MakeCopy(void) { CEntityEvent *peeCopy = new ESecretFound(*this); return peeCopy;}
ESecretFound::ESecretFound() : CEntityEvent(EVENTCODE_ESecretFound) {;
};
CEntityEvent *ESound::MakeCopy(void) { CEntityEvent *peeCopy = new ESound(*this); return peeCopy;}
ESound::ESound() : CEntityEvent(EVENTCODE_ESound) {;
 ClearToDefault(EsndtSound);
 ClearToDefault(penTarget);
};
CEntityEvent *EScroll::MakeCopy(void) { CEntityEvent *peeCopy = new EScroll(*this); return peeCopy;}
EScroll::EScroll() : CEntityEvent(EVENTCODE_EScroll) {;
 ClearToDefault(bStart);
 ClearToDefault(penSender);
};
CEntityEvent *ETextFX::MakeCopy(void) { CEntityEvent *peeCopy = new ETextFX(*this); return peeCopy;}
ETextFX::ETextFX() : CEntityEvent(EVENTCODE_ETextFX) {;
 ClearToDefault(bStart);
 ClearToDefault(penSender);
};
CEntityEvent *EHudPicFX::MakeCopy(void) { CEntityEvent *peeCopy = new EHudPicFX(*this); return peeCopy;}
EHudPicFX::EHudPicFX() : CEntityEvent(EVENTCODE_EHudPicFX) {;
 ClearToDefault(bStart);
 ClearToDefault(penSender);
};
CEntityEvent *ECredits::MakeCopy(void) { CEntityEvent *peeCopy = new ECredits(*this); return peeCopy;}
ECredits::ECredits() : CEntityEvent(EVENTCODE_ECredits) {;
 ClearToDefault(bStart);
 ClearToDefault(penSender);
};
CEntityEvent *ECenterMessage::MakeCopy(void) { CEntityEvent *peeCopy = new ECenterMessage(*this); return peeCopy;}
ECenterMessage::ECenterMessage() : CEntityEvent(EVENTCODE_ECenterMessage) {;
 ClearToDefault(strMessage);
 ClearToDefault(tmLength);
 ClearToDefault(mssSound);
};
CEntityEvent *EComputerMessage::MakeCopy(void) { CEntityEvent *peeCopy = new EComputerMessage(*this); return peeCopy;}
EComputerMessage::EComputerMessage() : CEntityEvent(EVENTCODE_EComputerMessage) {;
 ClearToDefault(fnmMessage);
};
CEntityEvent *EVoiceMessage::MakeCopy(void) { CEntityEvent *peeCopy = new EVoiceMessage(*this); return peeCopy;}
EVoiceMessage::EVoiceMessage() : CEntityEvent(EVENTCODE_EVoiceMessage) {;
 ClearToDefault(fnmMessage);
};
CEntityEvent *EHitBySpaceShipBeam::MakeCopy(void) { CEntityEvent *peeCopy = new EHitBySpaceShipBeam(*this); return peeCopy;}
EHitBySpaceShipBeam::EHitBySpaceShipBeam() : CEntityEvent(EVENTCODE_EHitBySpaceShipBeam) {;
};
void CGlobal::SetDefaultProperties(void) {
  CEntity::SetDefaultProperties();
}
BOOL CGlobal::
#line 295 "V:/Programs/SamSDK/Sources/EntitiesMP/Global.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGlobal_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CGlobal::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 296 "V:/Programs/SamSDK/Sources/EntitiesMP/Global.es"
ASSERTALWAYS  ("DON'T INSTANTIATE THIS CLASS"); ASSERT(FALSE); return TRUE;};