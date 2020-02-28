/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc2/command/CommandScheduler.h>
#include "cameraserver/CameraServer.h"

void Robot::RobotInit() { frc::CameraServer::GetInstance()->StartAutomaticCapture(); }

void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

void Robot::DisabledInit() {
  m_container.m_drivetrain.EnableLogFile(false);
  m_container.m_drivetrain.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

void Robot::DisabledPeriodic() {}

void Robot::AutonomousInit() { m_container.m_adjustableHood.ResetEncoder(); }

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  m_container.m_drivetrain.EnableLogFile(false);
  m_container.m_intake.Close();
  m_container.m_drivetrain.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_container.m_adjustableHood.ResetEncoder();
}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
