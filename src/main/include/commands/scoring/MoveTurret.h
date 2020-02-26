/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <networktables/NetworkTableEntry.h>

#include "subsystems/Turret.h"

class MoveTurret : public frc2::CommandHelper<frc2::CommandBase, MoveTurret> {
 public:
  MoveTurret(Turret* turret);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Turret* m_turret;
  nt::NetworkTableEntry m_chameleonYawEntry;
  nt::NetworkTableEntry m_chameleonIsValidEntry;
  double m_bufferYaw[15] = {0};
  double m_bufferYawSorted[15] = {0};
  bool m_bufferIsValid[15] = {1};
  bool m_bufferIsValidSorted[15] = {1};
  unsigned int m_bufferCount;
};
