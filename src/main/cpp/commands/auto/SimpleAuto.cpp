/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/SimpleAuto.h"

#include <frc2/command/ParallelCommandGroup.h>

#include "commands/scoring/AdjustHood.h"

SimpleAuto::SimpleAuto(Shooter* pshooter, Turret* pturret, AdjustableHood* padjustable_hood,
                       Feeder* pfeeder, Intake* pintake, Drivetrain* pdrivetrain) {
  m_pPrepShootGroup = new frc2::ParallelCommandGroup(PrepShoot(pshooter), AdjustTurret(pturret));
  m_pShootGroup = new frc2::ParallelCommandGroup(AdjustHood(padjustable_hood), Shoot(pshooter),
                                                 Feed(pfeeder, pintake, pshooter));
  m_pGoReverse = new AutoDrive(pdrivetrain, 1500);
}

void SimpleAuto::Initialize() {
  m_State = 0;
  m_pPrepShootGroup->Schedule();
  m_Timer.Reset();
  m_Timer.Start();
}

void SimpleAuto::Execute() {
  switch (m_State) {
    case 0:
      if (m_Timer.Get() > 3) {
        m_State++;
        m_pPrepShootGroup->Cancel();
        m_pShootGroup->Schedule();
      }
      break;
    case 1:
      if (m_Timer.Get() > 12) {
        m_State++;
        m_pShootGroup->Cancel();
        m_pGoReverse->Schedule();
      }
      break;
    case 2:
      if (m_Timer.Get() > 12.6) {
        m_pGoReverse->Cancel();
      }
      break;
    default:
      break;
  }
}

void SimpleAuto::End(bool interrupted) {
  m_Timer.Reset();
  m_Timer.Stop();

  m_pPrepShootGroup->Cancel();
  m_pShootGroup->Cancel();
  m_pGoReverse->Cancel();
}

bool SimpleAuto::IsFinished() { return m_Timer.Get() > 15; }
