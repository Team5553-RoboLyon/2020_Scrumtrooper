/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/PrepShoot.h"

#include "Constants.h"

PrepShoot::PrepShoot(Shooter* pshooter) : m_pShooter(pshooter) { AddRequirements(m_pShooter); }

void PrepShoot::Initialize() {
  m_pShooter->SetRamp(SHOOTER_PREP_SHOOT_RAMP);
  m_pShooter->ResetTimer();
}

void PrepShoot::Execute() { m_pShooter->Shoot(SHOOTER_PREP_SHOOT_SPEED); }

void PrepShoot::End(bool interrupted) { m_pShooter->Shoot(0.0); }

bool PrepShoot::IsFinished() { return false; }
