/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/smartdashboard/SmartDashboard.h>
#include "subsystems/AdjustableHood.h"

AdjustableHood::AdjustableHood()
    : PIDSubsystem(
          frc2::PIDController(kAdjustableHoodPGain, kAdjustableHoodIGain, kAdjustableHoodDGain)) {
  m_encodeur.SetDistancePerRotation(kAdjustableHoodPositionConversionFactor);
  m_encodeur.Reset();
  GetController().SetTolerance(1);
  GetController().SetIntegratorRange(-0.03,0.03);
  Disable();
  m_lockedCount= 0;
}

void AdjustableHood::UseOutput(double output, double setpoint)
 {
   frc::SmartDashboard::PutNumber("volet encodeur Dist:",m_encodeur.GetDistance() );
    frc::SmartDashboard::PutNumber("volet setpoint:",setpoint );
    frc::SmartDashboard::PutNumber("volet output:",output );
    frc::SmartDashboard::PutNumber("Velocity error : ", GetController().GetVelocityError());
    frc::SmartDashboard::PutNumber("Distance restante :", abs(setpoint - m_encodeur.GetDistance()));


  /*if((abs(setpoint - m_encodeur.GetDistance()) > 1) && (abs(GetController().GetVelocityError()) < 1 ) && (output > 0.12))
  {
    //SetSetpoint(m_encodeur.GetDistance());
    frc::SmartDashboard::PutNumber("Hood security :", 1);
  } else {
    frc::SmartDashboard::PutNumber("Hood security :", 0);
  }*/

  if((abs(setpoint - m_encodeur.GetDistance()) > 1) && (abs(GetController().GetVelocityError()) < 1 ) && (abs(output) > 0.05)) 
  {
    m_lockedCount++;
    if(m_lockedCount > 8) {
      SetSetpoint(m_encodeur.GetDistance());
      GetController().Reset();
      m_lockedCount = 0;
    }
  } else {
    m_lockedCount = 0;
  }
  frc::SmartDashboard::PutNumber("Niveau de blocage :", m_lockedCount);
  m_prevVelocityError = GetController().GetVelocityError();

    m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, output);
}

double AdjustableHood::GetMeasurement() { return m_encodeur.GetDistance(); }

void AdjustableHood::ResetEncoder() { m_encodeur.Reset(); }

void AdjustableHood::Monter() {
  if (!IsEnabled()) m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.25);
}

void AdjustableHood::Descendre() {
  if (!IsEnabled()) m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.25);
}

void AdjustableHood::Unblock() {
  if (!IsEnabled()) m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.5);
}

void AdjustableHood::Stop() {
  if (!IsEnabled()) m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0);
}
