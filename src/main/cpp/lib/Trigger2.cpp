/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "lib/Trigger2.h"

#include <frc2/command/InstantCommand.h>

using namespace frc2;

Trigger2::Trigger2(const Trigger2& other) : m_isActive(other.m_isActive) {}

Trigger2 Trigger2::WhenActive(Command* command, bool interruptible) {
  CommandScheduler::GetInstance().AddButton(
      [pressedLast = m_isActive(), *this, command, interruptible]() mutable {
        bool pressed = m_isActive();

        if (!pressedLast && pressed) {
          command->Schedule(interruptible);
        }

        pressedLast = pressed;
      });

  return *this;
}

Trigger2 Trigger2::WhenActive(std::function<void()> toRun,
                              std::initializer_list<Subsystem*> requirements) {
  return WhenActive(std::move(toRun), wpi::makeArrayRef(requirements.begin(), requirements.end()));
}

Trigger2 Trigger2::WhenActive(std::function<void()> toRun, wpi::ArrayRef<Subsystem*> requirements) {
  return WhenActive(InstantCommand(std::move(toRun), requirements));
}

Trigger2 Trigger2::WhileActiveContinous(Command* command, bool interruptible) {
  CommandScheduler::GetInstance().AddButton(
      [pressedLast = m_isActive(), *this, command, interruptible]() mutable {
        bool pressed = m_isActive();

        if (pressed) {
          command->Schedule(interruptible);
        } else if (pressedLast && !pressed) {
          command->Cancel();
        }

        pressedLast = pressed;
      });
  return *this;
}

Trigger2 Trigger2::WhileActiveContinous(std::function<void()> toRun,
                                        std::initializer_list<Subsystem*> requirements) {
  return WhileActiveContinous(std::move(toRun),
                              wpi::makeArrayRef(requirements.begin(), requirements.end()));
}

Trigger2 Trigger2::WhileActiveContinous(std::function<void()> toRun,
                                        wpi::ArrayRef<Subsystem*> requirements) {
  return WhileActiveContinous(InstantCommand(std::move(toRun), requirements));
}

Trigger2 Trigger2::WhileActiveOnce(Command* command, bool interruptible) {
  CommandScheduler::GetInstance().AddButton(
      [pressedLast = m_isActive(), *this, command, interruptible]() mutable {
        bool pressed = m_isActive();

        if (!pressedLast && pressed) {
          command->Schedule(interruptible);
        } else if (pressedLast && !pressed) {
          command->Cancel();
        }

        pressedLast = pressed;
      });
  return *this;
}

Trigger2 Trigger2::WhenInactive(Command* command, bool interruptible) {
  CommandScheduler::GetInstance().AddButton(
      [pressedLast = m_isActive(), *this, command, interruptible]() mutable {
        bool pressed = m_isActive();

        if (pressedLast && !pressed) {
          command->Schedule(interruptible);
        }

        pressedLast = pressed;
      });
  return *this;
}

Trigger2 Trigger2::WhenInactive(std::function<void()> toRun,
                                std::initializer_list<Subsystem*> requirements) {
  return WhenInactive(std::move(toRun),
                      wpi::makeArrayRef(requirements.begin(), requirements.end()));
}

Trigger2 Trigger2::WhenInactive(std::function<void()> toRun,
                                wpi::ArrayRef<Subsystem*> requirements) {
  return WhenInactive(InstantCommand(std::move(toRun), requirements));
}

Trigger2 Trigger2::ToggleWhenActive(Command* command, bool interruptible) {
  CommandScheduler::GetInstance().AddButton(
      [pressedLast = m_isActive(), *this, command, interruptible]() mutable {
        bool pressed = m_isActive();

        if (!pressedLast && pressed) {
          if (command->IsScheduled()) {
            command->Cancel();
          } else {
            command->Schedule(interruptible);
          }
        }

        pressedLast = pressed;
      });
  return *this;
}

Trigger2 Trigger2::CancelWhenActive(Command* command) {
  CommandScheduler::GetInstance().AddButton([pressedLast = m_isActive(), *this, command]() mutable {
    bool pressed = m_isActive();

    if (!pressedLast && pressed) {
      command->Cancel();
    }

    pressedLast = pressed;
  });
  return *this;
}
