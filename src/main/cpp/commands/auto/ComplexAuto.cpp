/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/ComplexAuto.h"

#include <frc2/command/ParallelCommandGroup.h>

ComplexAuto::ComplexAuto(Shooter* pshooter, Turret* pturret, AdjustableHood* padjustable_hood,
                         Feeder* pfeeder, Intake* pintake, Drivetrain* pdrivetrain) {
  m_pPrepShootGroup = new frc2::ParallelCommandGroup(PrepShoot(pshooter), AdjustTurret(pturret));
  m_pAdjustHood = new AdjustHood(padjustable_hood);
  m_pShoot = new Shoot(pshooter);
  m_pFeed = new Feed(pfeeder, pintake, pshooter, false);
  m_pChangeIntakePosition = new ChangeIntakePosition(pintake);
  m_pGoReverse = new frc2::ParallelCommandGroup(AutoDrive(pdrivetrain, 17000), TakeCell(pintake));
  m_pGoForward = new AutoDrive(pdrivetrain, -10000);
  m_pShootGroup = new frc2::ParallelCommandGroup(AdjustHood(padjustable_hood), Shoot(pshooter),
                                                 Feed(pfeeder, pintake, pshooter));
  m_pMoveHoodZero = new MoveHood(padjustable_hood, 0);
}

void ComplexAuto::Initialize() {
  m_State = 0;
  m_pPrepShootGroup->Schedule();
  m_Timer.Reset();
  m_Timer.Start();
}

void ComplexAuto::Execute() {
  switch (m_State) {
    case 0:
      if (m_Timer.Get() > 3) {
        m_State++;
        m_pPrepShootGroup->Cancel();
        m_pAdjustHood->Schedule();
        m_pFeed->Schedule();
        m_pShoot->Schedule();
        m_pChangeIntakePosition->Schedule();
      }
      break;
    case 1:
      if (m_Timer.Get() > 8) {
        m_State++;
        m_pAdjustHood->Cancel();
        m_pFeed->Cancel();
        m_pShoot->Cancel();
        m_pChangeIntakePosition->Cancel();
        m_pGoReverse->Schedule();
        m_pMoveHoodZero->Schedule();
      }
      break;
    case 2:
      if (m_Timer.Get() > 10.5) {
        m_State++;
        m_pGoReverse->Cancel();
        m_pMoveHoodZero->Cancel();
        m_pChangeIntakePosition->Schedule();
        m_pGoForward->Schedule();
        m_pPrepShootGroup->Schedule();
      }
      break;
    case 3:
      if (m_Timer.Get() > 11.5) {
        m_State++;
        m_pChangeIntakePosition->Cancel();
        m_pGoForward->Cancel();
        m_pPrepShootGroup->Cancel();
        m_pShootGroup->Schedule();
      }
      break;

    default:
      break;
  }
}

void ComplexAuto::End(bool interrupted) {
  m_Timer.Reset();
  m_Timer.Stop();

  m_pPrepShootGroup->Cancel();
  m_pShootGroup->Cancel();
  m_pAdjustHood->Cancel();
  m_pFeed->Cancel();
  m_pShoot->Cancel();
  m_pChangeIntakePosition->Cancel();
  m_pGoReverse->Cancel();
  m_pGoForward->Cancel();
  m_pMoveHoodZero->Cancel();
}

bool ComplexAuto::IsFinished() { return m_Timer.Get() > 15; }
