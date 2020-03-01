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

void MoveTurret::Initialize() {
  m_turret->Enable();
  m_turret->StartLedRing();
}

void MoveTurret::Execute() {
  m_bufferIsValid[m_bufferCount] = m_chameleonIsValidEntry.GetBoolean(false);
  std::partial_sort_copy(&m_bufferIsValid[0], &m_bufferIsValid[14], &m_bufferIsValidSorted[0],
                         &m_bufferIsValidSorted[14]);

  if (m_bufferIsValid[m_bufferCount]) {
    m_bufferYaw[m_bufferCount] = m_chameleonYawEntry.GetDouble(0);
  } else {
    m_bufferYaw[m_bufferCount] = 0;
  }

  m_bufferCount = (m_bufferCount + 1) % 15;

  if (m_bufferIsValidSorted[7]) {
    std::partial_sort_copy(&m_bufferYaw[0], &m_bufferYaw[14], &m_bufferYawSorted[0],
                           &m_bufferYawSorted[14]);
    m_turret->SetClampedSetpoint(m_turret->GetMeasurement() + m_bufferYawSorted[7]);
  } else {
    m_turret->SetClampedSetpoint(0.0);
  }
  std::cout << m_chameleonIsValidEntry.GetBoolean(false) << "  " << m_bufferIsValidSorted[7] << "  "
            << m_chameleonYawEntry.GetDouble(0) << "  " << m_bufferYawSorted[7] << "  "
            << m_turret->GetMeasurement() + m_bufferYawSorted[7] << std::endl;
}

void MoveTurret::End(bool interrupted) {
  m_turret->Disable();
  m_turret->Stop();
  m_turret->StopLedRing();
}

bool MoveTurret::IsFinished() { return false; }
