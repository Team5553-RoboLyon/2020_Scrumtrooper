#pragma once

#include <frc2/command/PIDSubsystem.h>
#include <frc/VictorSP.h>
#include <frc/DutyCycleEncoder.h>

#include "Constants.h"

class TelescopicArm : public frc2::PIDSubsystem {
 public:
  TelescopicArm();

  void UseOutput(double output, double setpoint) override;
  double GetMeasurement() override;

  void Up();
  void Down();
  void Stop();

 private:
  frc::VictorSP m_moteur{kTelescopicArmMoteur};
  frc::DutyCycleEncoder m_encodeur{kTelescopicArmEncodeur};
};