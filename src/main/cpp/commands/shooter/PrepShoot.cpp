/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/shooter/PrepShoot.h"

#include <iostream>

PrepShoot::PrepShoot(double puissance, Shooter* Shooter, Feeder* Feeder, Drivetrain* Drivetrain, Intake* Intake, ControlPanelManipulator* ControlPanelManipulator, Turret* Turret, AdjustableHood* AdjustableHood)
    : m_feeder(Feeder), 
      m_shooter(Shooter), 
      m_drivetrain(Drivetrain), 
      m_intake(Intake), 
      m_controlpanelmanipulator(ControlPanelManipulator), 
      m_turret(Turret),
      m_adjustablehood(AdjustableHood),
      m_puissance(puissance) {
  AddRequirements(m_shooter);
  AddRequirements(m_feeder);
  AddRequirements(m_drivetrain);
  AddRequirements(m_intake);
  AddRequirements(m_controlpanelmanipulator);
  AddRequirements(m_turret);
  AddRequirements(m_adjustablehood);
}

void PrepShoot::Initialize() {}

void PrepShoot::Execute() {
  m_drivetrain->Stop();
  m_intake->Close();
  m_controlpanelmanipulator->Close();
  m_turret->Activate();
  m_adjustablehood->Activate();
  m_shooter->Shoot(m_puissance);
}

void PrepShoot::End(bool interrupted) {}

bool PrepShoot::IsFinished() { return false; }
