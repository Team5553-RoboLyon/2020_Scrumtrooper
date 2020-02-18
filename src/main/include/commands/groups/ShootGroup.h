#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "commands/shooter/PrepShoot.h"
#include "commands/shooter/Shoot.h"

#include "subsystems/Shooter.h"
#include "subsystems/Feeder.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/ControlPanelManipulator.h"
#include "subsystems/Turret.h"
#include "subsystems/AdjustableHood.h"

class ShootGroup
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, ShootGroup> {
 public:
  ShootGroup(Shooter* Shooter, Feeder* Feeder, Drivetrain* Drivetrain, Intake* Intake, ControlPanelManipulator* ControlPanelManipulator, Turret* Turret, AdjustableHood* AdjustableHood, double m_puissance = 0.0);
 private:
  double speed = 0.0;
};
