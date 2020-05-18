/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

Shooter::Shooter() {
  m_LeftMotor.Follow(m_RightMotor);
  m_LeftMotor.SetInverted(true);
  m_RightMotor.ConfigVoltageCompSaturation(12.5);
  m_LeftMotor.ConfigVoltageCompSaturation(12.5);
  m_RightMotor.EnableVoltageCompensation(true);
  m_LeftMotor.EnableVoltageCompensation(true);
  m_Timer.Reset();
  m_Timer.Stop();
}

void Shooter::Shoot(double power) {
  m_RightMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, power);
}

void Shooter::SetRamp(double seconds_from_neutral_to_full) {
  m_RightMotor.ConfigOpenloopRamp(seconds_from_neutral_to_full);
  m_LeftMotor.ConfigOpenloopRamp(seconds_from_neutral_to_full);
}

double Shooter::GetTimer() { return m_Timer.Get(); }

void Shooter::ResetTimer() {
  m_Timer.Reset();
  m_Timer.Start();
}

void Shooter::StopTimer() {
  m_Timer.Reset();
  m_Timer.Stop();
}

void Shooter::Periodic() {}
