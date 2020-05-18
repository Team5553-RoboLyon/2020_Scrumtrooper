/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Winch.h"

Winch::Winch() {
  m_Motor.SetOpenLoopRampRate(0.5);
  m_Motor.SetInverted(true);
  m_Encoder.SetPosition(0.0);
  m_Encoder.SetPositionConversionFactor(WINCH_POSITION_CONVERSION_FACTOR);
}

void Winch::GoUp() { m_Motor.Set(WINCH_SPEED); }

void Winch::GoDown() { m_Motor.Set(-WINCH_SPEED); }

void Winch::Stop() { m_Motor.StopMotor(); }
