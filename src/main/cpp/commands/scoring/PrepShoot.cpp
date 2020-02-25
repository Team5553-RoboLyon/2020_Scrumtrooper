/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/PrepShoot.h"

PrepShoot::PrepShoot(double puissance, Shooter* shooter, Feeder* feeder, Drivetrain* drivetrain,
                     Intake* intake, ControlPanelManipulator* controlPanelManipulator,
                     Turret* turret, AdjustableHood* adjustableHood)
    : m_puissance(puissance),
      m_shooter(shooter),
      m_feeder(feeder),
      m_drivetrain(drivetrain),
      m_intake(intake),
      m_controlpanelmanipulator(controlPanelManipulator),
      m_turret(turret),
      m_adjustablehood(adjustableHood) {
  AddRequirements(m_shooter);
  AddRequirements(m_drivetrain);
  AddRequirements(m_intake);
  AddRequirements(m_controlpanelmanipulator);
  AddRequirements(m_turret);
  AddRequirements(m_adjustablehood);
}

void PrepShoot::Initialize() {
  m_drivetrain->Stop();
  m_intake->Close();
  m_controlpanelmanipulator->Close();
  m_adjustablehood->SetAngle(415.0);
  m_shooter->Shoot(m_puissance);
}

void PrepShoot::Execute() {}

void PrepShoot::End(bool interrupted) { m_shooter->Shoot(0.0); }

bool PrepShoot::IsFinished() { return false; }
