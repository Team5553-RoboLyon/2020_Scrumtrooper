/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Encoder.h>
#include <frc/VictorSP.h>
#include <frc2/command/PIDSubsystem.h>

#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>

#include "Constants.h"

#define BUFFER_SIZE 3

class Turret : public frc2::PIDSubsystem {
 public:
  Turret();

  void UseOutput(double output, double setpoint) override;
  double GetMeasurement() override;
  void SetClampedSetpoint(double setpoint);

  void Stop();
  void TurnLeft();
  void TurnRight();

  void Adjust();

 private:
  frc::VictorSP m_Motor{TURRET_MOTOR};
  frc::Encoder m_Encoder{TURRET_ENCODER_A, TURRET_ENCODER_B};
  nt::NetworkTableEntry m_ChameleonYawEntry;
  nt::NetworkTableEntry m_ChameleonIsValidEntry;
  double m_BufferYaw[BUFFER_SIZE] = {0};
  double m_BufferYawSorted[BUFFER_SIZE] = {0};
  unsigned int m_BufferCount;
};
