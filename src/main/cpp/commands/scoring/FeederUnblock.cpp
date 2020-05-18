/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/FeederUnblock.h"

FeederUnblock::FeederUnblock(Feeder* pfeeder) : m_pFeeder(pfeeder) { AddRequirements(m_pFeeder); }

void FeederUnblock::Initialize() {}

void FeederUnblock::Execute() { m_pFeeder->UnBlock(); }

void FeederUnblock::End(bool interrupted) { m_pFeeder->Stop(); }

bool FeederUnblock::IsFinished() { return false; }
