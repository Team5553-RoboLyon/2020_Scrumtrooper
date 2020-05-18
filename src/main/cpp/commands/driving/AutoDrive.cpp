/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/driving/AutoDrive.h"

AutoDrive::AutoDrive(Drivetrain* pdrivetrain, double distance)
    : m_pDrivetrain(pdrivetrain), m_Distance(distance), m_Integral(0), m_PrevError(distance) {
  AddRequirements(m_pDrivetrain);
}

void AutoDrive::Initialize() {
  m_pDrivetrain->ResetEncodeurs();
  // m_pDrivetrain->DisableRamp();
}

void AutoDrive::Execute() {
  double encoderValue = (m_pDrivetrain->GetRightEncoder() + m_pDrivetrain->GetLeftEncoder()) / 2;

  double error = m_Distance - encoderValue;
  m_Integral += (error * .02);
  double derivative = (error - m_PrevError) / .02;
  double power = 0.0025 * error + 0.00023 * m_Integral + 0.0003 * derivative;

  m_PrevError = error;
  if (power > 0.5) {
    power = 0.5;
  } else if (power < -0.5) {
    power = -0.5;
  }
  m_pDrivetrain->Drive(power, power);
}

void AutoDrive::End(bool interrupted) {
  m_pDrivetrain->EnableRamp();
  m_pDrivetrain->Stop();
}

bool AutoDrive::IsFinished() {
  return std::abs(m_Distance -
                  (m_pDrivetrain->GetRightEncoder() + m_pDrivetrain->GetLeftEncoder()) / 2) < 3;
}
