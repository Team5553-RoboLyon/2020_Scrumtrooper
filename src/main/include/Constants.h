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
constexpr int DRIVETRAIN_RIGHT_MOTOR_1 = 1;
constexpr int DRIVETRAIN_RIGHT_MOTOR_2 = 4;
constexpr int DRIVETRAIN_LEFT_MOTOR_1 = 2;
constexpr int DRIVETRAIN_LEFT_MOTOR_2 = 3;

// Winch
constexpr int WINCH_MOTOR = 5;

// Shooter
constexpr int SHOOTER_LEFT_MOTOR = 10;
constexpr int SHOOTER_RIGHT_MOTOR = 9;

// Feeder
constexpr int FEEDER_MOTOR = 7;

// Conveyor
constexpr int CONVEYOR_MOTOR = 8;

// AdjustableHood IDs
constexpr int ADJUSTABLE_HOOD_MOTOR = 6;

// ############### PWM IDs ###############
// Intake
constexpr int INTAKE_MOTOR = 2;

// Turret
constexpr int TURRET_MOTOR = 3;

// ControlPanelManipulator
constexpr int CONTROL_PANEL_MANIPULATOR_MOTOR = 4;

// TelescopicArm
constexpr int TELESCOPIC_ARM_MOTOR = 0;

// ############### Encoders IDs ###############
// Drivetrain
constexpr int DRIVETRAIN_RIGHT_ENCODER_A = 0;
constexpr int DRIVETRAIN_RIGHT_ENCODER_B = 1;
constexpr int DRIVETRAIN_LEFT_ENCODER_A = 2;
constexpr int DRIVETRAIN_LEFT_ENCODER_B = 3;

// Turret
constexpr int TURRET_ENCODER_A = 4;
constexpr int TURRET_ENCODER_B = 5;

// AdjustableHood
constexpr int ADJUSTABLE_HOOD_ENCODER = 7;

// TelescopicArm
constexpr int TELESCOPIC_ARM_ENCODER = 8;

constexpr int TURRET_RELAY = 9;

// ############### PCM IDs ###############
// Intake
constexpr int INTAKE_SOLENOID_A = 4;
constexpr int INTAKE_SOLENOID_B = 5;

// ############### Motion Constants ###############
// Drivetrain
constexpr int DRIVETRAIN_ULTRASONIC_SIZE = 5;
constexpr int DRIVETRAIN_ULTRASONIC_WARNING_THRESHOLD = 60;
constexpr double DRIVETRAIN_OPEN_LOOP_RAMP_RATE = 0.72;
constexpr double DRIVETRAIN_POSITION_CONVERSION_FACTOR = 42;

// AdjustableHood
constexpr double ADJUSTABLE_HOOD_POSITION_CONVERSION_FACTOR = 360 * 18 / 34;
constexpr double ADJUSTABLE_HOOD_P_GAIN = 0.013;
constexpr double ADJUSTABLE_HOOD_I_GAIN = 0.00075;  // 0.00175;//0.002;//0.0015;//0.001;
constexpr double ADJUSTABLE_HOOD_D_GAIN = 0.00025;
constexpr double ADJUSTABLE_HOOD_GRAVITY_GAIN = 0.05;

// Intake
constexpr double INTAKE_OPENED_SPEED = 0.6;
constexpr double INTAKE_CLOSED_SPEED = 0.2;

// Feeder
constexpr double FEEDER_SPEED = 0.7;
constexpr double CONVEYOR_SPEED = 0.4;

// Turret
constexpr double TURRET_POSITION_CONVERSION_FACTOR = -360.0 * ((16.0 / 132.0) / 2048.0);
constexpr double TURRET_SPEED = 0.2;
constexpr double TURRET_MAX_POSITION = 45.0;
constexpr double TURRET_MAX_SPEED = 0.4;
constexpr double TURRET_P_GAIN = 0.0503;
constexpr double TURRET_I_GAIN = 0.004;
constexpr double TURRET_D_GAIN = 0.002;

// Shooter
constexpr double SHOOTER_PREP_SHOOT_SPEED = 0.8;
constexpr double SHOOTER_PREP_SHOOT_RAMP = 0.7;

// ControlPanelManipulator
constexpr double CONTROL_PANEL_MANIPULATOR_SPEED = 0.0;

// Winch
constexpr double WINCH_POSITION_CONVERSION_FACTOR = 1.0 / 311.0;
constexpr double WINCH_SPEED = 0.9;

// TelescopicArm
constexpr double TELESCOPIC_ARM_UP_SPEED = 0.55;
constexpr double TELESCOPIC_ARM_DOWN_SPEED = 0.35;
