/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/DoubleSolenoid.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <units/units.h>
#include <wpi/math>
#include <frc/DutyCycleEncoder.h>

#include "lib/CSVLogFile.h"

#include "Constants.h"

class Drivetrain : public frc2::SubsystemBase {
 public:
  enum class GearRatio { kLow, kHigh };

  Drivetrain();

  void Periodic();
  void EnableLogFile(bool enable);
  void SetVitesse(GearRatio gearRatio);
  void ChangerVitesse();
  void Drive(double droite, double gauche);

  void ResetEncodeurs();
  void SetPositionConversionFactor(GearRatio gearRatio);
  units::meter_t GetEncodeurDroit();
  units::meter_t GetEncodeurGauche();

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

  frc::DoubleSolenoid m_ballshifter{kDrivetrainBallshifterA, kDrivetrainBallshifterB};

  GearRatio m_gearRatio;

  const rev::CANSparkMax::IdleMode kIdleMode = rev::CANSparkMax::IdleMode::kCoast;
  const double kOpenLoopRampeRate = 2.0;

  const units::meter_t kWheelCircumference{wpi::math::pi * 6 * 0.0254};
  const double kLowGearRatio = 1;
  const double kHighGearRatio = 1 / 10.6;
  //const double kLowGearPositionConversionFactor = kWheelCircumference.to<double>() * kLowGearRatio;
  //const double kHighGearPositionConversionFactor = kWheelCircumference.to<double>() * kHighGearRatio;
  const double kLowGearPositionConversionFactor = 42;
  const double kHighGearPositionConversionFactor = 42;

  CSVLogFile* m_logFile;
  bool m_isLogFileEnabled;
  frc::DutyCycleEncoder m_encodeurExterne {0};
};
