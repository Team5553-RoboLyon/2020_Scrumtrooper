/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Turret.h"

Turret::Turret()
    : frc2::PIDSubsystem(frc2::PIDController(TURRET_P_GAIN, TURRET_I_GAIN, TURRET_D_GAIN)) {
  m_Encoder.SetDistancePerPulse(TURRET_POSITION_CONVERSION_FACTOR);
  m_Encoder.Reset();
  m_Motor.SetInverted(true);
  SetSetpoint(0);
  Disable();
}

void Turret::UseOutput(double output, double setpoint) {
  m_Motor.Set(std::clamp(output, -TURRET_MAX_SPEED, TURRET_MAX_SPEED));
}

double Turret::GetMeasurement() { return m_Encoder.GetDistance(); }

void Turret::SetClampedSetpoint(double setpoint) {
  SetSetpoint(std::clamp(setpoint, -TURRET_MAX_POSITION, TURRET_MAX_POSITION));
}

void Turret::Stop() {
  if (!IsEnabled()) m_Motor.StopMotor();
}

void Turret::TurnLeft() {
  if (!IsEnabled()) m_Motor.Set(-TURRET_SPEED);
}

void Turret::TurnRight() {
  if (!IsEnabled()) m_Motor.Set(TURRET_SPEED);
}
