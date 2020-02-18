/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/winch/Unstretch.h"

#include <iostream>

Unstretch::Unstretch(Winch* Winch)
    : m_winch(Winch) {
  AddRequirements(m_winch);
}

void Unstretch::Initialize() {}

void Unstretch::Execute() {
  m_winch->Down();
}

void Unstretch::End(bool interrupted) {}

bool Unstretch::IsFinished() { return false; }
