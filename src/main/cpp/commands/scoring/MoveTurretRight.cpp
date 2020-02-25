/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/MoveTurretRight.h"

MoveTurretRight::MoveTurretRight(Turret* turret) : m_turret(turret) { AddRequirements(m_turret); }

void MoveTurretRight::Initialize() {
  m_turret->Enable();
  m_turret->SetSetpoint(m_turret->GetController().GetSetpoint() + 10);
}

void MoveTurretRight::Execute() {}

void MoveTurretRight::End(bool interrupted) {
  if (!interrupted) {
    /*m_turret->Disable();
    m_turret->Stop();*/
  }
}

bool MoveTurretRight::IsFinished() {
  return std::abs(m_turret->GetMeasurement() - m_turret->GetController().GetSetpoint()) < 1;
}
