/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/adjustablehood/AdjustHood.h"

#include <iostream>

AdjustHood::AdjustHood(AdjustableHood* AdjustableHood, double angle)
    : m_adjustablehood(AdjustableHood),
      m_angle(angle) {
  AddRequirements(m_adjustablehood);
}

void AdjustHood::Initialize() {}

void AdjustHood::Execute() {
  if(m_angle = 1) m_adjustablehood->Monter();
  if(m_angle = -1) m_adjustablehood->Descendre();
  //m_adjustablehood->SetAngle(m_angle);
  //m_adjustablehood->
}

void AdjustHood::End(bool interrupted) {}

bool AdjustHood::IsFinished() { return false; }
