#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>
#include <frc/SpeedControllerGroup.h>

#include "Constants.h"

class Winch : public frc2::SubsystemBase {
 public:
    Winch();

    void Up();
    void Down();
    void Stop();
 private:
  frc::VictorSP moteur1 {kWinchMoteur1};
  frc::VictorSP moteur2 {kWinchMoteur2};
  frc::SpeedControllerGroup moteurGroup {moteur1, moteur2};
};