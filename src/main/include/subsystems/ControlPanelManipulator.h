#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>
#include <frc/VictorSP.h>

#include "Constants.h"

class ControlPanelManipulator : public frc2::SubsystemBase {
 public:
  enum class ControlPanelManipulatorPosition { kOpened, kClosed };

  ControlPanelManipulator();

  void Open();
  void Close();
  void ChangePosition();
  void Activate();
  void Stop();

 private:
  frc::VictorSP m_moteur{kControlPanelManipulatorMoteur};
  frc::DoubleSolenoid m_solenoid{kControlPanelManipulatorA, kControlPanelManipulatorB};
  ControlPanelManipulatorPosition m_position;
};