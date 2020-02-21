#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Shooter.h"
#include "subsystems/Feeder.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/ControlPanelManipulator.h"
#include "subsystems/Turret.h"
#include "subsystems/AdjustableHood.h"

class ShootGroup : public frc2::CommandHelper<frc2::SequentialCommandGroup, ShootGroup> {
 public:
  ShootGroup(Shooter* shooter, Feeder* feeder, Drivetrain* drivetrain, Intake* intake,
             ControlPanelManipulator* controlPanelManipulator, Turret* turret,
             AdjustableHood* adjustableHood, double puissance = 0.8);
};
