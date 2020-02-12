/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

Intake::Intake() {
    CloseIntake();
}

void Intake::OpenIntake() {
    m_solenoid.Set(frc::DoubleSolenoid::Value::kForward);
}
void Intake::CloseIntake() {
    Stop();
    m_solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
}

void Intake::ChangeIntakePosition() {
    if(m_position == IntakePosition::kOpened) CloseIntake();
    if(m_position == IntakePosition::kClosed) OpenIntake();
}

void Intake::Activate() {
    if(m_position == IntakePosition::kClosed) return;
    m_moteur.Set(kIntakeMoteurSpeed);
}

void Intake::Stop() {
    m_moteur.StopMotor();
}