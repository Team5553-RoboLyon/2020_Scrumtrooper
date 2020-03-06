/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/Auto.h"

#include <frc2/command/ParallelCommandGroup.h>

Auto::Auto(Shooter* shooter, Turret* turret, AdjustableHood* adjustableHood, Feeder* feeder,
           Intake* intake, Drivetrain* drivetrain) {
  m_1 = new frc2::ParallelCommandGroup(PrepShoot(shooter), AdjustTurret(turret));
  m_2 = new frc2::ParallelCommandGroup(AdjustHood(adjustableHood), Shoot(shooter),
                                       Feed(feeder, intake, shooter));
  m_3 = new AutoDrive(drivetrain, 1500);
}

// Called when the command is initially scheduled.
void Auto::Initialize() {
  state = 0;
  m_1->Schedule();
  m_timer.Reset();
  m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void Auto::Execute() {
  if (m_timer.Get() > 3 && state == 0) {
    state = 1;
    m_1->Cancel();
    m_2->Schedule();
  } else if (m_timer.Get() > 8 && state == 1) {
    m_2->Cancel();
    m_3->Schedule();
  }
}

// Called once the command ends or is interrupted.
void Auto::End(bool interrupted) {
  m_timer.Reset();
  m_timer.Stop();
  m_1->Cancel();
  m_2->Cancel();
  m_3->Cancel();
}

// Returns true when the command should end.
bool Auto::IsFinished() { return m_timer.Get() > 13; }
