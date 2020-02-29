/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/Feed.h"

Feed::Feed(Feeder* feeder, Intake* intake) : m_feeder(feeder), m_intake(intake) {
  AddRequirements(m_feeder);
  AddRequirements(m_intake);
}

void Feed::Initialize() {}

void Feed::Execute() {
  m_feeder->Activate();
  m_intake->Activate();
}

void Feed::End(bool interrupted) {
  m_feeder->Stop();
  m_intake->Stop();
}

bool Feed::IsFinished() { return false; }
