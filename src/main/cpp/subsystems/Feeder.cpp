/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Feeder.h"

Feeder::Feeder() {
  m_moteurConveyor.SetInverted(true);
  m_moteurFeeder.SetInverted(false);
  m_count = 0;
}

void Feeder::Activate() { m_activated = true; }

void Feeder::UnBlock() {
  m_moteurFeeder.Set(-kFeederMoteurSpeed);
  m_moteurConveyor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
                       -kConveyorMoteurSpeed);
  m_activated = false;
}

void Feeder::Stop() {
  m_moteurFeeder.StopMotor();
  m_moteurConveyor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0);
  m_activated = false;
}

void Feeder::Periodic() {
  if (m_activated) {
    m_moteurFeeder.Set(kFeederMoteurSpeed);
    m_moteurConveyor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
                         kConveyorMoteurSpeed * std::abs(std::sin(m_count)));
    m_count += 0.02 * 3.14;
  }
}