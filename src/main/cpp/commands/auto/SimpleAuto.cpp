/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/SimpleAuto.h"

#include <frc2/command/ParallelCommandGroup.h>

SimpleAuto::SimpleAuto(Shooter* shooter, Turret* turret, AdjustableHood* adjustableHood,
                       Feeder* feeder, Intake* intake, Drivetrain* drivetrain) {
  m_prepShootGroup = new frc2::ParallelCommandGroup(PrepShoot(shooter), AdjustTurret(turret));
  m_shootGroup = new frc2::ParallelCommandGroup(AdjustHood(adjustableHood), Shoot(shooter),
                                                Feed(feeder, intake, shooter));
  m_reculer = new AutoDrive(drivetrain, 1500);
}

void SimpleAuto::Initialize() {
  state = 0;
  m_prepShootGroup->Schedule();
  m_timer.Reset();
  m_timer.Start();
}

void SimpleAuto::Execute() {
  switch (state) {
    case 0:
      if (m_timer.Get() > 3) {
        state++;
        m_prepShootGroup->Cancel();
        m_shootGroup->Schedule();
      }
      break;
    case 1:
      if (m_timer.Get() > 12) {
        state++;
        m_shootGroup->Cancel();
        m_reculer->Schedule();
      }
      break;
    case 2:
      if (m_timer.Get() > 12.6) {
        m_reculer->Cancel();
      }
      break;
    default:
      break;
  }
}

void SimpleAuto::End(bool interrupted) {
  m_timer.Reset();
  m_timer.Stop();

  m_prepShootGroup->Cancel();
  m_shootGroup->Cancel();
  m_reculer->Cancel();
}

bool SimpleAuto::IsFinished() { return m_timer.Get() > 15; }
