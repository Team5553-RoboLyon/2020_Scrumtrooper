#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/Encoder.h>

#include "Constants.h"

class Winch : public frc2::SubsystemBase {
 public:
  Winch();

  void Up();
  void Down();
  void Stop();

 private:
  frc::VictorSP m_moteur1{kWinchMoteur1};
  frc::VictorSP m_moteur2{kWinchMoteur2};
  frc::SpeedControllerGroup m_moteurGroup{m_moteur1, m_moteur2};

  frc::Encoder m_encoder{kClimberEncodeurA, kClimberEncodeurB};
};