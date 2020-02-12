/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/controlpanel/Control.h"

#include <iostream>

Control::Control(Controlpanel* Controlpanel)
    : m_controlpanel(Controlpanel) {
  AddRequirements(m_controlpanel);
}

void Control::Initialize() {}

void Control::Execute() {
}

void Control::End(bool interrupted) {}

bool Control::IsFinished() { return false; }
