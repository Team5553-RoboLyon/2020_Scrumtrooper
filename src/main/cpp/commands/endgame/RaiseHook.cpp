/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/endgame/RaiseHook.h"

RaiseHook::RaiseHook(TelescopicArm* telescopicArm, Intake* intake, Drivetrain* drivetrain)
    : m_telescopicarm(telescopicArm), m_intake(intake), m_drivetrain(drivetrain) {
  AddRequirements(m_telescopicarm);
  AddRequirements(m_intake);
}

void RaiseHook::Initialize() {
  m_intake->Open();
  m_telescopicarm->Up();
}

void RaiseHook::Execute() {
  m_telescopicarm->Up();
  if (m_telescopicarm->GetEncodeur() > 50) {
    m_drivetrain->SlowSpeed();
  }
}

void RaiseHook::End(bool interrupted) { m_telescopicarm->ResistGravity(); }

bool RaiseHook::IsFinished() { return false; }
