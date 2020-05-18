/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc2/command/CommandScheduler.h>

#include <cameraserver/CameraServer.h>

void Robot::RobotInit() {
  m_Camera = frc::CameraServer::GetInstance()->StartAutomaticCapture();
  m_Camera.SetResolution(320, 240);
  m_Camera.SetFPS(12);
}

void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

void Robot::DisabledInit() {
  m_Container.m_Drivetrain.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  // Remet à zéro le controlleur le PID ( dont le setpoint ) du volet
  m_Container.m_AdjustableHood.Disable();
}

void Robot::DisabledPeriodic() {}

void Robot::AutonomousInit() {
  m_Container.m_Intake.Close();
  m_Container.m_Drivetrain.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_Container.m_AdjustableHood.ResetEncoder();
  m_Container.m_TelescopicArm.ResetEncoder();
  m_pAutonomousCommand = m_Container.GetAutonomousCommand();

  if (m_pAutonomousCommand != nullptr) {
    m_pAutonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  /*m_Container.m_intake.Close();
  m_Container.m_drivetrain.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_Container.m_adjustableHood.ResetEncoder();
  m_Container.m_telescopicArm.ResetEncoder();*/
  if (m_pAutonomousCommand != nullptr) {
    m_pAutonomousCommand->Cancel();
    m_pAutonomousCommand = nullptr;
  }
}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
