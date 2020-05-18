/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"

class Drive : public frc2::CommandHelper<frc2::CommandBase, Drive> {
 public:
  Drive(std::function<double()> forward, std::function<double()> turn, Drivetrain* pdrivetrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  std::function<double()> m_Forward;
  std::function<double()> m_Turn;
  Drivetrain* m_pDrivetrain;
};
