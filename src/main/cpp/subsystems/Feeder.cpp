/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Feeder.h"

Feeder::Feeder() {
  m_moteurConveyor.SetInverted(false);
  m_moteurFeeder.SetInverted(false);
  m_moteurConveyor.ConfigVoltageCompSaturation(10);
  m_moteurFeeder.ConfigVoltageCompSaturation(10);
  m_moteurConveyor.EnableVoltageCompensation(true);
  m_moteurFeeder.EnableVoltageCompensation(true);
  m_count = 0;
  m_activated = false;
}

void Feeder::Activate() {
  m_moteurFeeder.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, kFeederMoteurSpeed);
  m_activated = true;
}

void Feeder::UnBlock() {
  m_moteurFeeder.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -kFeederMoteurSpeed);
  m_moteurConveyor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
                       -kConveyorMoteurSpeed);
  m_activated = false;
}

void Feeder::Stop() {
  m_moteurFeeder.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0);
  m_moteurConveyor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0);
  m_activated = false;
}

void Feeder::Periodic() {
  if (m_activated) {
    m_moteurConveyor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
                         kConveyorMoteurSpeed);  //* (std::abs(std::sin(m_count)) + 1) / 2
    m_count += 0.02 * 3.14;
  }
}