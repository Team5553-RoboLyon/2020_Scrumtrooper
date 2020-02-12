#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
 public:

    Shooter();

    void Shoot(double puissance);
    void Periodic();
 private:
   VictorSPX m_moteur1 {kShooteurMoteurDroite};
   VictorSPX m_moteur2 {kShooteurMoteurGauche};
};