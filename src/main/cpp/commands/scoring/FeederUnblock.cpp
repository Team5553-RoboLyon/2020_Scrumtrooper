/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/FeederUnblock.h"

FeederUnblock::FeederUnblock(Feeder* feeder) : m_feeder(feeder) { AddRequirements(m_feeder); }

void FeederUnblock::Initialize() {}

void FeederUnblock::Execute() { m_feeder->UnBlock(); }

void FeederUnblock::End(bool interrupted) { m_feeder->Stop(); }

bool FeederUnblock::IsFinished() { return false; }
