#include "commands/scoring/ShootGroup.h"

#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/ParallelRaceGroup.h>

#include "commands/scoring/PrepShoot.h"
#include "commands/scoring/Feed.h"
#include "commands/scoring/Shoot.h"
#include "commands/scoring/MoveTurret.h"

ShootGroup::ShootGroup(Shooter* shooter, Feeder* feeder, Drivetrain* drivetrain, Intake* intake,
                       ControlPanelManipulator* controlPanelManipulator, Turret* turret,
                       AdjustableHood* adjustableHood, double puissance) {
  AddCommands(frc2::ParallelCommandGroup(PrepShoot(puissance, shooter, feeder, drivetrain, intake,
                                                   controlPanelManipulator, adjustableHood),
                                         MoveTurret(turret))
                  .WithTimeout(3_s),
              frc2::ParallelCommandGroup(Shoot(puissance, shooter), Feed(feeder, intake)));
}
