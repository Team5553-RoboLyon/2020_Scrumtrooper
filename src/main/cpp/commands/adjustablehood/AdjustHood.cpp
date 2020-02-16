/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/adjustablehood/AdjustHood.h"

#include <iostream>

AdjustHood::AdjustHood(AdjustableHood* AdjustableHood)
    : m_adjustablehood(AdjustableHood) {
  AddRequirements(m_adjustablehood);
}

void AdjustHood::Initialize() {}

void AdjustHood::Execute() {
  m_adjustablehood->SetAngle(415.0);
}

void AdjustHood::End(bool interrupted) {}

bool AdjustHood::IsFinished() { return false; }
