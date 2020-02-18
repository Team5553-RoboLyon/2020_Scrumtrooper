/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/intake/Activate.h"

#include <iostream>
Activate::Activate(Intake* Intake)
    : m_intake(Intake) {
  AddRequirements(m_intake);
}

void Activate::Initialize() {}

void Activate::Execute() {
  m_intake->Activate();
}

void Activate::End(bool interrupted) {
    m_intake->Stop();
}

bool Activate::IsFinished() { return false; }