/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/MoveTurret.h"

#include <iostream>

MoveTurret::MoveTurret(Turret* turret, double angle) : m_turret(turret), m_angle(angle) {
  AddRequirements(m_turret);
}

void MoveTurret::Initialize() {
  m_turret->Enable();
  m_turret->SetSetpoint(m_angle);
}

void MoveTurret::Execute() {}

void MoveTurret::End(bool interrupted) {
  m_turret->Disable();
  m_turret->Stop();
}

bool MoveTurret::IsFinished() { return std::abs(m_angle - m_turret->GetMeasurement()) < 1; }
