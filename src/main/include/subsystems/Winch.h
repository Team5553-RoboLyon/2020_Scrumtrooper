#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

class Winch : public frc2::SubsystemBase {
 public:
  Winch();

  void Up();
  void Down();
  void Stop();

 private:
  rev::CANSparkMax m_moteur{kWinchMoteur, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANEncoder m_encodeur{m_moteur};
};