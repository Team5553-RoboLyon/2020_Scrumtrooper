/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

Intake::Intake() { Close(); }

void Intake::Open() {
  m_solenoid.Set(frc::DoubleSolenoid::Value::kForward);
  m_position = IntakePosition::kOpened;
}
void Intake::Close() {
  Stop();
  m_solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
  m_position = IntakePosition::kClosed;
}

void Intake::ChangePosition() {
  if (m_position == IntakePosition::kOpened) {
    Close();
  } else {
    Open();
  };
}

void Intake::Activate() {
  if (m_position == IntakePosition::kOpened) {
    m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, kIntakeMoteurSpeedOpened);
  } else {
    m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, kIntakeMoteurSpeedClosed);
  }
}

void Intake::Stop() { m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0); }