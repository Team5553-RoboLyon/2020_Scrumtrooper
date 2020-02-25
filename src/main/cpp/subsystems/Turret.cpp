/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Turret.h"

using State = frc::TrapezoidProfile<units::degrees>::State;

Turret::Turret()
    : frc2::ProfiledPIDSubsystem<units::degrees>(frc::ProfiledPIDController<units::degrees>(
          kTurretPGain, 0.0, 0.0, {kTurretMaxVelocity, kTurretMaxAcceleration})) {
  m_encodeur.SetDistancePerPulse(kTurretPositionConversionFactor);
  m_encodeur.Reset();
  m_moteur.SetInverted(true);
  GetController().SetTolerance(1.0_deg);
  SetGoal(0_deg);
  Disable();
}

void Turret::UseOutput(double output, State setpoint) {
  m_moteur.SetVoltage(units::volt_t(output));
}

units::degree_t Turret::GetMeasurement() { return units::degree_t(m_encodeur.GetDistance()); }

void Turret::Stop() {
  if (!IsEnabled()) m_moteur.StopMotor();
}

void Turret::Left() {
  if (!IsEnabled()) m_moteur.Set(-kTurretSpeed);
}

void Turret::Right() {
  if (!IsEnabled()) m_moteur.Set(kTurretSpeed);
}