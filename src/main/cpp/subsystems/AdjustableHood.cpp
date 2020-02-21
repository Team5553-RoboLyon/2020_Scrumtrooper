/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/AdjustableHood.h"

AdjustableHood::AdjustableHood() {
  m_actualAngle = 0.0;
  m_integral = 0.0;
  m_prev_error = 0.0;
}

void AdjustableHood::Close() {
  SetAngle(0.0);
  m_isOpened = false;
}

void AdjustableHood::Monter() {
  m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.25);
}

void AdjustableHood::Descendre() {
  m_moteur.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.25);
}

void AdjustableHood::SetAngle(double angle) {
  /*if(!m_isActivated) return;
  double error = angle - m_encodeur.Get();
  m_integral += (error*.02);
  double derivative = (error - m_prev_error) / .02;
  double rcw = 0.0025*error + 0.00023*m_integral + 0.0003*derivative;
  //Precédement I = 0.00021

  m_actualAngle = 0.0;

  m_prev_error = error;
  m_isOpened = true;*/
}