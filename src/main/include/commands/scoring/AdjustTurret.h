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

#define BUFFER_SIZE 3

class AdjustTurret : public frc2::CommandHelper<frc2::CommandBase, AdjustTurret> {
 public:
  explicit AdjustTurret(Turret* pturret);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Turret* m_pTurret;
  nt::NetworkTableEntry m_ChameleonYawEntry;
  nt::NetworkTableEntry m_ChameleonIsValidEntry;
  double m_BufferYaw[BUFFER_SIZE] = {0};
  double m_BufferYawSorted[BUFFER_SIZE] = {0};
  unsigned int m_BufferCount;
};
