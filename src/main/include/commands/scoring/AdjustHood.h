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

#include "subsystems/AdjustableHood.h"

#define HOOD_BUFFER_SIZE 3

class AdjustHood : public frc2::CommandHelper<frc2::CommandBase, AdjustHood> {
 public:
  explicit AdjustHood(AdjustableHood* padjustable_hood);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  AdjustableHood* m_pAdjustableHood;

  nt::NetworkTableEntry m_ChameleonPitchEntry;
  nt::NetworkTableEntry m_ChameleonIsValidEntry;
  double m_BufferPitch[HOOD_BUFFER_SIZE] = {0};
  double m_BufferPitchSorted[HOOD_BUFFER_SIZE] = {0};
  unsigned int m_BufferCount;
};
