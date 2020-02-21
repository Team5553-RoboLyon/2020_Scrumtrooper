/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/intake/TakeCell.h"

TakeCell::TakeCell(Intake* intake) : m_intake(intake) { AddRequirements(m_intake); }

void TakeCell::Initialize() { m_intake->Activate(); }

void TakeCell::Execute() {}

void TakeCell::End(bool interrupted) { m_intake->Stop(); }

bool TakeCell::IsFinished() { return false; }