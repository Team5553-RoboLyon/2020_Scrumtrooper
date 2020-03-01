/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/MoveTurret.h"

#include <networktables/NetworkTableInstance.h>

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

void MoveTurret::Initialize() {
  m_turret->Enable();
  m_turret->StartLedRing();
}

void MoveTurret::Execute() {
  if (m_chameleonIsValidEntry.GetBoolean(false)) {
    m_bufferYaw[m_bufferCount] = m_chameleonYawEntry.GetDouble(0);
  }
  m_bufferCount = (m_bufferCount + 1) % BUFFER_SIZE;

  std::partial_sort_copy(&m_bufferYaw[0], &m_bufferYaw[BUFFER_SIZE - 1], &m_bufferYawSorted[0],
                         &m_bufferYawSorted[BUFFER_SIZE - 1]);
  m_turret->SetClampedSetpoint(m_turret->GetMeasurement() +
                               m_bufferYawSorted[(int)(BUFFER_SIZE / 2)]);
}

void MoveTurret::End(bool interrupted) {}

bool MoveTurret::IsFinished() { return false; }
