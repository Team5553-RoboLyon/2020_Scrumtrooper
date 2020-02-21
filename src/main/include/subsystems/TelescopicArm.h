#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>

#include "Constants.h"

class TelescopicArm : public frc2::SubsystemBase {
 public:
  TelescopicArm();

  void Up();
  void Down();
  void Stop();

 private:
  frc::VictorSP m_moteur{kTelescopicArmMoteur};
};