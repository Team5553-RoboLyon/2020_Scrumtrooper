/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/TelescopicArm.h"

TelescopicArm::TelescopicArm() {}

void TelescopicArm::ResetEncoder() { m_Encoder.Reset(); }

double TelescopicArm::GetEncodeur() { return m_Encoder.Get().to<double>(); }

void TelescopicArm::GoUp() {
  if (m_Encoder.Get().to<double>() < 113.0) {
    m_Motor.Set(TELESCOPIC_ARM_UP_SPEED);
  } else {
    ResistGravity();
  }
}

void TelescopicArm::GoDown() {
  if (m_Encoder.Get().to<double>() > 0) {
    m_Motor.Set(-TELESCOPIC_ARM_DOWN_SPEED);
  } else {
    Stop();
  }
}

void TelescopicArm::Stop() { m_Motor.StopMotor(); }

void TelescopicArm::ResistGravity() { m_Motor.Set(0.05); }
