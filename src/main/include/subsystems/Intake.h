#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>
#include <frc/VictorSP.h>

#include "Constants.h"

class Intake : public frc2::SubsystemBase {
 public:
    enum class IntakePosition {kOpened, kClosed};
    Intake();

    void Close();
    void Open();
    void ChangePosition();
    void Activate();
    void Stop();
 private:
    IntakePosition m_position;
    frc::DoubleSolenoid m_solenoid {kIntakeA, kIntakeB};
    VictorSPX m_moteur {kIntakeMoteur};
};