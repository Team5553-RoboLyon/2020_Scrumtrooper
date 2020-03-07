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
  m_1 = new frc2::ParallelCommandGroup(PrepShoot(shooter), AdjustTurret(turret));
  m_2 = new frc2::ParallelCommandGroup(AdjustHood(adjustableHood), Shoot(shooter),
                                       Feed(feeder, intake, shooter));
  m_3 = new AutoDrive(drivetrain, 1500);
}

void SimpleAuto::Initialize() {
  state = 0;
  m_1->Schedule();
  m_timer.Reset();
  m_timer.Start();
}

void SimpleAuto::Execute() {
  if (m_timer.Get() > 3 && state == 0) {
    state = 1;
    m_1->Cancel();
    m_2->Schedule();
  } else if (m_timer.Get() > 12 && state == 1) {
    m_2->Cancel();
    m_3->Schedule();
  }
}

void SimpleAuto::End(bool interrupted) {
  m_timer.Reset();
  m_timer.Stop();
  m_1->Cancel();
  m_2->Cancel();
  m_3->Cancel();
}

bool SimpleAuto::IsFinished() { return m_timer.Get() > 12.6; }
