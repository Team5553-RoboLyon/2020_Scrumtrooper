/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/turret/TESTRight.h"

#include <iostream>

Right::Right(Turret* Turret)
    : m_turret(Turret) {
  AddRequirements(m_turret);
}

void Right::Initialize() {}

void Right::Execute() {
  m_turret->Right();
}

void Right::End(bool interrRightted) {
  m_turret->Stop();
}

bool Right::IsFinished() { return true; }
