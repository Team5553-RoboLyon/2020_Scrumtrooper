/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// CAN IDs
    //Drivetrain IDs
    constexpr int kDrivetrainMoteurDroite1 = 2;
    constexpr int kDrivetrainMoteurDroite2 = 4;
    constexpr int kDrivetrainMoteurGauche1 = 1;
    constexpr int kDrivetrainMoteurGauche2 = 3;

    //Shooteur IDs
    constexpr int kShooterMoteurDroite = 8;
    constexpr int kShooterMoteurGauche = 7;

//PWM IDs
    //Intake IDs
    constexpr int kIntakeMoteur = 0;

    //Feeder IDs
    constexpr int kFeederMoteur = 0;
    constexpr int kConveyorMoteur = 0;

    //Turret IDs
    constexpr int kTurretMoteur = 0;

    //ControlPanelManipulator IDs
    constexpr int kControlPanelManipulatorMoteur = 0;

    //AdjustableHood IDs
    constexpr int kAdjustableHoodMoteur = 0;

    //TelescopicArm IDs
    constexpr int kTelescopicArmMoteur = 0;

    //Winch IDs
    constexpr int kWinchMoteur = 0;

// PCM IDs
    //Ballshifter IDs
    constexpr int kDrivetrainBallshifterA = 0;
    constexpr int kDrivetrainBallshifterB = 1;

    //Intake IDs
    constexpr int kIntakeA = 2;
    constexpr int kIntakeB = 3;

    //ControlPanelManipulator IDs
    constexpr int kControlPanelManipulatorA = 4;
    constexpr int kControlPanelManipulatorB = 5;

//Speed Constants
    //Intake Speeds
    constexpr double kIntakeMoteurSpeed = 0.0;

    //Feeder Speeds
    constexpr double kFeederMoteurSpeed = 0.0;
    constexpr double kConveyorMoteurSpeed = 0.0;

    //Turret Speeds
    constexpr double kTurretMoteurSpeed = 0.0;

    //ControlPanelManipulator Speeds
    constexpr double kControlPanelManipulatorSpeed = 0.0;
