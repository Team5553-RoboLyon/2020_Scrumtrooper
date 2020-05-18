/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/endgame/LiftRobot.h"

LiftRobot::LiftRobot(Winch* pwinch) : m_pWinch(pwinch) { AddRequirements(m_pWinch); }

void LiftRobot::Initialize() { m_pWinch->GoUp(); }

void LiftRobot::Execute() {}

void LiftRobot::End(bool interrupted) { m_pWinch->Stop(); }

bool LiftRobot::IsFinished() { return false; }
