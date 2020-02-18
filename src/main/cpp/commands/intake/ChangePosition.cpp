/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/intake/ChangePosition.h"

#include <iostream>
ChangePosition::ChangePosition(Intake* Intake)
    : m_intake(Intake) {
  AddRequirements(m_intake);
}

void ChangePosition::Initialize() {}

void ChangePosition::Execute() {
  m_intake->ChangePosition();
}

void ChangePosition::End(bool interrupted) {
  std::cout << "Intake fini" << std::endl;
}

bool ChangePosition::IsFinished() { return true; }