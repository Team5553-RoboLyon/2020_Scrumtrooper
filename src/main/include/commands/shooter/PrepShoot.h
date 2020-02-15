/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"
#include "subsystems/Conveyor.h"
#include "subsystems/Feeder.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Controlpanel.h"
#include "subsystems/Turret.h"
#include "subsystems/Hood.h"

class PrepShoot : public frc2::CommandHelper<frc2::CommandBase, PrepShoot> {
 public:
  PrepShoot(double puissance, Shooter* shooter, Conveyor* Conveyor, Feeder* Feeder, Drivetrain* Drivetrain, Intake* Intake, Controlpanel* Controlpanel, Turret* Turret, Hood* Hood);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Shooter* m_shooter;
  Feeder* m_feeder;
  Conveyor* m_conveyor;
  Drivetrain* m_drivetrain;
  Intake* m_intake;
  Controlpanel* m_controlpanel;
  Turret* m_turret;
  Hood* m_hood;
  double m_puissance = 0.0;
};
