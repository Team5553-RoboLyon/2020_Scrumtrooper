/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/endgame/RaiseHook.h"

RaiseHook::RaiseHook(TelescopicArm* telescopicArm) : m_telescopicarm(telescopicArm) {
  AddRequirements(m_telescopicarm);
}

void RaiseHook::Initialize() {
  m_telescopicarm->Disable();
  m_telescopicarm->Up();
}

void RaiseHook::Execute() { m_telescopicarm->Up(); }

void RaiseHook::End(bool interrupted) { m_telescopicarm->Stop(); }

bool RaiseHook::IsFinished() { return false; }
