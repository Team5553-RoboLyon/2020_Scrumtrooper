/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/Shoot.h"

Shoot::Shoot(double puissance, Shooter* Shooter) : m_puissance(puissance), m_shooter(Shooter) {
  AddRequirements(m_shooter);
}

void Shoot::Initialize() {}

void Shoot::Execute() { m_shooter->Shoot(m_puissance); }

void Shoot::End(bool interrupted) { m_shooter->Shoot(0.0); }

bool Shoot::IsFinished() { return false; }
