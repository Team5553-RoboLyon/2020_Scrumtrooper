/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc2/command/CommandScheduler.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include "commands/driving/Drive.h"
#include "commands/driving/AutoDrive.h"
#include "commands/controlpanel/PositionControl.h"
#include "commands/controlpanel/RotationControl.h"
#include "commands/endgame/DropHook.h"
#include "commands/endgame/DropRobot.h"
#include "commands/endgame/LiftRobot.h"
#include "commands/endgame/RaiseHook.h"
#include "commands/scoring/AdjustHood.h"
#include "commands/scoring/PrepShoot.h"
#include "commands/scoring/Shoot.h"
#include "commands/scoring/Feed.h"
#include "commands/scoring/FeederUnblock.h"
#include "commands/intake/ChangeIntakePosition.h"
#include "commands/intake/TakeCell.h"
#include "commands/intake/EmergencyIntake.h"
#include "commands/scoring/AdjustTurret.h"
#include "commands/scoring/MoveHood.h"
#include "commands/scoring/MoveTurret.h"

#include "commands/auto/Auto.h"

RobotContainer::RobotContainer() {
  m_autoChooser.AddOption("Shoot + Reculer",
                          new Auto(&m_shooter, &m_turret, &m_adjustableHood, &m_feeder, &m_intake,
                                   &m_drivetrain)); /*frc2::SequentialCommandGroup(
frc2::ParallelCommandGroup(PrepShoot(&m_shooter),
AdjustTurret(&m_turret)) .WithTimeout(3_s),
frc2::ParallelCommandGroup(AdjustHood(&m_adjustableHood),
Shoot(&m_shooter), Feed(&m_feeder, &m_intake,
&m_shooter)) .WithTimeout(5_s),
AutoDrive(&m_drivetrain, 3000)));*/

  m_autoChooser.AddOption(
      "Shoot + TakeCells + Shoot",
      new frc2::SequentialCommandGroup(
          frc2::ParallelCommandGroup(PrepShoot(&m_shooter), AdjustTurret(&m_turret))
              .WithTimeout(3_s),
          frc2::ParallelCommandGroup(AdjustHood(&m_adjustableHood), Shoot(&m_shooter),
                                     Feed(&m_feeder, &m_intake, &m_shooter))
              .WithTimeout(5_s),
          ChangeIntakePosition(&m_intake, &m_drivetrain),
          frc2::ParallelRaceGroup(AutoDrive(&m_drivetrain, 17000),
                                  TakeCell(&m_intake).WithTimeout(5_s)),
          AutoDrive(&m_drivetrain, -10000),
          frc2::ParallelCommandGroup(PrepShoot(&m_shooter), AdjustTurret(&m_turret))
              .WithTimeout(3_s),
          frc2::ParallelCommandGroup(AdjustHood(&m_adjustableHood), Shoot(&m_shooter),
                                     Feed(&m_feeder, &m_intake, &m_shooter).WithTimeout(15_s))));

  frc::Shuffleboard::GetTab("Autonomous").Add(m_autoChooser);

  m_drivetrain.SetDefaultCommand(
      Drive([this] { return -m_driverController.GetY(frc::GenericHID::JoystickHand::kLeftHand); },
            [this] { return m_driverController.GetX(frc::GenericHID::JoystickHand::kRightHand); },
            &m_drivetrain));

  ConfigureControls();
}

frc2::Command* RobotContainer::GetAutonomousCommand() { return m_autoChooser.GetSelected(); }

void RobotContainer::ConfigureControls() {
  //########## Xbox Controller ##########
  // Intake buttons
  j_bumperRightButton.WhenPressed(ChangeIntakePosition(&m_intake, &m_drivetrain));
  j_axisRightTrigger.WhileActiveContinous(TakeCell(&m_intake));

  // Shoot buttons
  j_bumperLeftButton.ToggleWhenActive(
      frc2::ParallelCommandGroup(PrepShoot(&m_shooter), AdjustTurret(&m_turret)));
  j_axisLeftTrigger
      .WhileActiveContinous(frc2::ParallelCommandGroup(
          AdjustHood(&m_adjustableHood), Shoot(&m_shooter), Feed(&m_feeder, &m_intake, &m_shooter)))
      .WhenInactive(frc2::ParallelCommandGroup(
          MoveHood(&m_adjustableHood, 0),
          frc2::SequentialCommandGroup(frc2::WaitCommand(4_s), MoveTurret(&m_turret, 0))));

  // Winch Buttons
  j_yButton.WhileHeld(LiftRobot(&m_winch));
  j_xButton.WhileHeld(DropRobot(&m_winch));

  // TelescopicArm Buttons
  j_aButton.WhileHeld(DropHook(&m_telescopicArm, &m_intake, &m_drivetrain));
  j_bButton.WhenPressed(MoveTurret(&m_turret, 35))
      .WhileHeld(RaiseHook(&m_telescopicArm, &m_intake, &m_drivetrain));

  //########## Panel ##########
  p_redButton.WhileHeld(EmergencyIntake(&m_intake, &m_drivetrain), false);
  p_yellowButton.WhileHeld(FeederUnblock(&m_feeder));
}

void RobotContainer::ConfigureTestControls() {}
