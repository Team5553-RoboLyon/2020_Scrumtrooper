/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/Shoot.h"

#include <networktables/NetworkTableInstance.h>

Shoot::Shoot(Shooter* pshooter) : m_pShooter(pshooter) {
  m_ChameleonPitchEntry = nt::NetworkTableInstance::GetDefault()
                              .GetTable("chameleon-vision")
                              ->GetEntry("turret/targetPitch");
  m_ChameleonIsValidEntry = nt::NetworkTableInstance::GetDefault()
                                .GetTable("chameleon-vision")
                                ->GetEntry("turret/isValid");
  AddRequirements(m_pShooter);
}

void Shoot::Initialize() { m_pShooter->SetRamp(0); }

void Shoot::Execute() {
  double power = 1;
  double pitch = m_ChameleonPitchEntry.GetDouble(0.0);
  if (pitch < 2 && pitch > -2) {
    power = 0.96;
  } else {
    power = 1;
    // power = pitch * pitch * 0.0033 + pitch * 0.0358 + 0.96;
    // pitch * pitch * 0.00329 + pitch * 0.0358 + 0.949;
    // pitch * pitch * 0.00215 + pitch * 0.0247 + 0.907
  }
  m_pShooter->Shoot(power);
}

void Shoot::End(bool interrupted) { m_pShooter->Shoot(0.0); }

bool Shoot::IsFinished() { return false; }
