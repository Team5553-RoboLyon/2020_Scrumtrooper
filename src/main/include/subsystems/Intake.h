/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/DoubleSolenoid.h>
#include <frc/VictorSP.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class Intake : public frc2::SubsystemBase {
 public:
  enum class IntakePosition { kOpened, kClosed };
  Intake();

  void Close();
  void Open();
  void ChangePosition();
  void Activate();
  void Stop();

 private:
  IntakePosition m_position;
  frc::DoubleSolenoid m_solenoid{kIntakeA, kIntakeB};
  frc::VictorSP m_moteur{kIntakeMoteur};
};
