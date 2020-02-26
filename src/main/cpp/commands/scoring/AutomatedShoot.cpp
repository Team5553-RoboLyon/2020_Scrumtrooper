/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/AutomatedShoot.h"

AutomatedShoot::AutomatedShoot(Drivetrain* Drivetrain) : m_drivetrain(Drivetrain) {
  AddRequirements(m_drivetrain);
}

void AutomatedShoot::Initialize() {
  m_drivetrain->ResetEncodeurs();
  m_drivetrain->DisableRamp();
}

void AutomatedShoot::Execute() { m_drivetrain->AutomatedShoot(); }

void AutomatedShoot::End(bool interrupted) { m_drivetrain->EnableRamp(); }

bool AutomatedShoot::IsFinished() {
  return (m_drivetrain->m_encoderValue > m_drivetrain->m_nbrTickAutomatedShoot - 3 &&
          m_drivetrain->m_encoderValue < m_drivetrain->m_nbrTickAutomatedShoot + 3);
}
