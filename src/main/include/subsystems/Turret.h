#pragma once

#include <frc2/command/ProfiledPIDSubsystem.h>
#include <frc/VictorSP.h>
#include <frc/Encoder.h>
#include <units/units.h>

#include "Constants.h"

class Turret : public frc2::ProfiledPIDSubsystem<units::degrees> {
  using State = frc::TrapezoidProfile<units::degrees>::State;

 public:
  Turret();

  void UseOutput(double output, State setpoint) override;
  units::degree_t GetMeasurement() override;

  void Stop();
  void Left();
  void Right();

 private:
  frc::VictorSP m_moteur{kTurretMoteur};
  frc::Encoder m_encodeur{4, 5};
};