/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <units/units.h>

// ############### CAN IDs ###############
// Drivetrain
constexpr int kDrivetrainMoteurDroite1 = 1;
constexpr int kDrivetrainMoteurDroite2 = 4;
constexpr int kDrivetrainMoteurGauche1 = 2;
constexpr int kDrivetrainMoteurGauche2 = 3;

// Winch
constexpr int kWinchMoteur = 5;

// Shooter
constexpr int kShooterMoteurGauche = 10;
constexpr int kShooterMoteurDroite = 9;

// Intake
constexpr int kIntakeMoteur = 7;

// Conveyor
constexpr int kConveyorMoteur = 8;

// AdjustableHood IDs
constexpr int kAdjustableHoodMoteur = 6;

// ############### PWM IDs ###############
// Feeder
constexpr int kFeederMoteur = 3;

// Turret
constexpr int kTurretMoteur = 2;

// ControlPanelManipulator
constexpr int kControlPanelManipulatorMoteur = 4;

// TelescopicArm
constexpr int kTelescopicArmMoteur = 0;

// ############### Encoders IDs ###############
// Drivetrain
constexpr int kDrivetrainRightEncodeurA = 0;
constexpr int kDrivetrainRightEncodeurB = 1;
constexpr int kDrivetrainLeftEncodeurA = 2;
constexpr int kDrivetrainLeftEncodeurB = 3;

// Turret
constexpr int kTurretEncodeurA = 4;
constexpr int kTurretEncodeurB = 5;

// AdjustableHood
constexpr int kAdjustableHoodEncodeur = 7;

// TelescopicArm
constexpr int kTelescopicArmEncodeur = 8;

constexpr int kTurretRelay = 9;

// ############### PCM IDs ###############
// Intake
constexpr int kIntakeA = 0;
constexpr int kIntakeB = 1;

// ############### Motion Constants ###############
// AdjustableHood
constexpr double kAdjustableHoodPositionConversionFactor = 360 * 18 / 34;
constexpr double kAdjustableHoodPGain = 0.012;
constexpr double kAdjustableHoodIGain = 0.001;
constexpr double kAdjustableHoodDGain = 0.0001;
constexpr double kAdjustableHoodGravityGain = 0.05;

// Intake
constexpr double kIntakeMoteurSpeedOpened = 0.6;
constexpr double kIntakeMoteurSpeedClosed = -0.2;

// Feeder
constexpr double kFeederMoteurSpeed = 0.60;
constexpr double kConveyorMoteurSpeed = 0.25;

// Turret
constexpr double kTurretPositionConversionFactor = -360.0 * ((16.0 / 132.0) / 2048.0);
constexpr double kTurretSpeed = 0.2;
constexpr double kTurretMaxPosition = 45.0;
constexpr double kTurretMaxSpeed = 0.4;
constexpr double kTurretPGain = 0.022;
constexpr double kTurretIGain = 0;
constexpr double kTurretDGain = 0;

// ControlPanelManipulator
constexpr double kControlPanelManipulatorSpeed = 0.0;

// Winch
constexpr double kWinchPositionConversionFactor = 1.0 / 311.0;
constexpr double kWinchSpeed = 0.9;
constexpr double kWinchPGain = 40.0;
constexpr units::meters_per_second_t kWinchMaxVelocity = 2.0_mps;
constexpr units::meters_per_second_squared_t kWinchMaxAcceleration = 1.0_mps_sq;
constexpr units::meter_t kWinchLiftHeight = 1.0_m;

// TelescopicArm
constexpr double kTelescopicArmSpeedUp = 0.25;
constexpr double kTelescopicArmSpeedDown = 0.1;
constexpr double kTelescopicArmPGain = 0.022;
constexpr double kTelescopicArmIGain = 0;
constexpr double kTelescopicArmDGain = 0;
constexpr double kTelescopicArmGravityGain = 0;
