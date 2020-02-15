/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/controlPanelManipulator/RotationControl.h"

RotationControl::RotationControl(ControlPanelManipulator* controlPanelManipulator)
    : m_controlPanelManipulator(controlPanelManipulator) {
  AddRequirements(m_controlPanelManipulator);
}

void RotationControl::Initialize() {}

void RotationControl::Execute() {
}

void RotationControl::End(bool interrupted) {}

bool RotationControl::IsFinished() { return false; }
