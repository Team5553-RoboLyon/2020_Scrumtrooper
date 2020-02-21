/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/endgame/DropHook.h"

DropHook::DropHook(TelescopicArm* telescopicArm) : m_telescopicarm(telescopicArm) {
  AddRequirements(m_telescopicarm);
}

void DropHook::Initialize() {}

void DropHook::Execute() { m_telescopicarm->Down(); }

void DropHook::End(bool interrupted) { m_telescopicarm->Stop(); }

bool DropHook::IsFinished() { return true; }
