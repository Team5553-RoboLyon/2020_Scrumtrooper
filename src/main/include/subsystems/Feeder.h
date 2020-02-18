#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class Feeder : public frc2::SubsystemBase {
 public:
   Feeder();

   void Activate();
   void UnBlock();
   void Stop();

 private:
   frc::VictorSP m_moteurFeeder{kFeederMoteur};
   VictorSPX m_moteurConveyor{kConveyorMoteur};
};