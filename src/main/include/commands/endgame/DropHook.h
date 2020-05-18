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
#include "subsystems/Intake.h"
#include "subsystems/TelescopicArm.h"

class DropHook : public frc2::CommandHelper<frc2::CommandBase, DropHook> {
 public:
  DropHook(TelescopicArm* ptelescopic_arm, Intake* pintake, Drivetrain* pdrivetrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  TelescopicArm* m_pTelescopicArm;
  Intake* m_pIntake;
  Drivetrain* m_pDrivetrain;
};
