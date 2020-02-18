#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>
#include <frc/Encoder.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"

class AdjustableHood : public frc2::SubsystemBase {
 public:
    AdjustableHood();

    void Close();
    void SetAngle(double angle);

 private:
    bool isOpened;
    bool isActivated;
    double integral = 0.0;
    double prev_error = 0.0;
    frc::VictorSP m_moteur {kAdjustableHoodMoteur};
    frc::Encoder encodeur {kAdjustableHoodEncodeurA, kAdjustableHoodEncodeurB};
};