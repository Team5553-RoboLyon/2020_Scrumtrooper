/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <units/units.h>
#include <wpi/math>
#include <frc/Encoder.h>
#include <frc/I2C.h>

#include "lib/CSVLogFile.h"
#include "commands/scoring/AdjustHood.h"
#include "subsystems/AdjustableHood.h"

#include "Constants.h"

#define DRIVETRAIN_ULTRASONICSIZE 5
#define DRIVETRAIN_ULTRASONIC_WARNING_THRESHOLD 60

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
  int GetEncodeurDroit();
  int GetEncodeurGauche();

 private:
  enum SpeedMode { quick, slow };
  rev::CANSparkMax m_moteurDroite{kDrivetrainMoteurDroite1,
                                  rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_moteurDroiteFollower{kDrivetrainMoteurDroite2,
                                          rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_moteurGauche{kDrivetrainMoteurGauche1,
                                  rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_moteurGaucheFollower{kDrivetrainMoteurGauche2,
                                          rev::CANSparkMax::MotorType::kBrushless};

  rev::CANEncoder m_encodeurDroite1{m_moteurDroite};
  rev::CANEncoder m_encodeurDroite2{m_moteurDroiteFollower};
  rev::CANEncoder m_encodeurGauche1{m_moteurGauche};
  rev::CANEncoder m_encodeurGauche2{m_moteurGaucheFollower};

  const rev::CANSparkMax::IdleMode kIdleMode = rev::CANSparkMax::IdleMode::kBrake;
  const rev::CANSparkMax::IdleMode kDisabledMode = rev::CANSparkMax::IdleMode::kCoast;

  const units::meter_t kWheelCircumference{wpi::math::pi * 6 * 0.0254};
  const double kGearRatio = 1 / 10.6;
  const double kOpenLoopRampeRate = 0.72;
  double m_integral = 0.0;
  double m_prev_error = 0.0;
  const double kPositionConversionFactor = 42;

  // const double kLowGearPositionConversionFactor = kWheelCircumference.to<double>() *
  // kLowGearRatio; const double kHighGearPositionConversionFactor =
  // kWheelCircumference.to<double>()
  // * kHighGearRatio;

  frc::Encoder m_encoderExterneDroite{kDrivetrainRightEncodeurA, kDrivetrainRightEncodeurB};
  frc::Encoder m_encoderExterneGauche{kDrivetrainLeftEncodeurA, kDrivetrainLeftEncodeurB};

  CSVLogFile* m_logFile;
  bool m_isLogFileEnabled;
  bool m_isUltraSonicSensorActivated = true;

  frc::I2C m_arduinoDroit{frc::I2C::Port::kOnboard, 3};
  frc::I2C m_arduinoGauche{frc::I2C::Port::kOnboard, 4};

  double m_receiveBufferDroitDouble[DRIVETRAIN_ULTRASONICSIZE];
  double m_receiveBufferGaucheDouble[DRIVETRAIN_ULTRASONICSIZE];
  int m_warningLevel = 0;
  Drivetrain::SpeedMode m_speedMode = Drivetrain::SpeedMode::quick;
};
