/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc2/command/InstantCommand.h>

RobotContainer::RobotContainer() {
  ConfigureNormalMode();
  m_drivetrain.SetDefaultCommand(
      Drive([this] { return -m_driverController.GetY(frc::GenericHID::JoystickHand::kLeftHand); },
            [this] { return -m_driverController.GetX(frc::GenericHID::JoystickHand::kRightHand); },
            &m_drivetrain));


}

void RobotContainer::ChangeConfiguration() {
    if(manualMode) ConfigureNormalMode();
    if(!manualMode) ConfigureManualMode();
}

void RobotContainer::ConfigureNormalMode() {

    //Intake buttons
    j_bumperLeftButton.WhenPressed(ChangePosition(&m_intake));
    TriggerAxisLeftTrigger.WhileActiveContinous(Activate(&m_intake));
    
    
    (Activate(&m_intake));

    //Shooter button
    j_xButton.WhileHeld(ShootGroup(&m_shooter, &m_feeder, &m_drivetrain, &m_intake, &m_controlPanelManipulator, &m_turret, &m_adjustableHood));
    
    //Ballshifter button
    (j_StickLeftButton && j_StickRightButton).WhileActiveOnce(Ballshifter(&m_drivetrain));

    //ControlPanelManipulator buttons
    //j_bumperRightButton.WhenPressed(PositionControl(&m_controlPanelManipulator));
    //TriggerAxisRightTrigger.WhenActive(RotationControl(&m_controlPanelManipulator));

    j_StartButton.WhenPressed(&ChangeConfigurationCommand);
    manualMode = false;
}

void RobotContainer::ConfigureManualMode() {
    //Mode manuel !
    
    //Intake buttons
    j_bumperLeftButton.WhenPressed(ChangePosition(&m_intake));
    TriggerAxisLeftTrigger.WhileActiveOnce(Activate(&m_intake));

    //Feeder button
    j_bumperRightButton.WhileHeld(Feed(&m_feeder));

    //Shooter buttons
    TriggerAxisRightTrigger.WhileActiveContinous(PrepShoot(0.8, &m_shooter, &m_feeder, &m_drivetrain, &m_intake, &m_controlPanelManipulator, &m_turret, &m_adjustableHood));

    //AdjustableHood buttons
    POV0Deg.WhenActive(AdjustHood(&m_adjustableHood, m_adjustableHood.actualAngle + 5));
    POV180Deg.WhenActive(AdjustHood(&m_adjustableHood, m_adjustableHood.actualAngle - 5));

    //Turret Buttons
    POV90Deg.WhenActive(Right(&m_turret));
    POV270Deg.WhenActive(Left(&m_turret));

    //Telescopicarm Buttons
    j_bButton.WhileHeld(Up(&m_telescopicArm));
    j_aButton.WhileHeld(Down(&m_telescopicArm));

    //Winch Buttons
    j_yButton.WhileHeld(Stretch(&m_winch));
    j_xButton.WhileHeld(Unstretch(&m_winch));

    j_StartButton.WhenPressed(&ChangeConfigurationCommand);
    manualMode = true;
}
