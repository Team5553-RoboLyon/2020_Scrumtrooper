/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/TelescopicArm.h"

TelescopicArm::TelescopicArm()
    : PIDSubsystem(
          frc2::PIDController(kTelescopicArmPGain, kTelescopicArmIGain, kTelescopicArmDGain)) {}

void TelescopicArm::UseOutput(double output, double setpoint) {
  m_moteur.Set(kTelescopicArmGravityGain + output);
}

double TelescopicArm::GetMeasurement() { return m_encodeur.GetDistance(); }

void TelescopicArm::ResetEncoder() { m_encodeur.Reset(); }

double TelescopicArm::GetEncodeur() { m_encodeur.Get().to<double>(); }

void TelescopicArm::Up() {
  if (!IsEnabled()) {
    if (m_encodeur.Get().to<double>() < 113.0) {
      m_moteur.Set(kTelescopicArmSpeedUp);
    } else {
      ResistGravity();
    }
  }
}

void TelescopicArm::Down() {
  if (!IsEnabled()) {
    if (m_encodeur.Get().to<double>() > 0) {
      m_moteur.Set(-kTelescopicArmSpeedDown);
    } else {
      Stop();
    }
  }
}

void TelescopicArm::Stop() {
  if (!IsEnabled()) m_moteur.StopMotor();
}

void TelescopicArm::ResistGravity() {
  if (!IsEnabled()) m_moteur.Set(0.05);
}