/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Winch.h"

Winch::Winch() {}

void Winch::Up() { m_moteur.Set(kWinchSpeed); }

void Winch::Down() { m_moteur.Set(-kWinchSpeed); }

void Winch::Stop() { m_moteur.StopMotor(); }