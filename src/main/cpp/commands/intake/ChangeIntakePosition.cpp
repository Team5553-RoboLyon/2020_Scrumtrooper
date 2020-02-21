/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/intake/ChangeIntakePosition.h"

ChangeIntakePosition::ChangeIntakePosition(Intake* intake) : m_intake(intake) {
  AddRequirements(m_intake);
}

void ChangeIntakePosition::Initialize() { m_intake->ChangePosition(); }
