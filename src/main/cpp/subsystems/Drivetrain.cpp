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

  /*m_moteurDroite.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_moteurDroiteFollower.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_moteurGauche.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_moteurGaucheFollower.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);*/

  m_moteurDroite.SetOpenLoopRampRate(3);
  m_moteurGauche.SetOpenLoopRampRate(3);
  m_moteurDroiteFollower.SetOpenLoopRampRate(3);
  m_moteurGaucheFollower.SetOpenLoopRampRate(3);

  m_moteurDroite.SetClosedLoopRampRate(3);
  m_moteurGauche.SetClosedLoopRampRate(3);
  m_moteurDroiteFollower.SetClosedLoopRampRate(3);
  m_moteurGaucheFollower.SetClosedLoopRampRate(3);
}

void Drivetrain::Periodic() {}

void Drivetrain::SetVitesse(GearRatio gearRatio) {
  if (gearRatio == GearRatio::kLow) {
    m_ballshifter.Set(frc::DoubleSolenoid::Value::kForward);
  } else {
    m_ballshifter.Set(frc::DoubleSolenoid::Value::kReverse);
  }
  m_gearRatio = gearRatio;
  SetPositionConversionFactor(gearRatio);
}

void Drivetrain::ChangerVitesse() {
  if (m_gearRatio == GearRatio::kLow) {
    SetVitesse(GearRatio::kHigh);
  } else {
    SetVitesse(GearRatio::kLow);
  }
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