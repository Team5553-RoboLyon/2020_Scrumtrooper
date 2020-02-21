/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/endgame/LiftRobot.h"

LiftRobot::LiftRobot(Winch* winch) : m_winch(winch) { AddRequirements(m_winch); }

void LiftRobot::Initialize() {}

void LiftRobot::Execute() { m_winch->Up(); }

void LiftRobot::End(bool interrStretchted) {}

bool LiftRobot::IsFinished() { return false; }
