/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/TelescopicArm.h"
#include "subsystems/Intake.h"
#include "subsystems/Drivetrain.h"

class RaiseHook : public frc2::CommandHelper<frc2::CommandBase, RaiseHook> {
 public:
  RaiseHook(TelescopicArm* telescopicArm, Intake* intake, Drivetrain* drivetrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  TelescopicArm* m_telescopicarm;
  Intake* m_intake;
  Drivetrain* m_drivetrain;
};
