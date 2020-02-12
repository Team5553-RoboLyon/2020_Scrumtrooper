/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Controlpanel.h"

Controlpanel::Controlpanel() {
    CloseControlpanel();
}

void Controlpanel::OpenControlpanel() {
    m_solenoid.Set(frc::DoubleSolenoid::Value::kForward);
}

void Controlpanel::CloseControlpanel() {
    Stop();
    m_solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
}

void Controlpanel::ChangeControlpanelPosition() {
    if(m_position == ControlpanelPosition::kOpened) CloseControlpanel();
    if(m_position == ControlpanelPosition::kClosed) OpenControlpanel();
}

void Controlpanel::Activate() {
    if(m_position == ControlpanelPosition::kClosed) return;
    m_moteur.Set(kIntakeMoteurSpeed);
}

void Controlpanel::Stop() {
    m_moteur.StopMotor();
}