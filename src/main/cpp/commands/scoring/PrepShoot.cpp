/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/PrepShoot.h"

#include "networktables/NetworkTableInstance.h"

PrepShoot::PrepShoot(double puissance, Shooter* shooter, Feeder* feeder, Drivetrain* drivetrain,
                     Intake* intake, ControlPanelManipulator* controlPanelManipulator,
                     AdjustableHood* adjustableHood)
    : m_puissance(puissance),
      m_shooter(shooter),
      m_feeder(feeder),
      m_drivetrain(drivetrain),
      m_intake(intake),
      m_controlpanelmanipulator(controlPanelManipulator),
      m_adjustablehood(adjustableHood) {
  m_chameleonPitchEntry = nt::NetworkTableInstance::GetDefault()
                              .GetTable("chameleon-vision")
                              ->GetEntry("turret/targetPitch");
  m_chameleonIsValidEntry = nt::NetworkTableInstance::GetDefault()
                                .GetTable("chameleon-vision")
                                ->GetEntry("turret/isValid");
  AddRequirements(m_shooter);
}

void PrepShoot::Initialize() {}

void PrepShoot::Execute() {
  double m_pitch = m_chameleonPitchEntry.GetDouble(0.0);
  // Calcul
  
  m_puissance = m_pitch*m_pitch*0.0252 + m_pitch * 0.215 + 1.27;
  
  m_shooter->Shoot(m_puissance);
}

void PrepShoot::End(bool interrupted) { m_shooter->Shoot(0.0); }

bool PrepShoot::IsFinished() { return false; }
