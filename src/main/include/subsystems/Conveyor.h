#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>

#include "Constants.h"

class Conveyor : public frc2::SubsystemBase {
 public:
    Conveyor();

    void Activate();
    void Stop();
 private:
   frc::VictorSP m_moteur {kConveyorMoteur};
};