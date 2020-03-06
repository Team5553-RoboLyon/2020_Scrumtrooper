/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/endgame/DropHook.h"

DropHook::DropHook(TelescopicArm* telescopicArm, Intake* intake, Drivetrain* drivetrain)
    : m_telescopicarm(telescopicArm), m_intake(intake), m_drivetrain(drivetrain) {
  AddRequirements(m_telescopicarm);
  AddRequirements(m_intake);
}

void DropHook::Initialize() {
  m_intake->Open();
  m_telescopicarm->Disable();
  m_telescopicarm->Down();
}

void DropHook::Execute() {
  m_telescopicarm->Down();
  if (m_telescopicarm->GetEncodeur() < 50) {
    m_drivetrain->QuickSpeed();
  }
}

void DropHook::End(bool interrupted) { m_telescopicarm->Stop(); }

bool DropHook::IsFinished() { return false; }
