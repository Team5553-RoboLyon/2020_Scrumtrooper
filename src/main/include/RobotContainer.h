/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/XboxController.h>

#include "subsystems/Drivetrain.h"
#include "commands/Drive.h"

class RobotContainer {
 public:
  RobotContainer();

 private:
  frc::XboxController m_driverController{0};

  Drivetrain m_drivetrain;

  void ConfigureButtonBindings();
};
