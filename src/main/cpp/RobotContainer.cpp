/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc2/command/CommandScheduler.h>

#include "commands/driving/Drive.h"
#include "commands/controlpanel/PositionControl.h"
#include "commands/controlpanel/RotationControl.h"
#include "commands/endgame/DropHook.h"
#include "commands/endgame/DropRobot.h"
#include "commands/endgame/LiftRobot.h"
#include "commands/endgame/RaiseHook.h"
#include "commands/scoring/AdjustHood.h"
#include "commands/scoring/MoveTurretLeft.h"
#include "commands/scoring/MoveTurretRight.h"
#include "commands/scoring/PrepShoot.h"
#include "commands/scoring/Shoot.h"
#include "commands/scoring/Feed.h"
#include "commands/intake/ChangeIntakePosition.h"
#include "commands/intake/TakeCell.h"
#include "commands/scoring/ShootGroup.h"

RobotContainer::RobotContainer() {
  m_drivetrain.SetDefaultCommand(
      Drive([this] { return -m_driverController.GetY(frc::GenericHID::JoystickHand::kLeftHand); },
            [this] { return m_driverController.GetX(frc::GenericHID::JoystickHand::kRightHand); },
            &m_drivetrain));

  ConfigureControls();
}

void RobotContainer::ConfigureControls() {
  // Intake buttons
  j_bumperLeftButton.WhenPressed(ChangeIntakePosition(&m_intake));
  j_axisLeftTrigger.WhileActiveContinous(TakeCell(&m_intake));

  // Shooter buttons
  j_axisRightTrigger.WhileActiveContinous(ShootGroup(&m_shooter, &m_feeder, &m_drivetrain,
                                                     &m_intake, &m_controlPanelManipulator,
                                                     &m_turret, &m_adjustableHood, 1));

  // AdjustableHood buttons
  j_POV0Deg.WhileActiveContinous(AdjustHood(&m_adjustableHood, 1));
  j_POV180Deg.WhileActiveContinous(AdjustHood(&m_adjustableHood, -1));

  // Turret Buttons
  j_POV90Deg.WhileActiveContinous(MoveTurretRight(&m_turret));
  j_POV270Deg.WhileActiveContinous(MoveTurretLeft(&m_turret));

  // Winch Buttons
  j_yButton.WhenPressed(LiftRobot(&m_winch));
  j_xButton.WhileHeld(DropRobot(&m_winch));
}
