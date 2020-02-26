#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

#include "Constants.h"

#include "subsystems/Feeder.h"

class FeederUnblock : public frc2::CommandHelper<frc2::CommandBase, FeederUnblock> {
 public:
  FeederUnblock(Feeder* feeder);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Feeder* m_feeder;
};
