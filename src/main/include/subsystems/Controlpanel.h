#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>
#include <frc/VictorSP.h>

#include "Constants.h"

class Controlpanel : public frc2::SubsystemBase {
 public:
    enum class ControlpanelPosition {kOpened, kClosed};

    Controlpanel();

    void OpenControlpanel();
    void CloseControlpanel();
    void ChangeControlpanelPosition();
    void Activate();
    void Stop();
 private:
    frc::VictorSP m_moteur {kControlpanelMoteur};
    frc::DoubleSolenoid m_solenoid {kControlpanelA, kControlpanelB};
    ControlpanelPosition m_position;
};