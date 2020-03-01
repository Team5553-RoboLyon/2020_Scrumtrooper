/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/MoveHood.h"

MoveHood::MoveHood(AdjustableHood* adjustableHood, double angle)
    : m_adjustablehood(adjustableHood), m_angle(angle) {
  AddRequirements(m_adjustablehood);
}

void MoveHood::Initialize() {
  m_adjustablehood->Enable();
  m_adjustablehood->SetSetpoint(m_angle);
}

void MoveHood::Execute() {}

void MoveHood::End(bool interrupted) {
  m_adjustablehood->Disable();
  m_adjustablehood->Stop();
}

bool MoveHood::IsFinished() { return std::abs(m_angle - m_adjustablehood->GetMeasurement()) < 1; }
