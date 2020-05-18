/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"

double FindRadius(double d0, double d1, double d2, double h) {
  double a0 = (d1 - d0) / h;
  double a1 = (d2 - d0) / (2 * h);
  double a2 = (d2 - d1) / h;

  double a = (a0 + a1 + a2) / 3;

  double angle = std::atan(a);

  double corde = d0 / a;

  double radius = corde / (2 * std::sin(angle));

  return radius;
}

Drivetrain::Drivetrain() {
  m_RightMotor.RestoreFactoryDefaults();
  m_LeftMotor.RestoreFactoryDefaults();
  m_RightMotorFollower.RestoreFactoryDefaults();
  m_LeftMotorFollower.RestoreFactoryDefaults();

  m_RightMotor.SetOpenLoopRampRate(DRIVETRAIN_OPEN_LOOP_RAMP_RATE);
  m_LeftMotor.SetOpenLoopRampRate(DRIVETRAIN_OPEN_LOOP_RAMP_RATE);
  m_RightMotorFollower.SetOpenLoopRampRate(DRIVETRAIN_OPEN_LOOP_RAMP_RATE);
  m_LeftMotorFollower.SetOpenLoopRampRate(DRIVETRAIN_OPEN_LOOP_RAMP_RATE);

  m_RightMotorFollower.Follow(m_RightMotor);
  m_LeftMotorFollower.Follow(m_LeftMotor);

  m_LeftMotor.SetInverted(true);
  m_LeftExternalEncoder.SetDistancePerPulse(-1);

  m_RightEncoder1.SetPositionConversionFactor(DRIVETRAIN_POSITION_CONVERSION_FACTOR);
  m_RightEncoder2.SetPositionConversionFactor(DRIVETRAIN_POSITION_CONVERSION_FACTOR);
  m_LeftEncoder1.SetPositionConversionFactor(DRIVETRAIN_POSITION_CONVERSION_FACTOR);
  m_LeftEncoder2.SetPositionConversionFactor(DRIVETRAIN_POSITION_CONVERSION_FACTOR);

  ResetEncodeurs();
  SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

  EnableLogFile(false);
}

void Drivetrain::Periodic() {
  m_WarningLevel = 0;

  if (m_IsLogFileEnabled) {
    m_LogFile->Log(m_RightEncoder1.GetPosition(), m_RightEncoder2.GetPosition(),
                   m_LeftEncoder1.GetPosition(), m_LeftEncoder2.GetPosition(),
                   m_RightExternalEncoder.Get(), m_LeftExternalEncoder.Get());
  }

  /*if (m_IsUltraSonicSensorActivated) {
    //############ Right Arduino #############
    uint8_t right_send_buffer = 0;
    uint16_t right_receive_buffer[DRIVETRAIN_ULTRASONIC_SIZE];
    if (m_RightArduino.Transaction(&right_send_buffer, 1, (uint8_t*)right_receive_buffer, 10)) {
      std::cout << "AD : Transfer Aborted..." << std::endl;
    } else {
      std::cout << "AD : ";
      for (int i = 0; i < (DRIVETRAIN_ULTRASONIC_SIZE - 2); i++) {
        m_DoubleReceiveBufferRight[i] = ((double)right_receive_buffer[i] * 500.0f) / 65535.0f;
        std::cout << m_DoubleReceiveBufferRight[i] << "    ";
      }
      std::cout << std::endl;
      for (int i = 0; i < (DRIVETRAIN_ULTRASONIC_SIZE - 2); i++) {
        if ((m_DoubleReceiveBufferRight[i] < DRIVETRAIN_ULTRASONIC_WARNING_THRESHOLD) &&
            (m_DoubleReceiveBufferRight[i] != 0.0)) {
          // m_WarningLevel++;
        }
      }
    }

    //############ Left Arduino #############
    uint8_t left_send_buffer = 0;
    uint16_t left_receive_buffer[DRIVETRAIN_ULTRASONIC_SIZE];
    if (m_LeftArduino.Transaction(&left_send_buffer, 1, (uint8_t*)left_receive_buffer, 10)) {
      std::cout << "AG : Transfer Aborted..." << std::endl;
    } else {
      std::cout << "AG : ";
      for (int i = 0; i < (DRIVETRAIN_ULTRASONIC_SIZE - 2); i++) {
        m_DoubleReceiveBufferLeft[i] = ((double)left_receive_buffer[i] * 500.0f) / 65535.0f;
        std::cout << m_DoubleReceiveBufferLeft[i] << "    ";
      }
      std::cout << std::endl;
      for (int i = 0; i < (DRIVETRAIN_ULTRASONIC_SIZE - 2); i++) {
        if ((m_DoubleReceiveBufferLeft[i] < DRIVETRAIN_ULTRASONIC_WARNING_THRESHOLD) &&
            (m_DoubleReceiveBufferRight[i] != 0.0)) {
          m_WarningLevel++;
        }
      }

}
frc::SmartDashboard::PutNumber("Warning Level", m_WarningLevel);
}
*/
}

void Drivetrain::EnableLogFile(bool enable) {
  if (!m_IsLogFileEnabled && enable) {
    m_LogFile = new CSVLogFile("/media/logs/log", "Droite 1", "Droite 2", "Gauche 1", "Gauche 2",
                               "Encodeur externe");
  } else if (m_IsLogFileEnabled && !enable) {
    delete m_LogFile;
  }
  m_IsLogFileEnabled = enable;
}

void Drivetrain::Stop() {
  m_RightMotor.StopMotor();
  m_LeftMotor.StopMotor();
}

void Drivetrain::ChangeSpeed() {
  if (m_SpeedMode == Drivetrain::SpeedMode::quick) {
    SlowSpeed();
  } else if (m_SpeedMode == Drivetrain::SpeedMode::slow) {
    QuickSpeed();
  }
}

void Drivetrain::SlowSpeed() { m_SpeedMode = Drivetrain::SpeedMode::slow; }

void Drivetrain::QuickSpeed() { m_SpeedMode = Drivetrain::SpeedMode::quick; }

double Drivetrain::CalculateTurn(double forward, double turn) {
  /*if (m_WarningLevel == 3) {
    frc::SmartDashboard::PutNumber("Turn AvC", turn);
    double radius_crashed =
        FindRadius(m_DoubleReceiveBufferLeft[2], m_DoubleReceiveBufferLeft[1],
                    m_DoubleReceiveBufferLeft[0], 30.5);

    double radius = forward / (turn + 0.0000000000000000000000000000000000000001);

    if (std::abs(radius) > std::abs(radius_crashed)) {
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
  if (m_SpeedMode == Drivetrain::SpeedMode::slow) {
    droite *= 0.25;
    gauche *= 0.25;
  }
  m_RightMotor.Set(droite);
  m_LeftMotor.Set(gauche);
}

void Drivetrain::ResetEncodeurs() {
  m_RightEncoder1.SetPosition(0.0);
  m_RightEncoder2.SetPosition(0.0);
  m_LeftEncoder1.SetPosition(0.0);
  m_LeftEncoder2.SetPosition(0.0);
  m_RightExternalEncoder.Reset();
  m_LeftExternalEncoder.Reset();
}

void Drivetrain::SetIdleMode(rev::CANSparkMax::IdleMode mode) {
  m_RightMotor.SetIdleMode(mode);
  m_RightMotorFollower.SetIdleMode(mode);
  m_LeftMotor.SetIdleMode(mode);
  m_LeftMotorFollower.SetIdleMode(mode);
}

void Drivetrain::DisableRamp() {
  m_RightMotor.SetOpenLoopRampRate(0.0);
  m_LeftMotor.SetOpenLoopRampRate(0.0);
  m_RightMotorFollower.SetOpenLoopRampRate(0.0);
  m_LeftMotorFollower.SetOpenLoopRampRate(0.0);
}

void Drivetrain::EnableRamp() {
  m_RightMotor.SetOpenLoopRampRate(DRIVETRAIN_OPEN_LOOP_RAMP_RATE);
  m_LeftMotor.SetOpenLoopRampRate(DRIVETRAIN_OPEN_LOOP_RAMP_RATE);
  m_RightMotorFollower.SetOpenLoopRampRate(DRIVETRAIN_OPEN_LOOP_RAMP_RATE);
  m_LeftMotorFollower.SetOpenLoopRampRate(DRIVETRAIN_OPEN_LOOP_RAMP_RATE);
}

int Drivetrain::GetRightEncoder() { return m_RightExternalEncoder.Get(); }

int Drivetrain::GetLeftEncoder() { return m_LeftExternalEncoder.Get(); }
