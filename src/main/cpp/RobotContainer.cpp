/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc2/command/InstantCommand.h>

RobotContainer::RobotContainer() {
  ConfigureButtonBindings();
  m_drivetrain.SetDefaultCommand(
      Drive([this] { return -m_driverController.GetY(frc::GenericHID::JoystickHand::kLeftHand); },
            [this] { return -m_driverController.GetX(frc::GenericHID::JoystickHand::kRightHand); },
            &m_drivetrain));
}

void RobotContainer::ConfigureButtonBindings() {
    //Intake buttons
    j_bumperLeftButton.WhenPressed(ChangePosition(&m_intake));
    TriggerAxisLeftTrigger.WhenActive(Activate(&m_intake));

    //Shooter button
    j_xButton.WhileHeld(ShootGroup(&m_shooter, &m_feeder, &m_drivetrain, &m_intake, &m_controlPanelManipulator, &m_turret, &m_adjustableHood));
    
    //Ballshifter button
    (j_StickLeftButton && j_StickRightButton).WhileActiveOnce(Ballshifter(&m_drivetrain));

    //ControlPanelManipulator buttons
    j_bumperRightButton.WhenPressed(PositionControl(&m_controlPanelManipulator));
    TriggerAxisRightTrigger.WhenActive(RotationControl(&m_controlPanelManipulator));
    
}
