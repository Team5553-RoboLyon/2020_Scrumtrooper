/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/TelescopicArm.h"

TelescopicArm::TelescopicArm() {}

void TelescopicArm::ResetEncoder() { m_encodeur.Reset(); }

double TelescopicArm::GetEncodeur() { return m_encodeur.Get().to<double>(); }

void TelescopicArm::Up() {
  if (m_encodeur.Get().to<double>() < 113.0) {
    m_moteur.Set(kTelescopicArmSpeedUp);
  } else {
    ResistGravity();
  }
}

void TelescopicArm::Down() {
  if (m_encodeur.Get().to<double>() > 0) {
    m_moteur.Set(-kTelescopicArmSpeedDown);
  } else {
    Stop();
  }
}

void TelescopicArm::Stop() { m_moteur.StopMotor(); }

void TelescopicArm::ResistGravity() { m_moteur.Set(0.05); }
