/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"

#include <frc/smartdashboard/SmartDashboard.h>

Drivetrain::Drivetrain() {
  m_moteurDroite.RestoreFactoryDefaults();
  m_moteurGauche.RestoreFactoryDefaults();
  m_moteurDroiteFollower.RestoreFactoryDefaults();
  m_moteurGaucheFollower.RestoreFactoryDefaults();

  m_moteurDroite.SetOpenLoopRampRate(kOpenLoopRampeRate);
  m_moteurGauche.SetOpenLoopRampRate(kOpenLoopRampeRate);
  m_moteurDroiteFollower.SetOpenLoopRampRate(kOpenLoopRampeRate);
  m_moteurGaucheFollower.SetOpenLoopRampRate(kOpenLoopRampeRate);

  m_moteurDroiteFollower.Follow(m_moteurDroite);
  m_moteurGaucheFollower.Follow(m_moteurGauche);

  m_moteurGauche.SetInverted(true);

  m_encodeurDroite1.SetPositionConversionFactor(kPositionConversionFactor);
  m_encodeurDroite2.SetPositionConversionFactor(kPositionConversionFactor);
  m_encodeurGauche1.SetPositionConversionFactor(kPositionConversionFactor);
  m_encodeurGauche2.SetPositionConversionFactor(kPositionConversionFactor);

  ResetEncodeurs();
  SetIdleMode(kIdleMode);

  EnableLogFile(false);
}

void Drivetrain::Periodic() {
  frc::SmartDashboard::PutNumber("Droite1", m_encodeurDroite1.GetPosition());
  frc::SmartDashboard::PutNumber("Droite2", m_encodeurDroite2.GetPosition());
  frc::SmartDashboard::PutNumber("Gauche1", m_encodeurGauche1.GetPosition());
  frc::SmartDashboard::PutNumber("Gauche2", m_encodeurGauche2.GetPosition());

  if (m_isLogFileEnabled) {
    m_logFile->Log(m_encodeurDroite1.GetPosition(), m_encodeurDroite2.GetPosition(),
                   m_encodeurGauche1.GetPosition(), m_encodeurGauche2.GetPosition(),
                   m_encoderExterneDroite.Get(), m_encoderExterneGauche.Get());
  }
}

void Drivetrain::EnableLogFile(bool enable) {
  if (!m_isLogFileEnabled && enable) {
    m_logFile = new CSVLogFile("/media/logs/log", "Droite 1", "Droite 2", "Gauche 1", "Gauche 2",
                               "Encodeur externe");
  } else if (m_isLogFileEnabled && !enable) {
    delete m_logFile;
  }
  m_isLogFileEnabled = enable;
}

void Drivetrain::Stop() {
  m_moteurDroite.StopMotor();
  m_moteurGauche.StopMotor();
}

void Drivetrain::Drive(double gauche, double droite) {
  m_moteurDroite.Set(droite);
  m_moteurGauche.Set(gauche);

  actualSpeed = (droite + gauche) / 2;
}

void Drivetrain::AutomatedShoot() {
  encoderValue = (m_encoderExterneDroite.GetDistance() + m_encoderExterneGauche.GetDistance()) / 2;

  double error = nbrTickAutomatedShoot - encoderValue;
  m_integral += (error * .02);
  double derivative = (error - m_prev_error) / .02;
  double rcw = 0.0025 * error + 0.00023 * m_integral + 0.0003 * derivative;
  // Precédement I = 0.00021

  m_prev_error = error;
}

void Drivetrain::ResetEncodeurs() {
  m_encodeurDroite1.SetPosition(0.0);
  m_encodeurDroite2.SetPosition(0.0);
  m_encodeurGauche1.SetPosition(0.0);
  m_encodeurGauche2.SetPosition(0.0);
  m_encoderExterneDroite.Reset();
  m_encoderExterneGauche.Reset();
}

void Drivetrain::SetIdleMode(rev::CANSparkMax::IdleMode mode) {
  m_moteurDroite.SetIdleMode(mode);
  m_moteurDroiteFollower.SetIdleMode(mode);
  m_moteurGauche.SetIdleMode(mode);
  m_moteurGaucheFollower.SetIdleMode(mode);
}

void Drivetrain::DisableRamp() {
  m_moteurDroite.SetOpenLoopRampRate(0.0);
  m_moteurGauche.SetOpenLoopRampRate(0.0);
  m_moteurDroiteFollower.SetOpenLoopRampRate(0.0);
  m_moteurGaucheFollower.SetOpenLoopRampRate(0.0);
}

void Drivetrain::EnableRamp() {
  m_moteurDroite.SetOpenLoopRampRate(kOpenLoopRampeRate);
  m_moteurGauche.SetOpenLoopRampRate(kOpenLoopRampeRate);
  m_moteurDroiteFollower.SetOpenLoopRampRate(kOpenLoopRampeRate);
  m_moteurGaucheFollower.SetOpenLoopRampRate(kOpenLoopRampeRate);
}

units::meter_t Drivetrain::GetEncodeurDroit() {
  return units::meter_t((m_encodeurDroite1.GetPosition() + m_encodeurDroite2.GetPosition()) / 2.0);
}

units::meter_t Drivetrain::GetEncodeurGauche() {
  return units::meter_t((m_encodeurGauche1.GetPosition() + m_encodeurGauche2.GetPosition()) / 2.0);
}