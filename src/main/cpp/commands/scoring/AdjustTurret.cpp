/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/AdjustTurret.h"

#include <networktables/NetworkTableInstance.h>

AdjustTurret::AdjustTurret(Turret* pturret) : m_pTurret(pturret) {
  AddRequirements(m_pTurret);
  m_ChameleonYawEntry = nt::NetworkTableInstance::GetDefault()
                            .GetTable("chameleon-vision")
                            ->GetEntry("turret/targetYaw");
  m_ChameleonIsValidEntry = nt::NetworkTableInstance::GetDefault()
                                .GetTable("chameleon-vision")
                                ->GetEntry("turret/isValid");
  m_BufferCount = 0;
}

void AdjustTurret::Initialize() { m_pTurret->Enable(); }

void AdjustTurret::Execute() {
  if (m_ChameleonIsValidEntry.GetBoolean(false)) {
    m_BufferYaw[m_BufferCount] = m_ChameleonYawEntry.GetDouble(0);
  }
  m_BufferCount = (m_BufferCount + 1) % BUFFER_SIZE;

  std::partial_sort_copy(&m_BufferYaw[0], &m_BufferYaw[BUFFER_SIZE - 1], &m_BufferYawSorted[0],
                         &m_BufferYawSorted[BUFFER_SIZE - 1]);
  m_pTurret->SetClampedSetpoint(m_pTurret->GetMeasurement() +
                                m_BufferYawSorted[(int)(BUFFER_SIZE / 2)]);
}

void AdjustTurret::End(bool interrupted) {}

bool AdjustTurret::IsFinished() { return false; }
