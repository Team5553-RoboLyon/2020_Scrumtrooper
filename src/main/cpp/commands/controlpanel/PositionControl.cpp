/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/controlpanel/PositionControl.h"

PositionControl::PositionControl(ControlPanelManipulator* controlPanelManipulator)
    : m_controlPanelManipulator(controlPanelManipulator) {
  AddRequirements(m_controlPanelManipulator);
}

void PositionControl::Initialize() {}

void PositionControl::Execute() { m_controlPanelManipulator->ChangePosition(); }

void PositionControl::End(bool interrupted) {}

bool PositionControl::IsFinished() { return false; }
