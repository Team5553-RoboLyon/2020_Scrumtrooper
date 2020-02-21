/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/MoveTurretRight.h"

MoveTurretRight::MoveTurretRight(Turret* turret) : m_turret(turret) { AddRequirements(m_turret); }

void MoveTurretRight::Initialize() {}

void MoveTurretRight::Execute() { m_turret->Right(); }

void MoveTurretRight::End(bool interrRightted) { m_turret->Stop(); }

bool MoveTurretRight::IsFinished() { return true; }
