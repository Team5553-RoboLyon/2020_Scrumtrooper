#pragma once

#include <frc2/command/PIDSubsystem.h>
#include <frc/VictorSP.h>
#include <frc/Encoder.h>
#include <frc/DigitalOutput.h>
#include <frc/smartdashboard/SendableBase.h>

#include "Constants.h"

class Turret : public frc2::PIDSubsystem {
 public:
  Turret();

  void UseOutput(double output, double setpoint) override;
  double GetMeasurement() override;
  void SetClampedSetpoint(double setpoint);

  void Stop();
  void Left();
  void Right();

  void StartLedRing();
  void StopLedRing();

 private:
  frc::VictorSP m_moteur{kTurretMoteur};
  frc::Encoder m_encodeur{kTurretEncodeurA, kTurretEncodeurB};
  frc::DigitalOutput m_ledRing{kTurretRelay};
  frc::SendableHelper test{};
};