/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/endgame/DropRobot.h"

DropRobot::DropRobot(Winch* pwinch) : m_pWinch(pwinch) { AddRequirements(m_pWinch); }

void DropRobot::Initialize() { m_pWinch->GoDown(); }

void DropRobot::Execute() {}

void DropRobot::End(bool interrupted) { m_pWinch->Stop(); }

bool DropRobot::IsFinished() { return false; }
