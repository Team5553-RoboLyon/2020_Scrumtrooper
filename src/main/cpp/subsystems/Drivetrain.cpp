/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"

#include <frc/smartdashboard/SmartDashboard.h>

double find_radius(double d0, double d1, double d2, double h) {
  double a0 = (d1 - d0) / h;
  double a1 = (d2 - d0) / (2 * h);
  double a2 = (d2 - d1) / h;

  double a = (a0 + a1 + a2) / 3;

  double angle = atan(a);

  double corde = d0 / a;

  double radius = corde / (2 * sin(angle));

  frc::SmartDashboard::PutNumber("Angle", angle);
  frc::SmartDashboard::PutNumber("Corde", corde);
  frc::SmartDashboard::PutNumber("Radius", radius);

  return radius;
}

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
  m_warningLevel = 0;
  frc::SmartDashboard::PutNumber("Droite1", m_encodeurDroite1.GetPosition());
  frc::SmartDashboard::PutNumber("Droite2", m_encodeurDroite2.GetPosition());
  frc::SmartDashboard::PutNumber("Gauche1", m_encodeurGauche1.GetPosition());
  frc::SmartDashboard::PutNumber("Gauche2", m_encodeurGauche2.GetPosition());

  if (m_isLogFileEnabled) {
    m_logFile->Log(m_encodeurDroite1.GetPosition(), m_encodeurDroite2.GetPosition(),
                   m_encodeurGauche1.GetPosition(), m_encodeurGauche2.GetPosition(),
                   m_encoderExterneDroite.Get(), m_encoderExterneGauche.Get());
  }

  if (m_isUltraSonicSensorActivated) {
    //############ Arduino Droit #############
    uint8_t sendBufferDroit = 0;
    uint16_t receiveBufferDroit[DRIVETRAIN_ULTRASONICSIZE];
    if (m_arduinoDroit.Transaction(&sendBufferDroit, 1, (uint8_t*)receiveBufferDroit, 10)) {
      std::cout << "AD : Transfer Aborted..." << std::endl;
    } else {
      std::cout << "AD : ";
      for (int i = 0; i < (DRIVETRAIN_ULTRASONICSIZE - 2); i++) {
        m_receiveBufferDroitDouble[i] = ((double)receiveBufferDroit[i] * 500.0f) / 65535.0f;
        std::cout << m_receiveBufferDroitDouble[i] << "    ";
      }
      std::cout << std::endl;
      for (int i = 0; i < (DRIVETRAIN_ULTRASONICSIZE - 2); i++) {
        if ((m_receiveBufferDroitDouble[i] < DRIVETRAIN_ULTRASONIC_WARNING_THRESHOLD) &&
            (m_receiveBufferDroitDouble[i] != 0.0)) {
          // m_warningLevel++;
        }
      }
    }

    //############ Arduino Gauche #############
    uint8_t sendBufferGauche = 0;
    uint16_t receiveBufferGauche[DRIVETRAIN_ULTRASONICSIZE];
    if (m_arduinoGauche.Transaction(&sendBufferGauche, 1, (uint8_t*)receiveBufferGauche, 10)) {
      std::cout << "AG : Transfer Aborted..." << std::endl;
    } else {
      std::cout << "AG : ";
      for (int i = 0; i < (DRIVETRAIN_ULTRASONICSIZE - 2); i++) {
        m_receiveBufferGaucheDouble[i] = ((double)receiveBufferGauche[i] * 500.0f) / 65535.0f;
        std::cout << m_receiveBufferGaucheDouble[i] << "    ";
      }
      std::cout << std::endl;
      for (int i = 0; i < (DRIVETRAIN_ULTRASONICSIZE - 2); i++) {
        if ((m_receiveBufferGaucheDouble[i] < DRIVETRAIN_ULTRASONIC_WARNING_THRESHOLD) &&
            (m_receiveBufferDroitDouble[i] != 0.0)) {
          m_warningLevel++;
        }
      }
    }
    frc::SmartDashboard::PutNumber("Warning Level", m_warningLevel);
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

void Drivetrain::ChangeSpeed() {
  if(Drivetrain::SpeedMode::quick) { 
    SlowSpeed(); 
  } else if (Drivetrain::SpeedMode::slow){
    QuickSpeed();
  }

}

void Drivetrain::SlowSpeed()
{
  m_speedMode = Drivetrain::SpeedMode::slow;
}

void Drivetrain::QuickSpeed() {
 m_speedMode = Drivetrain::SpeedMode::quick;
}

double Drivetrain::CalculateTurn(double forward, double turn) {
  /*if (m_warningLevel == 3) {
    frc::SmartDashboard::PutNumber("Turn AvC", turn);
    double radius_crashed =
        find_radius(m_receiveBufferGaucheDouble[2], m_receiveBufferGaucheDouble[1],
                    m_receiveBufferGaucheDouble[0], 30.5);

    double radius = forward / (turn + 0.0000000000000000000000000000000000000001);

    if (abs(radius) > abs(radius_crashed)) {
      if (radius > 0) {
        radius += (radius_crashed - radius) / 2;
      } else {
        radius -= (radius_crashed + radius) / 2;
      }

      turn = forward * radius;
    }
    frc::SmartDashboard::PutNumber("Turn ApC", turn);
  }*/
  return turn;
}

void Drivetrain::Drive(double gauche, double droite) {
  if(m_speedMode == 1){
    droite *= 0.5;
    gauche *= 0.5;
  } 
  m_moteurDroite.Set(droite);
  m_moteurGauche.Set(gauche);

  m_actualSpeed = (droite + gauche) / 2;
}

void Drivetrain::AutomatedShoot() {
  m_encoderValue =
      (m_encoderExterneDroite.GetDistance() + m_encoderExterneGauche.GetDistance()) / 2;

  double error = m_nbrTickAutomatedShoot - m_encoderValue;
  m_integral += (error * .02);
  double derivative = (error - m_prev_error) / .02;
  double rcw = 0.0025 * error + 0.00023 * m_integral + 0.0003 * derivative;
  // Precédement I = 0.00021

  m_prev_error = error;
  m_moteurDroite.Set(rcw);
  m_moteurGauche.Set(rcw);
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