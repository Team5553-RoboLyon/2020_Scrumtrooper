/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/AdjustableHood.h"

AdjustableHood::AdjustableHood()
    : PIDSubsystem(
          frc2::PIDController(kAdjustableHoodPGain, kAdjustableHoodIGain, kAdjustableHoodDGain)) {
  m_encodeur.SetDistancePerRotation(kAdjustableHoodPositionConversionFactor);
  m_encodeur.Reset();
  Disable();
}

void AdjustableHood::UseOutput(double output, double setpoint) {
  if (GetController().GetSetpoint() < 1) {
    m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, output);
  } else {
    m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
                 kAdjustableHoodGravityGain + output);
  }
}

double AdjustableHood::GetMeasurement() { return m_encodeur.GetDistance(); }

void AdjustableHood::ResetEncoder() { m_encodeur.Reset(); }

void AdjustableHood::Monter() {
  if (!IsEnabled()) m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.25);
}

void AdjustableHood::Descendre() {
  if (!IsEnabled()) m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.25);
}

void AdjustableHood::Unblock() {
  if (!IsEnabled()) m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.5);
}

void AdjustableHood::Stop() {
  if (!IsEnabled()) m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0);
}
