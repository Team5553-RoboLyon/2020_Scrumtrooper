/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/Feed.h"

Feed::Feed(Feeder* pfeeder, Intake* pintake, Shooter* pshooter, bool enable_intake)
    : m_pFeeder(pfeeder),
      m_pIntake(pintake),
      m_pShooter(pshooter),
      m_IsIntakeEnabled(enable_intake) {
  AddRequirements(m_pFeeder);
  if (m_IsIntakeEnabled) {
    AddRequirements(m_pIntake);
  }
}

void Feed::Initialize() { m_Timeout = std::max(TOTAL_CHARGE_TIME, m_pShooter->GetTimer()) + 1.5; }

void Feed::Execute() {
  if (m_pShooter->GetTimer() >= m_Timeout) {
    m_pFeeder->Activate();
  }
  if (m_IsIntakeEnabled) {
    m_pIntake->Activate();
  }
}

void Feed::End(bool interrupted) {
  m_pFeeder->Stop();
  if (m_IsIntakeEnabled) {
    m_pIntake->Stop();
  }
}

bool Feed::IsFinished() { return false; }
