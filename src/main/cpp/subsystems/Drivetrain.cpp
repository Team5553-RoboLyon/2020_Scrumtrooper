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

  m_moteurDroite.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_moteurDroiteFollower.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_moteurGauche.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_moteurGaucheFollower.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

  m_moteurDroite.SetOpenLoopRampRate(2);

  m_moteurGauche.SetInverted(true);
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
  double s_droite = Rampe(m_precDroite, droite);
  double s_gauche = Rampe(m_precGauche, gauche);
  m_moteurDroite.Set(s_droite);
  m_moteurGauche.Set(s_gauche);

  frc::SmartDashboard::PutNumber("Speed Droite", m_moteurDroite.Get());

  m_precDroite = droite;
  m_precGauche = gauche;
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

double Drivetrain::Rampe(double precSpeed, double value) {
  double speed = value;
  if(!m_rampe) return speed;

  if(speed > 0 && speed > precSpeed - 0.02){
    speed = precSpeed - 0.02;
    std::cout << "Rampe activated" << std::endl;
  }
  return speed;
}

void Drivetrain::ToggleRampe() {
  m_rampe = !m_rampe;
}

units::meter_t Drivetrain::GetEncodeurDroit() {
  return units::meter_t((m_encodeurDroite1.GetPosition() + m_encodeurDroite2.GetPosition()) / 2.0);
}

units::meter_t Drivetrain::GetEncodeurGauche() {
  return units::meter_t((m_encodeurGauche1.GetPosition() + m_encodeurGauche2.GetPosition()) / 2.0);
}