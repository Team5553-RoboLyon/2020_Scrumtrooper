#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "commands/shooter/PrepShoot.h"
#include "commands/shooter/Shoot.h"

#include "subsystems/Shooter.h"
#include "subsystems/Conveyor.h"
#include "subsystems/Feeder.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Controlpanel.h"
#include "subsystems/Turret.h"
#include "subsystems/Hood.h"

class ShootGroup
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, ShootGroup> {
 public:
  ShootGroup(Shooter* Shooter, Conveyor* Conveyor, Feeder* Feeder, Drivetrain* Drivetrain, Intake* Intake, Controlpanel* Controlpanel, Turret* Turret, Hood* Hood);
};
