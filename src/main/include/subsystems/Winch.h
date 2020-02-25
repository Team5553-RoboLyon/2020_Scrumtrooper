#pragma once

#include <frc2/command/ProfiledPIDSubsystem.h>
#include <rev/CANSparkMax.h>
#include <units/units.h>

#include "Constants.h"

class Winch : public frc2::ProfiledPIDSubsystem<units::meters> {
  using State = frc::TrapezoidProfile<units::meters>::State;

 public:
  Winch();

  void UseOutput(double output, State setpoint) override;
  units::meter_t GetMeasurement() override;

  void Up();
  void Down();
  void Stop();

 private:
  rev::CANSparkMax m_moteur{kWinchMoteur, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANEncoder m_encodeur{m_moteur};
};