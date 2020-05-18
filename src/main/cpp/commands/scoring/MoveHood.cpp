/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/MoveHood.h"

MoveHood::MoveHood(AdjustableHood* padjustable_hood, double angle)
    : m_pAdjustableHood(padjustable_hood), m_Angle(angle) {
  AddRequirements(m_pAdjustableHood);
}

void MoveHood::Initialize() {
  m_pAdjustableHood->Enable();
  m_pAdjustableHood->SetSetpoint(m_Angle);
}

void MoveHood::Execute() {}

void MoveHood::End(bool interrupted) {
  m_pAdjustableHood->Disable();
  m_pAdjustableHood->Stop();
}

bool MoveHood::IsFinished() { return std::abs(m_Angle - m_pAdjustableHood->GetMeasurement()) < 1; }
