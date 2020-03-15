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
  void Monter();
  void Descendre();
  void Unblock();
  void Stop();

 private:
  ctre::phoenix::motorcontrol::can::VictorSPX m_moteur{kAdjustableHoodMoteur};
  frc::DutyCycleEncoder m_encodeur{kAdjustableHoodEncodeur};
  int m_lockedCount = 0;
  double m_prevVelocityError;
};
