/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

Shooter::Shooter() {
  m_moteur2.Follow(m_moteur1);
  m_moteur1.SetInverted(true);
  m_moteur2.SetInverted(true);
}

void Shooter::Shoot(double puissance) {
  m_moteur1.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, puissance);
}

void Shooter::Periodic() {}