/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/shooter/Shoot.h"

#include <iostream>

Shoot::Shoot(double puissance, Shooter* Shooter, Feeder* Feeder)
    : m_puissance(puissance), 
      m_shooter(Shooter),
      m_feeder(Feeder) {
  AddRequirements(m_shooter);
  AddRequirements(m_feeder);
}

void Shoot::Initialize() {}

void Shoot::Execute() {
  m_shooter->Shoot(m_puissance);
  m_feeder->Activate();
}

void Shoot::End(bool interrupted) {
  m_shooter->Shoot(0.0);
  m_feeder->Stop();
}

bool Shoot::IsFinished() { return false; }
