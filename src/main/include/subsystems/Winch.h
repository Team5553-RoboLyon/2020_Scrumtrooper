/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

class Winch : public frc2::SubsystemBase {
 public:
  Winch();

  void GoUp();
  void GoDown();
  void Stop();

 private:
  rev::CANSparkMax m_Motor{WINCH_MOTOR, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANEncoder m_Encoder{m_Motor};
};
