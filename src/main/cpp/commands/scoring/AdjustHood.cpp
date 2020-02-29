/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/AdjustHood.h"
#include <networktables/NetworkTableInstance.h>
#include <iostream>

AdjustHood::AdjustHood(AdjustableHood* adjustableHood) : m_adjustablehood(adjustableHood) {
  AddRequirements(m_adjustablehood);

  m_chameleonPitchEntry = nt::NetworkTableInstance::GetDefault()
                            .GetTable("chameleon-vision")
                            ->GetEntry("turret/targetPitch");
  m_chameleonIsValidEntry = nt::NetworkTableInstance::GetDefault()
                                .GetTable("chameleon-vision")
                                ->GetEntry("turret/isValid");
}

void AdjustHood::Initialize() { m_adjustablehood->Enable(); }

void AdjustHood::Execute() {


}

void AdjustHood::End(bool interrupted) {
  m_adjustablehood->Disable();
  m_adjustablehood->Stop();
}

bool AdjustHood::IsFinished() { return false; }
