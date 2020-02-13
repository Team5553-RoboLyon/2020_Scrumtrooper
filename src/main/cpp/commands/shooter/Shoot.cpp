/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/shooter/Shoot.h"

#include <iostream>

Shoot::Shoot(double puissance, Shooter* shooter, Feeder* feeder, Drivetrain* drivetrain, Intake* intake, ControlPanelManipulator* controlPanelManipulator, Turret* turret, AdjustableHood* adjustableHood)
    : m_puissance(puissance),
      m_shooter(shooter), 
      m_feeder(feeder),
      m_drivetrain(drivetrain), 
      m_intake(intake), 
      m_controlPanelManipulator(controlPanelManipulator), 
      m_turret(turret),
      m_adjustableHood(adjustableHood) {
  AddRequirements(m_shooter);
  AddRequirements(m_feeder);
  AddRequirements(m_drivetrain);
  AddRequirements(m_intake);
  AddRequirements(m_controlPanelManipulator);
  AddRequirements(m_turret);
  AddRequirements(m_adjustableHood);
}

void Shoot::Initialize() {}

void Shoot::Execute() {
  m_feeder->Activate();
  m_drivetrain->Stop();
  m_intake->Close();
  m_controlPanelManipulator->Close();
  m_turret->Activate();
  m_adjustableHood->Activate();
  m_shooter->Shoot(m_puissance);
}

void Shoot::End(bool interrupted) {}

bool Shoot::IsFinished() { return false; }
