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

    //Shooter IDs
    constexpr int kShooterMoteurDroite = 8;
    constexpr int kShooterMoteurGauche = 7;

    //Intake IDs
    constexpr int kIntakeMoteur = 0;

    //Conveyor IDs
    constexpr int kConveyorMoteur = 0;

    //AdjustableHood IDs
    constexpr int kAdjustableHoodMoteur = 0;

//PWM IDs
    //Feeder IDs
    constexpr int kFeederMoteur = 3;

    //Turret IDs
    constexpr int kTurretMoteur = 5;

    //ControlPanelManipulator IDs
    constexpr int kControlPanelManipulatorMoteur = 0;

    //TelescopicArm IDs
    constexpr int kTelescopicArmMoteur = 0;

    //Winch IDs
    constexpr int kWinchMoteur1 = 0;
    constexpr int kWinchMoteur2 = 1;

// PCM IDs
    //Ballshifter IDs
    constexpr int kDrivetrainBallshifterA = 2;
    constexpr int kDrivetrainBallshifterB = 3;

    //Intake IDs
    constexpr int kIntakeA = 0;
    constexpr int kIntakeB = 1;

    //ControlPanelManipulator IDs
    constexpr int kControlPanelManipulatorA = 4;
    constexpr int kControlPanelManipulatorB = 5;

//Speed Constants
    //Intake Speeds
    constexpr double kIntakeMoteurSpeed = 0.5;

    //Feeder Speeds
    constexpr double kFeederMoteurSpeed = 0.40;
    constexpr double kConveyorMoteurSpeed = 0.35;

    //Turret Speeds
    constexpr double kTurretMoteurSpeed = 0.2;

    //ControlPanelManipulator Speeds
    constexpr double kControlPanelManipulatorSpeed = 0.0;

    //Winch Speeds
    constexpr double kWinchSpeed = 0.0;

    //TelescopicArm Speeds
    constexpr double kTelescopicArmSpeed = 0.0;

//Encodeurs IDs
    //AdjustableHood IDs
    constexpr int kAdjustableHoodEncodeurA = 0;
    constexpr int kAdjustableHoodEncodeurB = 1;