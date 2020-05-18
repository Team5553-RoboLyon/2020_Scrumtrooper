/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Feeder.h"

Feeder::Feeder() {
  m_ConveyorMotor.SetInverted(false);
  m_FeederMotor.SetInverted(false);
  m_ConveyorMotor.ConfigVoltageCompSaturation(10);
  m_FeederMotor.ConfigVoltageCompSaturation(10);
  m_ConveyorMotor.EnableVoltageCompensation(true);
  m_FeederMotor.EnableVoltageCompensation(true);
}

void Feeder::Activate() {
  m_FeederMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, FEEDER_SPEED);
  m_ConveyorMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, CONVEYOR_SPEED);
}

void Feeder::UnBlock() {
  m_FeederMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -FEEDER_SPEED);
  m_ConveyorMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -CONVEYOR_SPEED);
}

void Feeder::Stop() {
  m_FeederMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0);
  m_ConveyorMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0);
}
