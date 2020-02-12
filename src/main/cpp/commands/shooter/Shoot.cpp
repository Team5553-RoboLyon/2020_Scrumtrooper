/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/shooter/Shoot.h"

#include <iostream>

Shoot::Shoot(double puissance, Shooter* Shooter, Convoyer* Convoyer, Feeder* Feeder)
    : m_puissance(puissance), m_feeder(Feeder), m_convoyer(Convoyer), m_shooter(Shooter) {
  AddRequirements(m_shooter);
  AddRequirements(m_convoyer);
  AddRequirements(m_feeder);
}

void Shoot::Initialize() {}

void Shoot::Execute() {
  m_shooter->Shoot(m_puissance);
  m_convoyer->Activate();
  m_feeder->Activate();
}

void Shoot::End(bool interrupted) {}

bool Shoot::IsFinished() { return false; }
