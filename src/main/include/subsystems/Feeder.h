#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>

#include "Constants.h"

class Feeder : public frc2::SubsystemBase {
 public:
   Feeder();

   void Activate();
   void Stop();
 private:
   frc::VictorSP m_moteur {kFeederMoteur};
};