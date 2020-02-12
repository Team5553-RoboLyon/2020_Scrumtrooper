/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"
#include "subsystems/Convoyer.h"
#include "subsystems/Feeder.h"

class Shoot : public frc2::CommandHelper<frc2::CommandBase, Shoot> {
 public:
  Shoot(double puissance, Shooter* shooter, Convoyer* Convoyer, Feeder* Feeder);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Shooter* m_shooter;
  Feeder* m_feeder;
  Convoyer* m_convoyer;
  double m_puissance = 0.0;
};
