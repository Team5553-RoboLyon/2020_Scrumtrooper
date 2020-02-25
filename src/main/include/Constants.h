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
constexpr int kFeederMoteur = 1;

// Turret
constexpr int kTurretMoteur = 3;

// ControlPanelManipulator
constexpr int kControlPanelManipulatorMoteur = -1;

// TelescopicArm
constexpr int kTelescopicArmMoteur = -1;

// ############### Encoders IDs ###############
// Drivetrain
constexpr int kDrivetrainRightEncodeurA = 0;
constexpr int kDrivetrainRightEncodeurB = 1;
constexpr int kDrivetrainLeftEncodeurA = 2;
constexpr int kDrivetrainLeftEncodeurB = 3;

// TelescopicArm
constexpr int kTelescopicArmEncodeurA = 4;
constexpr int kTelescopicArmEncodeurB = 5;

// AdjustableHood
constexpr int kAdjustableHoodEncodeurA = 8;
constexpr int kAdjustableHoodEncodeurB = 9;

// ############### PCM IDs ###############
// Intake
constexpr int kIntakeA = 2;
constexpr int kIntakeB = 1;

// ############### Motion Constants ###############
// Intake
constexpr double kIntakeMoteurSpeed = 0.6;

// Feeder
constexpr double kFeederMoteurSpeed = 0.60;
constexpr double kConveyorMoteurSpeed = 0.25;

// Turret
constexpr double kTurretMoteurSpeed = 0.2;

// ControlPanelManipulator
constexpr double kControlPanelManipulatorSpeed = 0.0;

// Winch
constexpr double kWinchPositionConversionFactor = 1.0;
constexpr double kWinchSpeed = 0.2;
constexpr double kWinchPGain = 0.1;
constexpr units::meters_per_second_t kWinchMaxVelocity = 2.0_mps;
constexpr units::meters_per_second_squared_t kWinchMaxAcceleration = 1.0_mps_sq;
constexpr units::meter_t kWinchLiftHeight = 1.0_m;

// TelescopicArm
constexpr double kTelescopicArmSpeed = 0.0;
