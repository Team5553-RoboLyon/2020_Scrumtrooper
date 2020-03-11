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
  m_1 = new frc2::ParallelCommandGroup(PrepShoot(shooter), AdjustTurret(turret));
  m_2_hood = new AdjustHood(adjustableHood);
  m_2_shoot = new Shoot(shooter);
  m_2_feed = new Feed(feeder, intake, shooter);
  m_3 = new ChangeIntakePosition(intake, drivetrain);
  m_4 = new frc2::ParallelCommandGroup(AutoDrive(drivetrain, 17000), TakeCell(intake));
  m_5 = new ChangeIntakePosition(intake, drivetrain);
  m_6 = new AutoDrive(drivetrain, -10000);
  m_7 = new frc2::ParallelCommandGroup(PrepShoot(shooter), AdjustTurret(turret));
  m_8 = new frc2::ParallelCommandGroup(AdjustHood(adjustableHood), Shoot(shooter),
                                       Feed(feeder, intake, shooter));
  m_moveHoodZero = new MoveHood(adjustableHood, 0);
}

void ComplexAuto::Initialize() {
  state = 0;
  m_1->Schedule();
  m_timer.Reset();
  m_timer.Start();
}

void ComplexAuto::Execute() {
  /*if (m_timer.Get() > 3 && state == 0) {
    state = 1;
    m_1->Cancel();
    m_2->Schedule();
    m_3->Schedule();
  } else if (m_timer.Get() > 6 && state == 1) {
    state = 2;
    m_2->Cancel();
    // m_3->Schedule();
  } else if (m_timer.Get() > 6 && state == 2) {
    state = 3;
    m_3->Cancel();
    m_4->Schedule();
  } else if (m_timer.Get() > 8.5 && state == 3) {
    state = 4;
    m_4->Cancel();
    m_5->Schedule();
  } else if (m_timer.Get() > 8.5 && state == 4) {
    state = 5;
    m_6->Schedule();
    m_7->Schedule();
  } else if (m_timer.Get() > 9.5 && state == 5) {
    state = 6;
    m_5->Cancel();
    m_6->Cancel();
  } else if (m_timer.Get() > 9.5 && state == 6) {
    m_7->Cancel();
    m_8->Schedule();
  }*/

  switch (state) {
    case 0:
      if (m_timer.Get() > 3) {
        state++;
        m_1->Cancel();
        // m_2->Schedule();  // Shoot
        m_2_hood->Schedule();   // Shoot
        m_2_feed->Schedule();   // Shoot
        m_2_shoot->Schedule();  // Shoot
        m_3->Schedule();        // Change intake
      }
      break;
    case 1:
      if (m_timer.Get() > 8) {
        state++;
        // m_2->Cancel();
        m_2_hood->Cancel();
        m_2_feed->Cancel();
        m_2_shoot->Cancel();
        m_3->Cancel();
        m_4->Schedule();             // Reculer
        m_moveHoodZero->Schedule();  // Rétracter hood
      }
      break;
    case 2:
      if (m_timer.Get() > 10.5) {
        state++;
        m_4->Cancel();
        m_moveHoodZero->Cancel();
        m_5->Schedule();  // Change Intake
        m_6->Schedule();  // Avancer
        m_7->Schedule();  // PrepShoot
      }
      break;
    case 3:
      if (m_timer.Get() > 11.5) {
        state++;
        m_5->Cancel();
        m_6->Cancel();
        m_7->Cancel();
        m_8->Schedule();  // Shoot
      }
      break;

    default:
      break;
  }
}

void ComplexAuto::End(bool interrupted) {
  m_timer.Reset();
  m_timer.Stop();
  m_1->Cancel();
  // m_2->Cancel();
  m_2_hood->Cancel();
  m_2_feed->Cancel();
  m_2_shoot->Cancel();
  m_3->Cancel();
  m_4->Cancel();
  m_5->Cancel();
  m_6->Cancel();
  m_7->Cancel();
  m_8->Cancel();
  m_moveHoodZero->Cancel();
}

bool ComplexAuto::IsFinished() { return m_timer.Get() > 15; }
