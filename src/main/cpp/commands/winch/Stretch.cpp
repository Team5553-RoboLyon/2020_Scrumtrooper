/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Winch/Stretch.h"

#include <iostream>

Stretch::Stretch(Winch* Winch)
    : m_winch(Winch) {
  AddRequirements(m_winch);
}

void Stretch::Initialize() {}

void Stretch::Execute() {
  m_winch->Up();
}

void Stretch::End(bool interrStretchted) {}

bool Stretch::IsFinished() { return false; }
