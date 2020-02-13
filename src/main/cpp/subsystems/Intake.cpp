/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

Intake::Intake() {
    Close();
}

void Intake::Open() {
    m_solenoid.Set(frc::DoubleSolenoid::Value::kForward);
}
void Intake::Close() {
    Stop();
    m_solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
}

void Intake::ChangePosition() {
    if(m_position == IntakePosition::kOpened) Close();
    if(m_position == IntakePosition::kClosed) Open();
}

void Intake::Activate() {
    if(m_position == IntakePosition::kClosed) return;
    m_moteur.Set(kIntakeMoteurSpeed);
}

void Intake::Stop() {
    m_moteur.StopMotor();
}