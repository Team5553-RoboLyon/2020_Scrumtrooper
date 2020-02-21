/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/endgame/DropRobot.h"

DropRobot::DropRobot(Winch* winch) : m_winch(winch) { AddRequirements(m_winch); }

void DropRobot::Initialize() {}

void DropRobot::Execute() { m_winch->Down(); }

void DropRobot::End(bool interrupted) {}

bool DropRobot::IsFinished() { return false; }
