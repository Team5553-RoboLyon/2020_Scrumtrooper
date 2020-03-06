/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/driving/AutoDrive.h"

AutoDrive::AutoDrive(Drivetrain* drivetrain, double distance)
    : m_drivetrain(drivetrain), m_distance(distance) {
  AddRequirements(m_drivetrain);
}

void AutoDrive::Initialize() {
  m_drivetrain->ResetEncodeurs();
  m_drivetrain->DisableRamp();
}

void AutoDrive::End(bool interrupted) { m_drivetrain->EnableRamp(); }

bool AutoDrive::IsFinished() {
  return (m_drivetrain->m_encoderValue > m_drivetrain->m_nbrTickAutomatedShoot - 3 &&
          m_drivetrain->m_encoderValue < m_drivetrain->m_nbrTickAutomatedShoot + 3);
}
