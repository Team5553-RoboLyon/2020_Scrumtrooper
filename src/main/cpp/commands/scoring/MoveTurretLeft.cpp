/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/MoveTurretLeft.h"

MoveTurretLeft::MoveTurretLeft(Turret* turret) : m_turret(turret) { AddRequirements(m_turret); }

void MoveTurretLeft::Initialize() {}

void MoveTurretLeft::Execute() { m_turret->Left(); }

void MoveTurretLeft::End(bool interrLeftted) { m_turret->Stop(); }

bool MoveTurretLeft::IsFinished() { return true; }
