#pragma once

#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>

#include "Constants.h"

class Feeder : public frc2::SubsystemBase {
 public:
  Feeder();

  void Activate();
  void UnBlock();
  void Stop();

 private:
  ctre::phoenix::motorcontrol::can::VictorSPX m_moteurFeeder{kFeederMoteur};
  ctre::phoenix::motorcontrol::can::VictorSPX m_moteurConveyor{kConveyorMoteur};
};