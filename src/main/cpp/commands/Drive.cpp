/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Drive.h"

#include "lib/Utils.h"
#include <iostream>

Drive::Drive(std::function<double()> forward, std::function<double()> turn, Drivetrain* drivetrain)
    : m_forward(forward), m_turn(turn), m_drivetrain(drivetrain) {
  AddRequirements(m_drivetrain);
}

void Drive::Initialize() {}

void Drive::Execute() {
  double forward = utils::Deadband(m_forward());
  double turn = utils::Deadband(m_turn());
  m_drivetrain->Drive(forward + 0.5 * turn, forward - 0.5 * turn);
}

void Drive::End(bool interrupted) {}

bool Drive::IsFinished() { return false; }
