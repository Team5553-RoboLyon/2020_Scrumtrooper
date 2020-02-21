/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/TelescopicArm.h"

TelescopicArm::TelescopicArm() {}

void TelescopicArm::Up() { m_moteur.Set(kTelescopicArmSpeed); }

void TelescopicArm::Down() { m_moteur.Set(-kTelescopicArmSpeed); }

void TelescopicArm::Stop() { m_moteur.StopMotor(); }