/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/shooter/Shoot.h"

#include <iostream>

Shoot::Shoot(double puissance, Shooter* Shooter, Convoyer* Convoyer, Feeder* Feeder, Drivetrain* Drivetrain, Intake* Intake, Controlpanel* Controlpanel, Turret* Turret, Hood* Hood)
    : m_puissance(puissance), 
      m_feeder(Feeder), 
      m_convoyer(Convoyer), 
      m_shooter(Shooter), 
      m_drivetrain(Drivetrain), 
      m_intake(Intake), 
      m_controlpanel(Controlpanel), 
      m_turret(Turret),
      m_hood(Hood) {
  AddRequirements(m_shooter);
  AddRequirements(m_convoyer);
  AddRequirements(m_feeder);
  AddRequirements(m_drivetrain);
  AddRequirements(m_intake);
  AddRequirements(m_controlpanel);
  AddRequirements(m_turret);
  AddRequirements(Hood);
}

void Shoot::Initialize() {}

void Shoot::Execute() {
  m_convoyer->Activate();
  m_feeder->Activate();
  m_drivetrain->Stop();
  m_intake->CloseIntake();
  m_controlpanel->CloseControlpanel();
  m_turret->Activate();
  m_hood->Activate();
  m_shooter->Shoot(m_puissance);
}

void Shoot::End(bool interrupted) {}

bool Shoot::IsFinished() { return false; }
