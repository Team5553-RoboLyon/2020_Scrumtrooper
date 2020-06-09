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

  m_ChameleonPitchEntry = nt::NetworkTableInstance::GetDefault()
                              .GetTable("chameleon-vision")
                              ->GetEntry("turret/targetPitch");
  m_ChameleonIsValidEntry = nt::NetworkTableInstance::GetDefault()
                                .GetTable("chameleon-vision")
                                ->GetEntry("turret/isValid");
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

void AdjustableHood::Adjust() {
  if (m_ChameleonIsValidEntry.GetBoolean(false)) {
    m_BufferPitch[m_BufferCount] = m_ChameleonPitchEntry.GetDouble(0);
  }
  m_BufferCount = (m_BufferCount + 1) % HOOD_BUFFER_SIZE;

  std::partial_sort_copy(&m_BufferPitch[0], &m_BufferPitch[HOOD_BUFFER_SIZE - 1],
                         &m_BufferPitchSorted[0], &m_BufferPitchSorted[HOOD_BUFFER_SIZE - 1]);
  if (std::abs(m_BufferPitchSorted[(int)(HOOD_BUFFER_SIZE / 2)]) < 2) {
    SetClampedSetpoint(42);
  } else if (m_BufferPitchSorted[(int)(HOOD_BUFFER_SIZE / 2)] < -4) {
    SetClampedSetpoint(45);
  } else if (m_BufferPitchSorted[(int)(HOOD_BUFFER_SIZE / 2)] < 0) {
    SetClampedSetpoint(46);
  } else {
    double angle = 47.4 * std::exp(-m_BufferPitchSorted[(int)(HOOD_BUFFER_SIZE / 2)] / 51.1);
    SetClampedSetpoint(angle);
  }
}
