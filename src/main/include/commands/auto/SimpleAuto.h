/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/Timer.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Feeder.h"
#include "subsystems/AdjustableHood.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/Turret.h"

#include <commands/scoring/PrepShoot.h>
#include <commands/scoring/AdjustTurret.h>
#include <commands/scoring/Shoot.h>
#include <commands/scoring/Feed.h>
#include <commands/driving/AutoDrive.h>

class SimpleAuto : public frc2::CommandHelper<frc2::CommandBase, SimpleAuto> {
 public:
  SimpleAuto(Shooter* shooter, Turret* turret, AdjustableHood* adjustableHood, Feeder* feeder,
             Intake* intake, Drivetrain* drivetrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  frc2::ParallelCommandGroup *m_prepShootGroup, *m_shootGroup;
  AutoDrive* m_reculer;
  frc::Timer m_timer;
  int state;
};
