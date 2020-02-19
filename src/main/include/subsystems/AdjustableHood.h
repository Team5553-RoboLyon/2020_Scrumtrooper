#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>
#include <frc/Encoder.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class AdjustableHood : public frc2::SubsystemBase {
 public:
  AdjustableHood();

  void Close();
  void Monter();
  void Descendre();
  void SetAngle(double angle);

  double actualAngle = 0.0;

 private:
  bool isOpened;
  bool isActivated;
  double integral = 0.0;
  double prev_error = 0.0;
  VictorSPX m_moteur{kAdjustableHoodMoteur};
  frc::Encoder encodeur{kAdjustableHoodEncodeurA, kAdjustableHoodEncodeurB};
};