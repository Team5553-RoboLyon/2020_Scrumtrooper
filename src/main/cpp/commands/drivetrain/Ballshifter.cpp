/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/drivetrain/Ballshifter.h"

#include <iostream>

Ballshifter::Ballshifter(Drivetrain* drivetrain) : m_drivetrain(drivetrain) {
  AddRequirements(m_drivetrain);
}

void Ballshifter::Initialize() { m_drivetrain->ChangerVitesse(); }
