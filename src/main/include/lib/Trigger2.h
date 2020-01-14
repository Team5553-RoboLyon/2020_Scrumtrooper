/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <functional>
#include <initializer_list>
#include <memory>
#include <utility>

#include <wpi/ArrayRef.h>

#include <frc2/command/Command.h>
#include <frc2/command/CommandScheduler.h>

namespace frc2 {
class Command;
/**
 * A class used to bind command scheduling to events.  The
 * Trigger2 class is a base for all command-event-binding classes, and so the
 * methods are named fairly abstractly; for purpose-specific wrappers, see
 * Button.
 *
 * @see Button
 */
class Trigger2 {
 public:
  /**
   * Create a new trigger that is active when the given condition is true.
   *
   * @param isActive Whether the trigger is active.
   */
  explicit Trigger2(std::function<bool()> isActive) : m_isActive{std::move(isActive)} {}

  /**
   * Create a new trigger that is never active (default constructor) - activity
   *  can be further determined by subclass code.
   */
  Trigger2() {
    m_isActive = [] { return false; };
  }

  Trigger2(const Trigger2& other);

  /**
   * Binds a command to start when the trigger becomes active.  Takes a
   * raw pointer, and so is non-owning; users are responsible for the lifespan
   * of the command.
   *
   * @param command The command to bind.
   * @param interruptible Whether the command should be interruptible.
   * @return The trigger, for chained calls.
   */
  Trigger2 WhenActive(Command* command, bool interruptible = true);

  /**
   * Binds a command to start when the trigger becomes active.  Transfers
   * command ownership to the button scheduler, so the user does not have to
   * worry about lifespan - rvalue refs will be *moved*, lvalue refs will be
   * *copied.*
   *
   * @param command The command to bind.
   * @param interruptible Whether the command should be interruptible.
   * @return The trigger, for chained calls.
   */
  template <class T,
            typename = std::enable_if_t<std::is_base_of_v<Command, std::remove_reference_t<T>>>>
  Trigger2 WhenActive(T&& command, bool interruptible = true) {
    CommandScheduler::GetInstance().AddButton(
        [pressedLast = m_isActive(), *this,
         command = std::make_unique<std::remove_reference_t<T>>(std::forward<T>(command)),
         interruptible]() mutable {
          bool pressed = m_isActive();

          if (!pressedLast && pressed) {
            command->Schedule(interruptible);
          }

          pressedLast = pressed;
        });

    return *this;
  }

  /**
   * Binds a runnable to execute when the trigger becomes active.
   *
   * @param toRun the runnable to execute.
   * @paaram requirements the required subsystems.
   */
  Trigger2 WhenActive(std::function<void()> toRun, std::initializer_list<Subsystem*> requirements);

  /**
   * Binds a runnable to execute when the trigger becomes active.
   *
   * @param toRun the runnable to execute.
   * @paaram requirements the required subsystems.
   */
  Trigger2 WhenActive(std::function<void()> toRun, wpi::ArrayRef<Subsystem*> requirements = {});

  /**
   * Binds a command to be started repeatedly while the trigger is active, and
   * cancelled when it becomes inactive.  Takes a raw pointer, and so is
   * non-owning; users are responsible for the lifespan of the command.
   *
   * @param command The command to bind.
   * @param interruptible Whether the command should be interruptible.
   * @return The trigger, for chained calls.
   */
  Trigger2 WhileActiveContinous(Command* command, bool interruptible = true);

  /**
   * Binds a command to be started repeatedly while the trigger is active, and
   * cancelled when it becomes inactive.  Transfers command ownership to the
   * button scheduler, so the user does not have to worry about lifespan -
   * rvalue refs will be *moved*, lvalue refs will be *copied.*
   *
   * @param command The command to bind.
   * @param interruptible Whether the command should be interruptible.
   * @return The trigger, for chained calls.
   */
  template <class T,
            typename = std::enable_if_t<std::is_base_of_v<Command, std::remove_reference_t<T>>>>
  Trigger2 WhileActiveContinous(T&& command, bool interruptible = true) {
    CommandScheduler::GetInstance().AddButton(
        [pressedLast = m_isActive(), *this,
         command = std::make_unique<std::remove_reference_t<T>>(std::forward<T>(command)),
         interruptible]() mutable {
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

  /**
   * Binds a runnable to execute repeatedly while the trigger is active.
   *
   * @param toRun the runnable to execute.
   * @param requirements the required subsystems.
   */
  Trigger2 WhileActiveContinous(std::function<void()> toRun,
                                std::initializer_list<Subsystem*> requirements);

  /**
   * Binds a runnable to execute repeatedly while the trigger is active.
   *
   * @param toRun the runnable to execute.
   * @param requirements the required subsystems.
   */
  Trigger2 WhileActiveContinous(std::function<void()> toRun,
                                wpi::ArrayRef<Subsystem*> requirements = {});

  /**
   * Binds a command to be started when the trigger becomes active, and
   * cancelled when it becomes inactive.  Takes a raw pointer, and so is
   * non-owning; users are responsible for the lifespan of the command.
   *
   * @param command The command to bind.
   * @param interruptible Whether the command should be interruptible.
   * @return The trigger, for chained calls.
   */
  Trigger2 WhileActiveOnce(Command* command, bool interruptible = true);

  /**
   * Binds a command to be started when the trigger becomes active, and
   * cancelled when it becomes inactive.  Transfers command ownership to the
   * button scheduler, so the user does not have to worry about lifespan -
   * rvalue refs will be *moved*, lvalue refs will be *copied.*
   *
   * @param command The command to bind.
   * @param interruptible Whether the command should be interruptible.
   * @return The trigger, for chained calls.
   */
  template <class T,
            typename = std::enable_if_t<std::is_base_of_v<Command, std::remove_reference_t<T>>>>
  Trigger2 WhileActiveOnce(T&& command, bool interruptible = true) {
    CommandScheduler::GetInstance().AddButton(
        [pressedLast = m_isActive(), *this,
         command = std::make_unique<std::remove_reference_t<T>>(std::forward<T>(command)),
         interruptible]() mutable {
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

  /**
   * Binds a command to start when the trigger becomes inactive.  Takes a
   * raw pointer, and so is non-owning; users are responsible for the lifespan
   * of the command.
   *
   * @param command The command to bind.
   * @param interruptible Whether the command should be interruptible.
   * @return The trigger, for chained calls.
   */
  Trigger2 WhenInactive(Command* command, bool interruptible = true);

  /**
   * Binds a command to start when the trigger becomes inactive.  Transfers
   * command ownership to the button scheduler, so the user does not have to
   * worry about lifespan - rvalue refs will be *moved*, lvalue refs will be
   * *copied.*
   *
   * @param command The command to bind.
   * @param interruptible Whether the command should be interruptible.
   * @return The trigger, for chained calls.
   */
  template <class T,
            typename = std::enable_if_t<std::is_base_of_v<Command, std::remove_reference_t<T>>>>
  Trigger2 WhenInactive(T&& command, bool interruptible = true) {
    CommandScheduler::GetInstance().AddButton(
        [pressedLast = m_isActive(), *this,
         command = std::make_unique<std::remove_reference_t<T>>(std::forward<T>(command)),
         interruptible]() mutable {
          bool pressed = m_isActive();

          if (pressedLast && !pressed) {
            command->Schedule(interruptible);
          }

          pressedLast = pressed;
        });
    return *this;
  }

  /**
   * Binds a runnable to execute when the trigger becomes inactive.
   *
   * @param toRun the runnable to execute.
   * @param requirements the required subsystems.
   */
  Trigger2 WhenInactive(std::function<void()> toRun,
                        std::initializer_list<Subsystem*> requirements);

  /**
   * Binds a runnable to execute when the trigger becomes inactive.
   *
   * @param toRun the runnable to execute.
   * @param requirements the required subsystems.
   */
  Trigger2 WhenInactive(std::function<void()> toRun, wpi::ArrayRef<Subsystem*> requirements = {});

  /**
   * Binds a command to start when the trigger becomes active, and be cancelled
   * when it again becomes active.  Takes a raw pointer, and so is non-owning;
   * users are responsible for the lifespan of the command.
   *
   * @param command The command to bind.
   * @param interruptible Whether the command should be interruptible.
   * @return The trigger, for chained calls.
   */
  Trigger2 ToggleWhenActive(Command* command, bool interruptible = true);

  /**
   * Binds a command to start when the trigger becomes active, and be cancelled
   * when it again becomes active.  Transfers command ownership to the button
   * scheduler, so the user does not have to worry about lifespan - rvalue refs
   * will be *moved*, lvalue refs will be *copied.*
   *
   * @param command The command to bind.
   * @param interruptible Whether the command should be interruptible.
   * @return The trigger, for chained calls.
   */
  template <class T,
            typename = std::enable_if_t<std::is_base_of_v<Command, std::remove_reference_t<T>>>>
  Trigger2 ToggleWhenActive(T&& command, bool interruptible = true) {
    CommandScheduler::GetInstance().AddButton(
        [pressedLast = m_isActive(), *this,
         command = std::make_unique<std::remove_reference_t<T>>(std::forward<T>(command)),
         interruptible]() mutable {
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

  /**
   * Binds a command to be cancelled when the trigger becomes active.  Takes a
   * raw pointer, and so is non-owning; users are responsible for the lifespan
   *  and scheduling of the command.
   *
   * @param command The command to bind.
   * @return The trigger, for chained calls.
   */
  Trigger2 CancelWhenActive(Command* command);

  /**
   * Composes two triggers with logical AND.
   *
   * @return A trigger which is active when both component triggers are active.
   */
  Trigger2 operator&&(Trigger2 rhs) {
    return Trigger2([*this, rhs] { return m_isActive() && rhs.m_isActive(); });
  }

  /**
   * Composes two triggers with logical OR.
   *
   * @return A trigger which is active when either component trigger is active.
   */
  Trigger2 operator||(Trigger2 rhs) {
    return Trigger2([*this, rhs] { return m_isActive() || rhs.m_isActive(); });
  }

  /**
   * Composes a trigger with logical NOT.
   *
   * @return A trigger which is active when the component trigger is inactive,
   * and vice-versa.
   */
  Trigger2 operator!() {
    return Trigger2([*this] { return !m_isActive(); });
  }

 private:
  std::function<bool()> m_isActive;
};
}  // namespace frc2
