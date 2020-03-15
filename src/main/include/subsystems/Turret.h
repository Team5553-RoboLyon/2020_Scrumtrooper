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

#include "Constants.h"

class Turret : public frc2::PIDSubsystem {
 public:
  Turret();

  void UseOutput(double output, double setpoint) override;
  double GetMeasurement() override;
  void SetClampedSetpoint(double setpoint);

  void Stop();
  void Left();
  void Right();

 private:
  frc::VictorSP m_moteur{kTurretMoteur};
  frc::Encoder m_encodeur{kTurretEncodeurA, kTurretEncodeurB};
};
