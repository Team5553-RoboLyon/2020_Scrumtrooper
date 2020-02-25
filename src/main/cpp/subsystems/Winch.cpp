/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Winch.h"

using State = frc::TrapezoidProfile<units::meters>::State;

Winch::Winch()
    : frc2::ProfiledPIDSubsystem<units::meters>(frc::ProfiledPIDController<units::meters>(
          kWinchPGain, 0.0, 0.0, {kWinchMaxVelocity, kWinchMaxAcceleration})) {
  m_moteur.SetInverted(true);
  m_encodeur.SetPosition(0.0);
  m_encodeur.SetPositionConversionFactor(kWinchPositionConversionFactor);
  GetController().SetTolerance(0.1_m);
  SetGoal(0_m);
  Disable();
}

void Winch::UseOutput(double output, State setpoint) { m_moteur.SetVoltage(units::volt_t(output)); }

units::meter_t Winch::GetMeasurement() { return units::meter_t(m_encodeur.GetPosition()); }

void Winch::Up() {
  if (!IsEnabled()) m_moteur.Set(kWinchSpeed);
}

void Winch::Down() {
  if (!IsEnabled()) m_moteur.Set(-kWinchSpeed);
}

void Winch::Stop() {
  if (!IsEnabled()) m_moteur.StopMotor();
}
