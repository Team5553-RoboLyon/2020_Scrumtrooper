/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Turret.h"

Turret::Turret()
    : frc2::PIDSubsystem(frc2::PIDController(kTurretPGain, kTurretIGain, kTurretDGain)) {
  m_encodeur.SetDistancePerPulse(kTurretPositionConversionFactor);
  m_encodeur.Reset();
  m_moteur.SetInverted(true);
  GetController().SetTolerance(1);
  StopLedRing();
  SetSetpoint(0);

  Disable();
}

void Turret::UseOutput(double output, double setpoint) {
  if (output < -kTurretMaxSpeed) output = -kTurretMaxSpeed;
  if (output > kTurretMaxSpeed) output = kTurretMaxSpeed;
  m_moteur.Set(output);
}

double Turret::GetMeasurement() { return m_encodeur.GetDistance(); }

void Turret::SetClampedSetpoint(double setpoint) {
  SetSetpoint(std::clamp(setpoint, -kTurretMaxPosition, kTurretMaxPosition));
}

void Turret::Stop() {
  if (!IsEnabled()) m_moteur.StopMotor();
}

void Turret::Left() {
  if (!IsEnabled()) m_moteur.Set(-kTurretSpeed);
}

void Turret::Right() {
  if (!IsEnabled()) m_moteur.Set(kTurretSpeed);
}

void Turret::StartLedRing() { m_ledRing.Set(true); }

void Turret::StopLedRing() { m_ledRing.Set(false); }