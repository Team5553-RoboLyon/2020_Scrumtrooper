/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/InstantCommand.h>

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
  bool manualMode;

 private:
  frc::XboxController m_driverController{0};
  frc2::JoystickButton j_aButton{&m_driverController, 1};
  frc2::JoystickButton j_bButton{&m_driverController, 2};
  frc2::JoystickButton j_xButton{&m_driverController, 3};
  frc2::JoystickButton j_yButton{&m_driverController, 4};
  frc2::JoystickButton j_bumperLeftButton{&m_driverController, 5};
  frc2::JoystickButton j_bumperRightButton{&m_driverController, 6};
  frc2::JoystickButton j_BackButton{&m_driverController, 7};
  frc2::JoystickButton j_StartButton{&m_driverController, 8};
  frc2::JoystickButton j_StickLeftButton{&m_driverController, 9};
  frc2::JoystickButton j_StickRightButton{&m_driverController, 10};

  frc2::Trigger TriggerAxisLeftTrigger{[this] {
    return m_driverController.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) > 0.2;
  }};
  frc2::Trigger TriggerAxisRightTrigger{[this] {
    return m_driverController.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) > 0.2;
  }};

  frc2::Trigger POV0Deg{[this] { return m_driverController.GetPOV() == 0; }};
  frc2::Trigger POV180Deg{[this] { return m_driverController.GetPOV() == 180; }};
  frc2::Trigger POV90Deg{[this] { return m_driverController.GetPOV() == 90; }};
  frc2::Trigger POV270Deg{[this] { return m_driverController.GetPOV() == 270; }};

  void ConfigureNormalMode();
  void ConfigureManualMode();
  void ChangeConfiguration();
  frc2::InstantCommand ChangeConfigurationCommand{[this] { return ChangeConfiguration(); }, {}};
};
