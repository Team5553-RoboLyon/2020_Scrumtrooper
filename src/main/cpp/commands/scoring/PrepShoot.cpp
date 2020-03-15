/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/PrepShoot.h"

#include "Constants.h"

PrepShoot::PrepShoot(Shooter* Shooter) : m_shooter(Shooter) { AddRequirements(m_shooter); }

void PrepShoot::Initialize() {
  m_shooter->SetRamp(kShooterPrepShootRamp);
  m_shooter->ResetTimer();
}

void PrepShoot::Execute() { m_shooter->Shoot(kShooterPrepShootSpeed); }

void PrepShoot::End(bool interrupted) { m_shooter->Shoot(0.0); }

bool PrepShoot::IsFinished() { return false; }
