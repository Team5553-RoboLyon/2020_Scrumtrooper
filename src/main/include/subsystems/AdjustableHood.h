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

 private:
  bool m_isOpened;
  bool m_isActivated;
  double m_actualAngle = 0.0;
  double m_integral = 0.0;
  double m_prev_error = 0.0;
  VictorSPX m_moteur{kAdjustableHoodMoteur};
  frc::Encoder m_encodeur{kAdjustableHoodEncodeurA, kAdjustableHoodEncodeurB};
};