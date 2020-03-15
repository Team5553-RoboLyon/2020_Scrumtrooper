/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/DriverStation.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/POVButton.h>

#include "subsystems/AdjustableHood.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Feeder.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/TelescopicArm.h"
#include "subsystems/Turret.h"
#include "subsystems/Winch.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

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
  frc2::JoystickButton j_aButton{&m_driverController, 1};
  frc2::JoystickButton j_bButton{&m_driverController, 2};
  frc2::JoystickButton j_xButton{&m_driverController, 3};
  frc2::JoystickButton j_yButton{&m_driverController, 4};
  frc2::JoystickButton j_bumperLeftButton{&m_driverController, 5};
  frc2::JoystickButton j_bumperRightButton{&m_driverController, 6};
  frc2::JoystickButton j_backButton{&m_driverController, 7};
  frc2::JoystickButton j_startButton{&m_driverController, 8};
  frc2::JoystickButton j_stickLeftButton{&m_driverController, 9};
  frc2::JoystickButton j_stickRightButton{&m_driverController, 10};

  frc::Joystick m_driverPanel{1};
  frc2::JoystickButton p_yellowButton{&m_driverPanel, 2};
  frc2::JoystickButton p_redButton{&m_driverPanel, 1};
  frc2::JoystickButton p_whiteButton{&m_driverPanel, 3};

  frc2::Trigger j_axisLeftTrigger{[this] {
    return m_driverController.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) > 0.2;
  }};
  frc2::Trigger j_axisRightTrigger{[this] {
    return m_driverController.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) > 0.2;
  }};

  frc2::POVButton j_POV0Deg{&m_driverController, 0};
  frc2::POVButton j_POV90Deg{&m_driverController, 90};
  frc2::POVButton j_POV180Deg{&m_driverController, 180};
  frc2::POVButton j_POV270Deg{&m_driverController, 270};

  frc2::Trigger m_endgameTrigger{
      [this] { return frc::DriverStation::GetInstance().GetMatchTime() < 40; }};

  frc::SendableChooser<frc2::Command*> m_autoChooser;

  void ConfigureControls();
  void ConfigureTestControls();
};
