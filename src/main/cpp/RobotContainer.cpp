/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc2/command/CommandScheduler.h>

#include "commands/controlpanel/PositionControl.h"
#include "commands/controlpanel/RotationControl.h"
#include "commands/driving/Drive.h"
#include "commands/endgame/DropHook.h"
#include "commands/endgame/DropRobot.h"
#include "commands/endgame/LiftRobot.h"
#include "commands/endgame/RaiseHook.h"
#include "commands/intake/ChangeIntakePosition.h"
#include "commands/intake/TakeCell.h"
#include "commands/scoring/AdjustHood.h"
#include "commands/scoring/Feed.h"
#include "commands/scoring/MoveTurretLeft.h"
#include "commands/scoring/MoveTurretRight.h"
#include "commands/scoring/ShootGroup.h"

RobotContainer::RobotContainer() {
  ConfigureNormalMode();
  m_drivetrain.SetDefaultCommand(
      Drive([this] { return -m_driverController.GetY(frc::GenericHID::JoystickHand::kLeftHand); },
            [this] { return -m_driverController.GetX(frc::GenericHID::JoystickHand::kRightHand); },
            &m_drivetrain));
  j_startButton.WhenPressed(&ChangeConfigurationCommand);
}

void RobotContainer::ChangeConfiguration() {
  frc2::CommandScheduler::GetInstance().ClearButtons();
  j_startButton.WhenPressed(&ChangeConfigurationCommand);

  if (manualMode) ConfigureNormalMode();
  if (!manualMode) ConfigureManualMode();
}

void RobotContainer::ConfigureNormalMode() {
  // Intake buttons
  j_bumperLeftButton.WhenPressed(ChangeIntakePosition(&m_intake));
  j_axisLeftTrigger.WhileActiveContinous(TakeCell(&m_intake));

  // Shooter button
  j_xButton.WhileHeld(ShootGroup(&m_shooter, &m_feeder, &m_drivetrain, &m_intake,
                                 &m_controlPanelManipulator, &m_turret, &m_adjustableHood));

  // ControlPanelManipulator buttons
  // j_bumperRightButton.WhenPressed(PositionControl(&m_controlPanelManipulator));
  // TriggerAxisRightTrigger.WhenActive(RotationControl(&m_controlPanelManipulator));

  manualMode = false;
}

void RobotContainer::ConfigureManualMode() {
  // Mode manuel !

  // Intake buttons
  j_bumperLeftButton.WhenPressed(ChangeIntakePosition(&m_intake));
  j_axisLeftTrigger.WhileActiveContinous(TakeCell(&m_intake));

  // Feeder button
  j_bumperRightButton.WhileHeld(Feed(&m_feeder));

  // Shooter buttons
  j_axisRightTrigger.WhileActiveContinous(ShootGroup(&m_shooter, &m_feeder, &m_drivetrain,
                                                     &m_intake, &m_controlPanelManipulator,
                                                     &m_turret, &m_adjustableHood));

  // AdjustableHood buttons
  j_POV0Deg.WhenActive(AdjustHood(&m_adjustableHood, 1));
  j_POV180Deg.WhenActive(AdjustHood(&m_adjustableHood, -1));

  // Turret Buttons
  j_POV90Deg.WhenActive(MoveTurretRight(&m_turret));
  j_POV270Deg.WhenActive(MoveTurretLeft(&m_turret));

  // Telescopicarm Buttons
  j_bButton.WhileHeld(RaiseHook(&m_telescopicArm));
  j_aButton.WhileHeld(DropHook(&m_telescopicArm));

  // Winch Buttons
  j_yButton.WhileHeld(LiftRobot(&m_winch));
  j_xButton.WhileHeld(DropRobot(&m_winch));

  manualMode = true;
}
