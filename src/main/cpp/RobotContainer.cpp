/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc2/command/CommandScheduler.h>

#include "commands/driving/Drive.h"
#include "commands/intake/ChangeIntakePosition.h"
#include "commands/intake/TakeCell.h"
#include "commands/scoring/ShootGroup.h"

RobotContainer::RobotContainer() {
  m_drivetrain.SetDefaultCommand(
      Drive([this] { return -m_driverController.GetY(frc::GenericHID::JoystickHand::kLeftHand); },
            [this] { return -m_driverController.GetX(frc::GenericHID::JoystickHand::kRightHand); },
            &m_drivetrain));

  ConfigureControls();
}

void RobotContainer::ConfigureControls() {
  // Intake buttons
  j_bumperLeftButton.WhenPressed(ChangeIntakePosition(&m_intake));
  j_axisLeftTrigger.WhileActiveContinous(TakeCell(&m_intake));

  // Shooter button
  j_xButton.WhileHeld(ShootGroup(&m_shooter, &m_feeder, &m_drivetrain, &m_intake,
                                 &m_controlPanelManipulator, &m_turret, &m_adjustableHood));
}
