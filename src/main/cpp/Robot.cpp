/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

void Robot::RobotInit() {
  /*camera.set(cv::CAP_PROP_BRIGHTNESS, 0);
camera.set(cv::CAP_PROP_FRAME_WIDTH, 320);
  camera.set(cv::CAP_PROP_FRAME_HEIGHT, 240);
  camera.set(cv::CAP_PROP_FPS, 30);

outputStream = frc::CameraServer::GetInstance()->PutVideo("Pince Arriere", 320, 240);*/
}

void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();

  /*camera.read(source);
  source.convertTo(source, -1, 3, 0.3);
  outputStream.PutFrame(source);*/
}

void Robot::DisabledInit() {
  m_container.m_drivetrain.EnableLogFile(false);
  m_container.m_drivetrain.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

void Robot::DisabledPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() { m_container.m_drivetrain.EnableLogFile(false); }

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
