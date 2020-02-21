#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>

#include "Constants.h"

class Turret : public frc2::SubsystemBase {
 public:
  Turret();

  void Periodic() override;
  void Activate();
  void Stop();

  // TEST COMMANDS !!
  void Left();
  void Right();

 private:
  bool m_turretActivated;
  frc::VictorSP m_moteur{kTurretMoteur};
};