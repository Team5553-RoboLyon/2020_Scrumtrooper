/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/InstantCommand.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Intake.h"
#include "subsystems/Drivetrain.h"

class EmergencyIntake : public frc2::CommandHelper<frc2::InstantCommand, EmergencyIntake> {
 public:
  EmergencyIntake(Intake* intake, Drivetrain* drivetrain);

  void Initialize() override;

 private:
  Intake* m_intake;
  Drivetrain* m_drivetrain;
};
