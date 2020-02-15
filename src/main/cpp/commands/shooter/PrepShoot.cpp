/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/shooter/PrepShoot.h"

#include <iostream>

PrepShoot::PrepShoot(double puissance, Shooter* Shooter, Conveyor* Conveyor, Feeder* Feeder, Drivetrain* Drivetrain, Intake* Intake, Controlpanel* Controlpanel, Turret* Turret, Hood* Hood)
    : m_feeder(Feeder), 
      m_conveyor(Conveyor), 
      m_shooter(Shooter), 
      m_drivetrain(Drivetrain), 
      m_intake(Intake), 
      m_controlpanel(Controlpanel), 
      m_turret(Turret),
      m_hood(Hood),
      m_puissance(puissance) {
  AddRequirements(m_shooter);
  AddRequirements(m_conveyor);
  AddRequirements(m_feeder);
  AddRequirements(m_drivetrain);
  AddRequirements(m_intake);
  AddRequirements(m_controlpanel);
  AddRequirements(m_turret);
  AddRequirements(Hood);
}

void PrepShoot::Initialize() {}

void PrepShoot::Execute() {
  m_drivetrain->Stop();
  m_intake->CloseIntake();
  m_controlpanel->CloseControlpanel();
  m_turret->Activate();
  m_hood->Activate();
  m_shooter->Shoot();
}

void PrepShoot::End(bool interrupted) {}

bool PrepShoot::IsFinished() { return false; }
