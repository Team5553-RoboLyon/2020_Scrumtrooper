#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>

#include "Constants.h"

class Hood : public frc2::SubsystemBase {
 public:
    Hood();

    void CloseHood();
    void SetAngle();
    void Activate();
    void Stop();
 private:
    bool isOpened;
    bool isActivated;
    frc::VictorSP m_moteur {kHoodMoteur};
};