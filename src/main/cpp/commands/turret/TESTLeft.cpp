/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/turret/TESTLeft.h"

#include <iostream>

Left::Left(Turret* Turret)
    : m_turret(Turret) {
  AddRequirements(m_turret);
}

void Left::Initialize() {}

void Left::Execute() {
  m_turret->Left();
}

void Left::End(bool interrLeftted) {
  m_turret->Stop();
}

bool Left::IsFinished() { return true; }
