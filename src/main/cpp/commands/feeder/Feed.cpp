/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/feeder/Feed.h"

#include <iostream>

Feed::Feed(Feeder* Feeder)
    : m_feeder(Feeder) {
  AddRequirements(m_feeder);
}

void Feed::Initialize() {}

void Feed::Execute() {
  m_feeder->Activate();
}

void Feed::End(bool interrupted) {
  m_feeder->Stop();
}

bool Feed::IsFinished() { return false; }
