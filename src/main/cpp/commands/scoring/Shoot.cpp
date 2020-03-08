/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/Shoot.h"

#include "networktables/NetworkTableInstance.h"

Shoot::Shoot(Shooter* shooter) : m_shooter(shooter) {
  m_chameleonPitchEntry = nt::NetworkTableInstance::GetDefault()
                              .GetTable("chameleon-vision")
                              ->GetEntry("turret/targetPitch");
  m_chameleonIsValidEntry = nt::NetworkTableInstance::GetDefault()
                                .GetTable("chameleon-vision")
                                ->GetEntry("turret/isValid");
  AddRequirements(m_shooter);
}

void Shoot::Initialize() { m_shooter->SetRamp(0); }

void Shoot::Execute() {
  double puissance = 1;
  double m_pitch = m_chameleonPitchEntry.GetDouble(0.0);
  if (m_pitch < 2 && m_pitch > -2) {
    puissance = 0.96;
  } else {
    puissance = 1;
    // puissance = m_pitch * m_pitch * 0.0033 + m_pitch * 0.0358 + 0.96;
    // m_pitch * m_pitch * 0.00329 + m_pitch * 0.0358 + 0.949;
    // m_pitch * m_pitch * 0.00215 + m_pitch * 0.0247 + 0.907
  }
  m_shooter->Shoot(puissance);
}

void Shoot::End(bool interrupted) { m_shooter->Shoot(0.0); }

bool Shoot::IsFinished() { return false; }
