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
#include "subsystems/Feeder.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/ControlPanelManipulator.h"
#include "subsystems/Turret.h"
#include "subsystems/AdjustableHood.h"

class PrepShoot : public frc2::CommandHelper<frc2::CommandBase, PrepShoot> {
 public:
  PrepShoot(double puissance, Shooter* shooter, Feeder* Feeder, Drivetrain* Drivetrain, Intake* Intake, ControlPanelManipulator* ControlPanelManipulator, Turret* Turret, AdjustableHood* AdjustableHood);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Shooter* m_shooter;
  Feeder* m_feeder;
  Drivetrain* m_drivetrain;
  Intake* m_intake;
  ControlPanelManipulator* m_controlpanelmanipulator;
  Turret* m_turret;
  AdjustableHood* m_adjustablehood;
  double m_puissance = 0.0;
};
