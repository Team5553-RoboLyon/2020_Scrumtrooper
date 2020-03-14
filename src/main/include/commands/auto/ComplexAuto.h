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
#include <commands/scoring/MoveHood.h>
#include <commands/driving/AutoDrive.h>
#include <commands/intake/ChangeIntakePosition.h>
#include <commands/intake/TakeCell.h>

class ComplexAuto : public frc2::CommandHelper<frc2::CommandBase, ComplexAuto> {
 public:
  ComplexAuto(Shooter* shooter, Turret* turret, AdjustableHood* adjustableHood, Feeder* feeder,
              Intake* intake, Drivetrain* drivetrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  frc2::ParallelCommandGroup *m_prepShootGroup, *m_shootGroup, *m_reculer;
  AdjustHood* m_adjustHood;
  Shoot* m_shoot;
  Feed* m_feed;
  ChangeIntakePosition* m_changeIntakePosition;
  AutoDrive* m_avancer;
  MoveHood* m_moveHoodZero;
  frc::Timer m_timer;
  int state;
};
