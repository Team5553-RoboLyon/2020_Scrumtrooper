/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Encoder.h>
#include <frc/I2C.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include <wpi/math>

#include "Constants.h"
#include "lib/CSVLogFile.h"

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  void Periodic();
  void EnableLogFile(bool enable);
  double CalculateTurn(double forward, double turn);
  void Drive(double gauche, double droite);
  void Stop();

  void SetIdleMode(rev::CANSparkMax::IdleMode mode);
  void ResetEncodeurs();
  void DisableRamp();
  void EnableRamp();
  void ChangeSpeed();
  void SlowSpeed();
  void QuickSpeed();
  int GetRightEncoder();
  int GetLeftEncoder();

 private:
  enum SpeedMode { quick, slow };
  rev::CANSparkMax m_RightMotor{DRIVETRAIN_RIGHT_MOTOR_1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_RightMotorFollower{DRIVETRAIN_RIGHT_MOTOR_2,
                                        rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_LeftMotor{DRIVETRAIN_LEFT_MOTOR_1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_LeftMotorFollower{DRIVETRAIN_LEFT_MOTOR_2,
                                       rev::CANSparkMax::MotorType::kBrushless};

  rev::CANEncoder m_RightEncoder1{m_RightMotor};
  rev::CANEncoder m_RightEncoder2{m_RightMotorFollower};
  rev::CANEncoder m_LeftEncoder1{m_LeftMotor};
  rev::CANEncoder m_LeftEncoder2{m_LeftMotorFollower};

  double m_Integral = 0.0;
  double m_PrevError = 0.0;

  frc::Encoder m_RightExternalEncoder{DRIVETRAIN_RIGHT_ENCODER_A, DRIVETRAIN_RIGHT_ENCODER_B};
  frc::Encoder m_LeftExternalEncoder{DRIVETRAIN_LEFT_ENCODER_A, DRIVETRAIN_LEFT_ENCODER_B};

  CSVLogFile* m_LogFile;
  bool m_IsLogFileEnabled;
  bool m_IsUltraSonicSensorActivated = true;

  frc::I2C m_RightArduino{frc::I2C::Port::kOnboard, 3};
  frc::I2C m_LeftArduino{frc::I2C::Port::kOnboard, 4};

  double m_DoubleReceiveBufferRight[DRIVETRAIN_ULTRASONIC_SIZE];
  double m_DoubleReceiveBufferLeft[DRIVETRAIN_ULTRASONIC_SIZE];
  int m_WarningLevel = 0;
  Drivetrain::SpeedMode m_SpeedMode = Drivetrain::SpeedMode::quick;
};
