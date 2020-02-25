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

#include "lib/CSVLogFile.h"
#include "commands/scoring/AdjustHood.h"
#include "subsystems/AdjustableHood.h"

#include "Constants.h"

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  void Periodic();
  void EnableLogFile(bool enable);
  void Drive(double gauche, double droite);
  void Stop();

  void SetIdleMode(rev::CANSparkMax::IdleMode mode);
  void ResetEncodeurs();
  void AutomatedShoot();
  void DisableRamp();
  void EnableRamp();
  units::meter_t GetEncodeurDroit();
  units::meter_t GetEncodeurGauche();

  double encoderValue;
  double nbrTickAutomatedShoot = 30;

 private:
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
  const double kOpenLoopRampeRate = 0.72;

  const units::meter_t kWheelCircumference{wpi::math::pi * 6 * 0.0254};
  const double kGearRatio = 1 / 10.6;
  // const double kLowGearPositionConversionFactor = kWheelCircumference.to<double>() *
  // kLowGearRatio; const double kHighGearPositionConversionFactor =
  // kWheelCircumference.to<double>()
  // * kHighGearRatio;
  const double kPositionConversionFactor = 42;

  frc::Encoder m_encoderExterneDroite{kDrivetrainRightEncodeurA, kDrivetrainRightEncodeurB};
  frc::Encoder m_encoderExterneGauche{kDrivetrainLeftEncodeurA, kDrivetrainLeftEncodeurB};

  CSVLogFile* m_logFile;
  bool m_isLogFileEnabled;
  double actualSpeed;
  double m_integral = 0.0;
  double m_prev_error = 0.0;
};
