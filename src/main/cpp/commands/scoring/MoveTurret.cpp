/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/MoveTurret.h"

#include <networktables/NetworkTableInstance.h>
#include <iostream>

MoveTurret::MoveTurret(Turret* turret) : m_turret(turret) {
  AddRequirements(m_turret);
  m_chameleonYawEntry = nt::NetworkTableInstance::GetDefault()
                            .GetTable("chameleon-vision")
                            ->GetEntry("turret/targetYaw");
  m_chameleonIsValidEntry = nt::NetworkTableInstance::GetDefault()
                                .GetTable("chameleon-vision")
                                ->GetEntry("turret/isValid");
  m_bufferCount = 0;
}

void MoveTurret::Initialize() { m_turret->Enable(); }

void MoveTurret::Execute() {
  if (m_chameleonIsValidEntry.GetBoolean(false)) {
    m_buffer[m_bufferCount] = m_chameleonYawEntry.GetDouble(0);
  } else {
    m_buffer[m_bufferCount] = 0;
  }
  m_bufferCount = (m_bufferCount + 1) % 15;
  std::partial_sort_copy(&m_buffer[0], &m_buffer[14], &m_bufferSorted[0], &m_bufferSorted[14]);
  std::cout << m_buffer[7] << std::endl;
  m_turret->SetClampedSetpoint(m_turret->GetMeasurement() + m_buffer[3]);
}

void MoveTurret::End(bool interrupted) {
  m_turret->Disable();
  m_turret->Stop();
}

bool MoveTurret::IsFinished() { return false; }
