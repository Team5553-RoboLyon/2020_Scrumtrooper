/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/XboxController.h>

#include "subsystems/ControlPanelManipulator.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Feeder.h"
#include "subsystems/AdjustableHood.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/TelescopicArm.h"
#include "subsystems/Turret.h"
#include "subsystems/Winch.h"

class RobotContainer {
 public:
  RobotContainer();

  ControlPanelManipulator m_controlPanelManipulator;
  Drivetrain m_drivetrain;
  Feeder m_feeder;
  AdjustableHood m_adjustableHood;
  Intake m_intake;
  Shooter m_shooter;
  TelescopicArm m_telescopicArm;
  Turret m_turret;
  Winch m_winch;

 private:
  frc::XboxController m_driverController{0};

  void ConfigureButtonBindings();
};
