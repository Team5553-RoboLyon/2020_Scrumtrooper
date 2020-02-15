#include "commands/groups/ShootGroup.h"

double speed = 0.0;

ShootGroup::ShootGroup(Shooter* Shooter, Feeder* Feeder, Drivetrain* Drivetrain, Intake* Intake, ControlPanelManipulator* ControlPanelManipulator, Turret* Turret, AdjustableHood* AdjustableHood) {
  AddCommands(
    PrepShoot(speed, Shooter, Feeder, Drivetrain, Intake, ControlPanelManipulator, Turret, AdjustableHood),
    Shoot(speed, Shooter)
  );
}
