#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/Timer.h>

#include "Constants.h"

#define TOTAL_CHARGE_TIME 2.5

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  void Shoot(double puissance);
  void SetRamp(double secondsFromNeutralToFull);
  void Periodic();

  double GetTimer();
  void ResetTimer();
  void StopTimer();

 private:
  VictorSPX m_moteur1{kShooterMoteurDroite};
  VictorSPX m_moteur2{kShooterMoteurGauche};
  frc::Timer m_timer;
};