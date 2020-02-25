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
  m_turret->SetGoal(m_turret->GetController().GetGoal().position + 5.0_deg);
}

void MoveTurretRight::Execute() {}

void MoveTurretRight::End(bool interrupted) {
  m_turret->Disable();
  m_turret->Stop();
}

bool MoveTurretRight::IsFinished() { return m_turret->GetController().AtGoal(); }
