/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/intake/ChangeIntakePosition.h"

ChangeIntakePosition::ChangeIntakePosition(Intake* intake, Drivetrain* drivetrain) : m_intake(intake), m_drivetrain(drivetrain) {
  AddRequirements(m_intake);
}

void ChangeIntakePosition::Initialize() { 
  m_intake->ChangePosition();
  m_drivetrain->ChangeSpeed(); 
  }
