/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <frc/DutyCycleEncoder.h>
#include <frc2/command/PIDSubsystem.h>

#include "Constants.h"

class AdjustableHood : public frc2::PIDSubsystem {
 public:
  AdjustableHood();

  void UseOutput(double output, double setpoint) override;
  double GetMeasurement() override;
  void SetClampedSetpoint(double setpoint);

  void ResetEncoder();

  void Close();
  void GoUp();
  void GoDown();
  void Unblock();
  void Stop();

 private:
  ctre::phoenix::motorcontrol::can::VictorSPX m_Motor{ADJUSTABLE_HOOD_MOTOR};
  frc::DutyCycleEncoder m_Encoder{ADJUSTABLE_HOOD_ENCODER};
  int m_LockedCount = 0;
  double m_PrevVelocityError;
};
