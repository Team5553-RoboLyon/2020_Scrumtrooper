/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/AdjustTurret.h"

#include <networktables/NetworkTableInstance.h>

AdjustTurret::AdjustTurret(Turret* pturret) : m_pTurret(pturret) { AddRequirements(m_pTurret); }

void AdjustTurret::Initialize() { m_pTurret->Enable(); }

void AdjustTurret::Execute() { m_pTurret->Adjust(); }

void AdjustTurret::End(bool interrupted) {}

bool AdjustTurret::IsFinished() { return false; }
