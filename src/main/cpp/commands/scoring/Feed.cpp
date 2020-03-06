/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/Feed.h"

Feed::Feed(Feeder* feeder, Intake* intake, Shooter* shooter)
    : m_feeder(feeder), m_intake(intake), m_shooter(shooter) {
  AddRequirements(m_feeder);
  AddRequirements(m_intake);
}

void Feed::Initialize() { m_timeout = std::max(TOTAL_CHARGE_TIME, m_shooter->GetTimer()) + 1.5; }

void Feed::Execute() {
  std::cout << " ############################################ 5 " << std::endl;
  if (m_shooter->GetTimer() >= m_timeout) {
    m_feeder->Activate();
  }

  m_intake->Activate();
  std::cout << " ############################################ 6 " << std::endl;
}

void Feed::End(bool interrupted) {
  m_feeder->Stop();
  m_intake->Stop();
}

bool Feed::IsFinished() { return false; }
