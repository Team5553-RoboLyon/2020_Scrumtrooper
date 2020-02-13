/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/AdjustableHood.h"

AdjustableHood::AdjustableHood() {
    if(!isActivated) return;
}

void AdjustableHood::Close() {
    Stop();
    isOpened = false;
}

void AdjustableHood::SetAngle() {
    if(!isActivated) return;
    isOpened = true;
}

void AdjustableHood::Activate() {
    isActivated = true;
}

void AdjustableHood::Stop() {
    isActivated = false;
}