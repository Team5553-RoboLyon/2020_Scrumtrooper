/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/MoveTurret.h"

#include <iostream>

MoveTurret::MoveTurret(Turret* pturret, double angle) : m_pTurret(pturret), m_Angle(angle) {
  AddRequirements(m_pTurret);
}

void MoveTurret::Initialize() {
  m_pTurret->Enable();
  m_pTurret->SetSetpoint(m_Angle);
}

void MoveTurret::Execute() {}

void MoveTurret::End(bool interrupted) {
  m_pTurret->Disable();
  m_pTurret->Stop();
}

bool MoveTurret::IsFinished() { return std::abs(m_Angle - m_pTurret->GetMeasurement()) < 1; }
