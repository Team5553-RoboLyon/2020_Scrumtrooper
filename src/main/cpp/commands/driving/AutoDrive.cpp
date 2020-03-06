/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/driving/AutoDrive.h"

AutoDrive::AutoDrive(Drivetrain* drivetrain, double distance)
    : m_drivetrain(drivetrain), m_distance(distance), m_integral(0), m_prev_error(distance) {
  AddRequirements(m_drivetrain);
}

void AutoDrive::Initialize() {
  m_drivetrain->ResetEncodeurs();
  // m_drivetrain->DisableRamp();
}

void AutoDrive::Execute() {
  double encoderValue = (m_drivetrain->GetEncodeurDroit() + m_drivetrain->GetEncodeurGauche()) / 2;

  double error = m_distance - encoderValue;
  m_integral += (error * .02);
  double derivative = (error - m_prev_error) / .02;
  double rcw = 0.0025 * error + 0.00023 * m_integral + 0.0003 * derivative;

  m_prev_error = error;
  m_drivetrain->Drive(rcw, rcw);
}

void AutoDrive::End(bool interrupted) {
  m_drivetrain->EnableRamp();
  m_drivetrain->Stop();
}

bool AutoDrive::IsFinished() {
  return std::abs(m_distance -
                  (m_drivetrain->GetEncodeurDroit() + m_drivetrain->GetEncodeurGauche()) / 2) < 3;
}
