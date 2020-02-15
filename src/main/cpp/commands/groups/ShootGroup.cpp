#include "commands/groups/ShootGroup.h"

double speed = 0.0;

ShootGroup::ShootGroup(Shooter* Shooter, Conveyor* Conveyor, Feeder* Feeder, Drivetrain* Drivetrain, Intake* Intake, Controlpanel* Controlpanel, Turret* Turret, Hood* Hood) {
  AddCommands(
    PrepShoot(speed, Shooter, Conveyor, Feeder, Drivetrain, Intake, Controlpanel, Turret, Hood),
    Shoot(speed, Shooter)
  );
}
