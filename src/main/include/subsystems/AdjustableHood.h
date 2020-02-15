#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>

#include "Constants.h"

class AdjustableHood : public frc2::SubsystemBase {
 public:
    AdjustableHood();

    void Close();
    void SetAngle();
    void Activate();
    void Stop();

 private:
    bool isOpened;
    bool isActivated;
    frc::VictorSP m_moteur {kAdjustableHoodMoteur};
};