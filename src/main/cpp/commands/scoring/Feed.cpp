/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/Feed.h"

Feed::Feed(Feeder* feeder, Intake* intake, Shooter* shooter, bool enableIntake)
    : m_feeder(feeder), m_intake(intake), m_shooter(shooter), m_isIntakeEnabled(enableIntake) {
  AddRequirements(m_feeder);
  if (m_isIntakeEnabled) {
    AddRequirements(m_intake);
  }
}

void Feed::Initialize() { m_timeout = std::max(TOTAL_CHARGE_TIME, m_shooter->GetTimer()) + 1.5; }

void Feed::Execute() {
  if (m_shooter->GetTimer() >= m_timeout) {
    m_feeder->Activate();
  }
  if (m_isIntakeEnabled) {
    m_intake->Activate();
  }
}

void Feed::End(bool interrupted) {
  m_feeder->Stop();
  if (m_isIntakeEnabled) {
    m_intake->Stop();
  }
}

bool Feed::IsFinished() { return false; }
