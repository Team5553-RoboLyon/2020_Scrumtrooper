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

void TelescopicArm::Up() {
  if (!IsEnabled()) m_moteur.Set(kTelescopicArmSpeedUp);

  std::cout << "TelescopicArm::Up" ;
}

void TelescopicArm::Down() {
  if (!IsEnabled()) m_moteur.Set(-kTelescopicArmSpeedDown);
}

void TelescopicArm::Stop() {
  //if (!IsEnabled()) m_moteur.StopMotor();
    if (!IsEnabled()) m_moteur.Set(0.05);

}