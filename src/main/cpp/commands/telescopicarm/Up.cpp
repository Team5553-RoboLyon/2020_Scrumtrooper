/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/telescopicarm/Up.h"

#include <iostream>

Up::Up(TelescopicArm* TelescopicArm)
    : m_telescopicarm(TelescopicArm) {
  AddRequirements(m_telescopicarm);
}

void Up::Initialize() {}

void Up::Execute() {
  m_telescopicarm->Up();
}

void Up::End(bool interrupted) {}

bool Up::IsFinished() { return false; }
