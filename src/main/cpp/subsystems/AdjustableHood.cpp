/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/AdjustableHood.h"

AdjustableHood::AdjustableHood()
    : PIDSubsystem(frc2::PIDController(ADJUSTABLE_HOOD_P_GAIN, ADJUSTABLE_HOOD_I_GAIN,
                                       ADJUSTABLE_HOOD_D_GAIN)) {
  m_Encoder.SetDistancePerRotation(ADJUSTABLE_HOOD_POSITION_CONVERSION_FACTOR);
  m_Encoder.Reset();
  GetController().SetIntegratorRange(-0.03, 0.03);
  Disable();
  m_LockedCount = 0;
}

void AdjustableHood::UseOutput(double output, double setpoint) {
  if ((std::abs(setpoint - m_Encoder.GetDistance()) > 1) &&
      (std::abs(GetController().GetVelocityError()) < 1) && (std::abs(output) > 0.05)) {
    m_LockedCount++;
    if (m_LockedCount > 8) {
      SetSetpoint(m_Encoder.GetDistance());
      GetController().Reset();
      m_LockedCount = 0;
    }
  } else {
    m_LockedCount = 0;
  }
  m_PrevVelocityError = GetController().GetVelocityError();

  m_Motor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, output);
}

void AdjustableHood::SetClampedSetpoint(double setpoint) {
  SetSetpoint(std::clamp(setpoint, 0.0, 46.0));
}

double AdjustableHood::GetMeasurement() { return m_Encoder.GetDistance(); }

void AdjustableHood::ResetEncoder() { m_Encoder.Reset(); }

void AdjustableHood::GoUp() {
  if (!IsEnabled()) m_Motor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.25);
}

void AdjustableHood::GoDown() {
  if (!IsEnabled()) m_Motor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.25);
}

void AdjustableHood::Unblock() {
  if (!IsEnabled()) m_Motor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.5);
}

void AdjustableHood::Stop() {
  if (!IsEnabled()) m_Motor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0);
}
