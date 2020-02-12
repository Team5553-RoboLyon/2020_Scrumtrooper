/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Turret.h"

Turret::Turret() {

}

void Turret::Periodic() {
    if(!turretActivated) return;
}

void Turret::Activate() {
    turretActivated = true;
}

void Turret::Stop() {
    turretActivated = false;
}