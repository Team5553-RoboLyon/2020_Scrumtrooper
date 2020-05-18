/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/DutyCycleEncoder.h>
#include <frc/VictorSP.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class TelescopicArm : public frc2::SubsystemBase {
 public:
  TelescopicArm();

  void ResetEncoder();
  double GetEncodeur();

  void GoUp();
  void GoDown();
  void Stop();
  void ResistGravity();

 private:
  frc::VictorSP m_Motor{TELESCOPIC_ARM_MOTOR};
  frc::DutyCycleEncoder m_Encoder{TELESCOPIC_ARM_ENCODER};
};
