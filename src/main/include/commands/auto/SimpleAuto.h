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

#include "subsystems/AdjustableHood.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Feeder.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/Turret.h"

#include "commands/driving/AutoDrive.h"
#include "commands/scoring/AdjustTurret.h"
#include "commands/scoring/Feed.h"
#include "commands/scoring/PrepShoot.h"
#include "commands/scoring/Shoot.h"

class SimpleAuto : public frc2::CommandHelper<frc2::CommandBase, SimpleAuto> {
 public:
  SimpleAuto(Shooter* pshooter, Turret* pturret, AdjustableHood* padjustable_hood, Feeder* pfeeder,
             Intake* pintake, Drivetrain* pdrivetrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  frc2::ParallelCommandGroup *m_pPrepShootGroup, *m_pShootGroup;
  AutoDrive* m_pGoReverse;
  frc::Timer m_Timer;
  int m_State;
};
