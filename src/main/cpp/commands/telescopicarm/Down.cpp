/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/telescopicarm/Down.h"

#include <iostream>

Down::Down(TelescopicArm* TelescopicArm)
    : m_telescopicarm(TelescopicArm) {
  AddRequirements(m_telescopicarm);
}

void Down::Initialize() {}

void Down::Execute() {
  m_telescopicarm->Down();
}

void Down::End(bool interrupted) {
  m_telescopicarm->Stop();
}

bool Down::IsFinished() { return true; }
