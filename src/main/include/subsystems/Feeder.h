/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class Feeder : public frc2::SubsystemBase {
 public:
  Feeder();

  void Activate();
  void UnBlock();
  void Stop();

 private:
  ctre::phoenix::motorcontrol::can::VictorSPX m_FeederMotor{FEEDER_MOTOR};
  ctre::phoenix::motorcontrol::can::VictorSPX m_ConveyorMotor{CONVEYOR_MOTOR};
};
