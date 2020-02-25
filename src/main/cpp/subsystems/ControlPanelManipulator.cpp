/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ControlPanelManipulator.h"

ControlPanelManipulator::ControlPanelManipulator() { Close(); }

void ControlPanelManipulator::Open() {
  // m_solenoid.Set(frc::DoubleSolenoid::Value::kForward);
}

void ControlPanelManipulator::Close() {
  Stop();
  // m_solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
}

void ControlPanelManipulator::ChangePosition() {
  if (m_position == ControlPanelManipulatorPosition::kOpened) Close();
  if (m_position == ControlPanelManipulatorPosition::kClosed) Open();
}

void ControlPanelManipulator::Activate() {
  if (m_position == ControlPanelManipulatorPosition::kClosed) return;
  m_moteur.Set(kIntakeMoteurSpeed);
}

void ControlPanelManipulator::Stop() { m_moteur.StopMotor(); }