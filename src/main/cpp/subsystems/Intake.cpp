/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

Intake::Intake() {
  m_Motor.SetInverted(true);
  Close();
}

void Intake::Open() {
  Stop();
  m_Solenoid.Set(frc::DoubleSolenoid::Value::kForward);
  m_Position = IntakePosition::kOpened;
}

void Intake::Close() {
  Stop();
  m_Solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
  m_Position = IntakePosition::kClosed;
}

void Intake::ChangePosition() {
  if (m_Position == IntakePosition::kOpened) {
    Close();
  } else {
    Open();
  }
}

void Intake::Activate() {
  if (m_Position == IntakePosition::kOpened) {
    m_Motor.Set(INTAKE_OPENED_SPEED);
  } else {
    m_Motor.Set(INTAKE_CLOSED_SPEED);
  }
}

void Intake::Stop() { m_Motor.Set(0.0); }
