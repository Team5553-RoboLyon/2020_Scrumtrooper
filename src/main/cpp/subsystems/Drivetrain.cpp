/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain() {
  m_moteurDroiteFollower.Follow(m_moteurDroite);
  m_moteurGaucheFollower.Follow(m_moteurGauche);

  m_moteurDroite.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_moteurDroiteFollower.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_moteurGauche.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_moteurGaucheFollower.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

  m_moteurGauche.SetInverted(true);
}

void Drivetrain::Periodic() {}

void Drivetrain::ChangerVitesse(GearRatio gearRatio) {
  if (gearRatio == GearRatio::kLow) {
    m_ballshifter.Set(frc::DoubleSolenoid::Value::kForward);
  } else {
    m_ballshifter.Set(frc::DoubleSolenoid::Value::kReverse);
  }
  SetPositionConversionFactor(gearRatio);
}

void Drivetrain::Drive(double droite, double gauche) {
  m_moteurDroite.Set(droite);
  m_moteurGauche.Set(gauche);
}

void Drivetrain::ResetEncodeurs() {
  m_encodeurDroite1.SetPosition(0.0);
  m_encodeurDroite2.SetPosition(0.0);
  m_encodeurGauche1.SetPosition(0.0);
  m_encodeurGauche2.SetPosition(0.0);
}

void Drivetrain::SetPositionConversionFactor(GearRatio gearRatio) {
  if (gearRatio == GearRatio::kLow) {
    m_encodeurDroite1.SetPositionConversionFactor(kLowGearPositionConversionFactor);
    m_encodeurDroite2.SetPositionConversionFactor(kLowGearPositionConversionFactor);
    m_encodeurGauche1.SetPositionConversionFactor(kLowGearPositionConversionFactor);
    m_encodeurGauche2.SetPositionConversionFactor(kLowGearPositionConversionFactor);
  } else {
    m_encodeurDroite1.SetPositionConversionFactor(kHighGearPositionConversionFactor);
    m_encodeurDroite2.SetPositionConversionFactor(kHighGearPositionConversionFactor);
    m_encodeurGauche1.SetPositionConversionFactor(kHighGearPositionConversionFactor);
    m_encodeurGauche2.SetPositionConversionFactor(kHighGearPositionConversionFactor);
  }
}

units::meter_t Drivetrain::GetEncodeurDroit() {
  return units::meter_t((m_encodeurDroite1.GetPosition() + m_encodeurDroite2.GetPosition()) / 2.0);
}

units::meter_t Drivetrain::GetEncodeurGauche() {
  return units::meter_t((m_encodeurGauche1.GetPosition() + m_encodeurGauche2.GetPosition()) / 2.0);
}