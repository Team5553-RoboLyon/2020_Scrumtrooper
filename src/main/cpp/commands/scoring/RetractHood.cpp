/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/RetractHood.h"

RetractHood::RetractHood(AdjustableHood* adjustableHood, double angle)
    : m_adjustablehood(adjustableHood), m_angle(angle) {
  AddRequirements(m_adjustablehood);
}

void RetractHood::Initialize() {
  m_adjustablehood->Enable();
  m_adjustablehood->SetSetpoint(m_angle);
}

void RetractHood::Execute() {}

void RetractHood::End(bool interrupted) { m_adjustablehood->SetSetpoint(0.0); }

bool RetractHood::IsFinished() { return false; }
