/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/CommandScheduler.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/WaitCommand.h>

#include "commands/auto/ComplexAuto.h"
#include "commands/auto/SimpleAuto.h"
#include "commands/driving/AutoDrive.h"
#include "commands/driving/Drive.h"
#include "commands/endgame/DropHook.h"
#include "commands/endgame/DropRobot.h"
#include "commands/endgame/LiftRobot.h"
#include "commands/endgame/RaiseHook.h"
#include "commands/intake/ChangeIntakePosition.h"
#include "commands/intake/EmergencyIntake.h"
#include "commands/intake/TakeCell.h"
#include "commands/scoring/AdjustHood.h"
#include "commands/scoring/AdjustTurret.h"
#include "commands/scoring/Feed.h"
#include "commands/scoring/FeederUnblock.h"
#include "commands/scoring/MoveHood.h"
#include "commands/scoring/MoveTurret.h"
#include "commands/scoring/PrepShoot.h"
#include "commands/scoring/Shoot.h"

RobotContainer::RobotContainer() {
  m_AutoChooser.AddOption("Shoot + Reculer",
                          new SimpleAuto(&m_Shooter, &m_Turret, &m_AdjustableHood, &m_Feeder,
                                         &m_Intake, &m_Drivetrain));

  m_AutoChooser.AddOption("Shoot + TakeCells + Shoot",
                          new ComplexAuto(&m_Shooter, &m_Turret, &m_AdjustableHood, &m_Feeder,
                                          &m_Intake, &m_Drivetrain));

  frc::Shuffleboard::GetTab("Autonomous").Add(m_AutoChooser);

  m_Drivetrain.SetDefaultCommand(
      Drive([this] { return -m_DriverController.GetY(frc::GenericHID::JoystickHand::kLeftHand); },
            [this] { return m_DriverController.GetX(frc::GenericHID::JoystickHand::kRightHand); },
            &m_Drivetrain));

  ConfigureControls();
}

frc2::Command* RobotContainer::GetAutonomousCommand() { return m_AutoChooser.GetSelected(); }

void RobotContainer::ConfigureControls() {
  //########## Xbox Controller ##########
  // Intake buttons
  m_BumperRightButton.WhenPressed(ChangeIntakePosition(&m_Intake));
  m_AxisRightTrigger.WhileActiveContinous(TakeCell(&m_Intake));

  // Shoot buttons
  m_BumperLeftButton.ToggleWhenActive(
      frc2::ParallelCommandGroup(PrepShoot(&m_Shooter), AdjustTurret(&m_Turret)));
  m_AxisLeftTrigger
      .WhileActiveContinous(frc2::ParallelCommandGroup(
          AdjustHood(&m_AdjustableHood), Shoot(&m_Shooter), Feed(&m_Feeder, &m_Intake, &m_Shooter)))
      .WhenInactive(frc2::ParallelCommandGroup(
          MoveHood(&m_AdjustableHood, 0),
          frc2::SequentialCommandGroup(frc2::WaitCommand(4_s), MoveTurret(&m_Turret, 0))));

  // Winch Buttons
  m_YButton.WhileHeld(LiftRobot(&m_Winch));
  // m_xButton.WhileHeld(DropRobot(&m_winch));

  // TelescopicArm Buttons
  m_AButton.WhileHeld(DropHook(&m_TelescopicArm, &m_Intake, &m_Drivetrain));
  m_BButton.WhenPressed(MoveTurret(&m_Turret, 0))
      .WhileHeld(RaiseHook(&m_TelescopicArm, &m_Intake, &m_Drivetrain));

  //########## Panel ##########
  m_RedButton.WhileHeld(EmergencyIntake(&m_Intake), false);
  m_YellowButton.WhileHeld(FeederUnblock(&m_Feeder));
}

void RobotContainer::ConfigureTestControls() {}
