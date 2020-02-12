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

    //Turret IDs
    constexpr int kTurretMoteur = 0;

    //Controlpanel IDs
    constexpr int kControlpanelMoteur = 0;

    //Hood IDs
    constexpr int kHoodMoteur = 0;

// PCM IDs
    //Ballshifter IDs
    constexpr int kDrivetrainBallshifterA = 0;
    constexpr int kDrivetrainBallshifterB = 1;

    //Intake IDs
    constexpr int kIntakeA = 2;
    constexpr int kIntakeB = 3;

    //Controlpanel IDs
    constexpr int kControlpanelA = 4;
    constexpr int kControlpanelB = 5;

//Speed Constants
    //Intake Speeds
    constexpr double kIntakeMoteurSpeed = 0.0;

    //Feeder Speeds
    constexpr double kFeederMoteurSpeed = 0.0;

    //Turret Speeds
    constexpr double kTurretMoteurSpeed = 0.0;

    //Controlpanel Speeds
    constexpr double kControlpanelSpeed = 0.0;