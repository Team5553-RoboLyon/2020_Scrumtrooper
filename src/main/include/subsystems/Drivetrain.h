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
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"

class Drivetrain : public frc2::SubsystemBase {
 public:
  enum class GearRatio { kLow, kHigh };

  Drivetrain();

  void Periodic();
  void SetVitesse(GearRatio gearRatio);
  void ChangerVitesse();
  void Drive(double droite, double gauche);

  void ResetEncodeurs();
  void SetPositionConversionFactor(GearRatio gearRatio);
  units::meter_t GetEncodeurDroit();
  units::meter_t GetEncodeurGauche();

  double Rampe(double precValue, double value);

  void ToggleRampe();

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

  const units::meter_t kWheelCircumference{wpi::math::pi * 0.1};
  const double kLowGearRatio = 1;
  const double kHighGearRatio = 1;
  const double kLowGearPositionConversionFactor =
      kWheelCircumference.to<double>() * kLowGearRatio / 42;
  const double kHighGearPositionConversionFactor =
      kWheelCircumference.to<double>() * kHighGearRatio / 42;

  GearRatio m_gearRatio;

  double m_precGauche, m_precDroite = 0.0;
  bool m_rampe = true;
};
