/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Drive.h"

#include <iostream>

double Deadband(double value, double deadband = 0.1) {
  if (std::abs(value) < deadband) {
    return 0;
  }

  if (value >= 0) {
    return (value - deadband) / (1.0 - deadband);
  } else {
    return (value + deadband) / (1.0 - deadband);
  }
}

Drive::Drive(std::function<double()> forward, std::function<double()> turn, Drivetrain* drivetrain)
    : m_forward(forward), m_turn(turn), m_drivetrain(drivetrain) {
  AddRequirements(m_drivetrain);
}

void Drive::Initialize() {}

void Drive::Execute() {
  double forward = Deadband(m_forward()* 0.4);
  double turn = Deadband(m_turn() *0.4);
  
  m_drivetrain->Drive(forward + 0.5 * turn, forward - 0.5 * turn);
}

void Drive::End(bool interrupted) {}

bool Drive::IsFinished() { return false; }
