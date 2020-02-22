#include "commands/scoring/ShootGroup.h"

#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/ParallelRaceGroup.h>

#include "commands/scoring/PrepShoot.h"
#include "commands/scoring/Feed.h"
#include "commands/scoring/Shoot.h"

ShootGroup::ShootGroup(Shooter* shooter, Feeder* feeder, Drivetrain* drivetrain, Intake* intake,
                       ControlPanelManipulator* controlPanelManipulator, Turret* turret,
                       AdjustableHood* adjustableHood, double puissance) {
  AddCommands(PrepShoot(puissance, shooter, feeder, drivetrain, intake, controlPanelManipulator,
                        turret, adjustableHood)
                  .WithTimeout(1_s),
              frc2::ParallelCommandGroup(Shoot(puissance, shooter), Feed(feeder)));
}
