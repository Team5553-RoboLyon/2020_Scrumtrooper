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

void Shoot::Initialize() {}

void Shoot::Execute() {
  double m_pitch = m_chameleonPitchEntry.GetDouble(0.0);
  double puissance = m_pitch * m_pitch * 0.0252 + m_pitch * 0.215 + 1.27;

  m_shooter->Shoot(puissance);
}

void Shoot::End(bool interrupted) { m_shooter->Shoot(0.0); }

bool Shoot::IsFinished() { return false; }
