#include "commands/groups/ShootGroup.h"

#include <frc2/command/ParallelCommandGroup.h>

ShootGroup::ShootGroup(Shooter* Shooter, Feeder* Feeder, Drivetrain* Drivetrain, Intake* Intake,
                       ControlPanelManipulator* ControlPanelManipulator, Turret* Turret,
                       AdjustableHood* AdjustableHood, double m_puissance) {
  speed = 0.8;
  AddCommands(PrepShoot(speed, Shooter, Feeder, Drivetrain, Intake, ControlPanelManipulator, Turret,
                        AdjustableHood),
              frc2::ParallelCommandGroup(Shoot(speed, Shooter), Feed(Feeder)));
}
