/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/ComplexAuto.h"

#include <frc2/command/ParallelCommandGroup.h>

ComplexAuto::ComplexAuto(Shooter* shooter, Turret* turret, AdjustableHood* adjustableHood,
                         Feeder* feeder, Intake* intake, Drivetrain* drivetrain) {
  m_prepShootGroup = new frc2::ParallelCommandGroup(PrepShoot(shooter), AdjustTurret(turret));
  m_adjustHood = new AdjustHood(adjustableHood);
  m_shoot = new Shoot(shooter);
  m_feed = new Feed(feeder, intake, shooter);
  m_changeIntakePosition = new ChangeIntakePosition(intake);
  m_reculer = new frc2::ParallelCommandGroup(AutoDrive(drivetrain, 17000), TakeCell(intake));
  m_avancer = new AutoDrive(drivetrain, -10000);
  m_shootGroup = new frc2::ParallelCommandGroup(AdjustHood(adjustableHood), Shoot(shooter),
                                                Feed(feeder, intake, shooter));
  m_moveHoodZero = new MoveHood(adjustableHood, 0);
}

void ComplexAuto::Initialize() {
  state = 0;
  m_prepShootGroup->Schedule();
  m_timer.Reset();
  m_timer.Start();
}

void ComplexAuto::Execute() {
  switch (state) {
    case 0:
      if (m_timer.Get() > 3) {
        state++;
        m_prepShootGroup->Cancel();
        m_adjustHood->Schedule();
        m_feed->Schedule();
        m_shoot->Schedule();
        m_changeIntakePosition->Schedule();
      }
      break;
    case 1:
      if (m_timer.Get() > 8) {
        state++;
        m_adjustHood->Cancel();
        m_feed->Cancel();
        m_shoot->Cancel();
        m_changeIntakePosition->Cancel();
        m_reculer->Schedule();
        m_moveHoodZero->Schedule();
      }
      break;
    case 2:
      if (m_timer.Get() > 10.5) {
        state++;
        m_reculer->Cancel();
        m_moveHoodZero->Cancel();
        m_changeIntakePosition->Schedule();
        m_avancer->Schedule();
        m_prepShootGroup->Schedule();
      }
      break;
    case 3:
      if (m_timer.Get() > 11.5) {
        state++;
        m_changeIntakePosition->Cancel();
        m_avancer->Cancel();
        m_prepShootGroup->Cancel();
        m_shootGroup->Schedule();
      }
      break;

    default:
      break;
  }
}

void ComplexAuto::End(bool interrupted) {
  m_timer.Reset();
  m_timer.Stop();

  m_prepShootGroup->Cancel();
  m_shootGroup->Cancel();
  m_adjustHood->Cancel();
  m_feed->Cancel();
  m_shoot->Cancel();
  m_changeIntakePosition->Cancel();
  m_reculer->Cancel();
  m_avancer->Cancel();
  m_moveHoodZero->Cancel();
}

bool ComplexAuto::IsFinished() { return m_timer.Get() > 15; }
