/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/AdjustHood.h"
#include <networktables/NetworkTableInstance.h>
#include <iostream>

AdjustHood::AdjustHood(AdjustableHood* adjustableHood) : m_adjustablehood(adjustableHood) {
  AddRequirements(m_adjustablehood);

  m_chameleonPitchEntry = nt::NetworkTableInstance::GetDefault()
                              .GetTable("chameleon-vision")
                              ->GetEntry("turret/targetPitch");
  m_chameleonIsValidEntry = nt::NetworkTableInstance::GetDefault()
                                .GetTable("chameleon-vision")
                                ->GetEntry("turret/isValid");
}

void AdjustHood::Initialize() { m_adjustablehood->Enable(); }

void AdjustHood::Execute() {
  if (m_chameleonIsValidEntry.GetBoolean(false)) {
    m_bufferPitch[m_bufferCount] = m_chameleonPitchEntry.GetDouble(0);
  }
  m_bufferCount = (m_bufferCount + 1) % HOOD_BUFFER_SIZE;

  std::partial_sort_copy(&m_bufferPitch[0], &m_bufferPitch[HOOD_BUFFER_SIZE - 1],
                         &m_bufferPitchSorted[0], &m_bufferPitchSorted[HOOD_BUFFER_SIZE - 1]);

  if (m_bufferPitchSorted[(int)(HOOD_BUFFER_SIZE / 2)] < 0) {
    m_adjustablehood->SetClampedSetpoint(46);
  } else {
    double angle = 46 * std::exp(-m_bufferPitchSorted[(int)(HOOD_BUFFER_SIZE / 2)] / 72);
    m_adjustablehood->SetClampedSetpoint(angle);
  }
}

void AdjustHood::End(bool interrupted) {
  m_adjustablehood->Disable();
  m_adjustablehood->Stop();
}

bool AdjustHood::IsFinished() { return false; }
