#pragma once

#include <frc2/command/PIDSubsystem.h>
#include <frc/DutyCycleEncoder.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class AdjustableHood : public frc2::PIDSubsystem {
 public:
  AdjustableHood();

  void UseOutput(double output, double setpoint) override;
  double GetMeasurement() override;
  void SetClampedSetpoint(double setpoint);

  void ResetEncoder();

  void Close();
  void Monter();
  void Descendre();
  void Unblock();
  void Stop();

 private:
  VictorSPX m_moteur{kAdjustableHoodMoteur};
  frc::DutyCycleEncoder m_encodeur{kAdjustableHoodEncodeur};
  int m_lockedCount = 0;
  double m_prevVelocityError;
};