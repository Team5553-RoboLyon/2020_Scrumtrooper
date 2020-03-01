#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

#include "Constants.h"

#include "subsystems/Feeder.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"

class Feed : public frc2::CommandHelper<frc2::CommandBase, Feed> {
 public:
  Feed(Feeder* feeder, Intake* intake, Shooter* shooter);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Feeder* m_feeder;
  Intake* m_intake;
  Shooter* m_shooter;
};
