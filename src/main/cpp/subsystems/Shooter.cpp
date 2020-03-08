/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

Shooter::Shooter() {
  m_moteur2.Follow(m_moteur1);
  m_moteur2.SetInverted(true);
  m_moteur1.ConfigVoltageCompSaturation(12);
  m_moteur2.ConfigVoltageCompSaturation(12);
  m_moteur1.EnableVoltageCompensation(true);
  m_moteur2.EnableVoltageCompensation(true);
  m_timer.Reset();
  m_timer.Stop();
}

void Shooter::Shoot(double puissance) {
  m_moteur1.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, puissance);
}

void Shooter::SetRamp(double secondsFromNeutralToFull) {
  m_moteur1.ConfigOpenloopRamp(secondsFromNeutralToFull);
  m_moteur2.ConfigOpenloopRamp(secondsFromNeutralToFull);
}

double Shooter::GetTimer() { return m_timer.Get(); }

void Shooter::ResetTimer() {
  m_timer.Reset();
  m_timer.Start();
}

void Shooter::StopTimer() {
  m_timer.Reset();
  m_timer.Stop();
}

void Shooter::Periodic() {}