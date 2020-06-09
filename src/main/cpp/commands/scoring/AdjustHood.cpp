/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/AdjustHood.h"

#include <networktables/NetworkTableInstance.h>

AdjustHood::AdjustHood(AdjustableHood* padjustableHood) : m_pAdjustableHood(padjustableHood) {
  AddRequirements(m_pAdjustableHood);

  m_ChameleonPitchEntry = nt::NetworkTableInstance::GetDefault()
                              .GetTable("chameleon-vision")
                              ->GetEntry("turret/targetPitch");
  m_ChameleonIsValidEntry = nt::NetworkTableInstance::GetDefault()
                                .GetTable("chameleon-vision")
                                ->GetEntry("turret/isValid");
}

void AdjustHood::Initialize() { m_pAdjustableHood->Enable(); }

void AdjustHood::Execute() {
  if (m_ChameleonIsValidEntry.GetBoolean(false)) {
    m_BufferPitch[m_BufferCount] = m_ChameleonPitchEntry.GetDouble(0);
  }
  m_BufferCount = (m_BufferCount + 1) % HOOD_BUFFER_SIZE;

  std::partial_sort_copy(&m_BufferPitch[0], &m_BufferPitch[HOOD_BUFFER_SIZE - 1],
                         &m_BufferPitchSorted[0], &m_BufferPitchSorted[HOOD_BUFFER_SIZE - 1]);
  if (std::abs(m_BufferPitchSorted[(int)(HOOD_BUFFER_SIZE / 2)]) < 2) {
    m_pAdjustableHood->SetClampedSetpoint(42);
  } else if (m_BufferPitchSorted[(int)(HOOD_BUFFER_SIZE / 2)] < -4) {
    m_pAdjustableHood->SetClampedSetpoint(45);
  } else if (m_BufferPitchSorted[(int)(HOOD_BUFFER_SIZE / 2)] < 0) {
    m_pAdjustableHood->SetClampedSetpoint(46);
  } else {
    double angle = 47.4 * std::exp(-m_BufferPitchSorted[(int)(HOOD_BUFFER_SIZE / 2)] / 51.1);
    m_pAdjustableHood->SetClampedSetpoint(angle);
  }
}

void AdjustHood::End(bool interrupted) {
  m_pAdjustableHood->Disable();
  m_pAdjustableHood->Stop();
}

bool AdjustHood::IsFinished() { return false; }
