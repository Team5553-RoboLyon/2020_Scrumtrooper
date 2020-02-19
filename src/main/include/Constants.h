/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// CAN IDs
// Drivetrain IDs
constexpr int kDrivetrainMoteurDroite1 = 2;
constexpr int kDrivetrainMoteurDroite2 = 3;
constexpr int kDrivetrainMoteurGauche1 = 1;
constexpr int kDrivetrainMoteurGauche2 = 4;

// Shooter IDs
constexpr int kShooterMoteurGauche = 5;
constexpr int kShooterMoteurDroite = 6;

// Intake IDs
constexpr int kIntakeMoteur = 7;

// Conveyor IDs
constexpr int kConveyorMoteur = 8;

// AdjustableHood IDs
constexpr int kAdjustableHoodMoteur = 9;

// PWM IDs
// Feeder IDs
constexpr int kFeederMoteur = 5;

// Turret IDs
constexpr int kTurretMoteur = 2;

// ControlPanelManipulator IDs
constexpr int kControlPanelManipulatorMoteur = -1;

// TelescopicArm IDs
constexpr int kTelescopicArmMoteur = -1;

// Winch IDs
constexpr int kWinchMoteur1 = 0;
constexpr int kWinchMoteur2 = 1;

// PCM IDs
// Ballshifter IDs
constexpr int kDrivetrainBallshifterA = 2;
constexpr int kDrivetrainBallshifterB = 3;

// Intake IDs
constexpr int kIntakeA = 0;
constexpr int kIntakeB = 1;

// ControlPanelManipulator IDs
constexpr int kControlPanelManipulatorA = 4;
constexpr int kControlPanelManipulatorB = 5;

// Speed Constants
// Intake Speeds
constexpr double kIntakeMoteurSpeed = 0.6;

// Feeder Speeds
constexpr double kFeederMoteurSpeed = 0.50;
constexpr double kConveyorMoteurSpeed = 0.25;

// Turret Speeds
constexpr double kTurretMoteurSpeed = 0.2;

// ControlPanelManipulator Speeds
constexpr double kControlPanelManipulatorSpeed = 0.0;

// Winch Speeds
constexpr double kWinchSpeed = 0.0;

// TelescopicArm Speeds
constexpr double kTelescopicArmSpeed = 0.0;

// Encodeurs IDs
// Drivetrain IDs
constexpr int kDrivetrainRightEncodeurA = 0;
constexpr int kDrivetrainRightEncodeurB = 1;
constexpr int kDrivetrainLeftEncodeurA = 2;
constexpr int kDrivetrainLeftEncodeurB = 3;

// Climber IDs
constexpr int kClimberEncodeurA = 4;
constexpr int kClimberEncodeurB = 5;

// TelescopicArm IDs
constexpr int kTelescopicArmEncodeurA = 4;
constexpr int kTelescopicArmEncodeurB = 5;

// AdjustableHood IDs
constexpr int kAdjustableHoodEncodeurA = 8;
constexpr int kAdjustableHoodEncodeurB = 9;