/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/intake/EmergencyIntake.h"

EmergencyIntake::EmergencyIntake(Intake* intake, Drivetrain* drivetrain)
    : m_intake(intake), m_drivetrain(drivetrain) {
  AddRequirements(m_intake);
}

void EmergencyIntake::Initialize() { m_intake->Close(); }
