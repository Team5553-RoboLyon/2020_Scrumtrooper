/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Hood.h"

Hood::Hood() {
    if(!isActivated) return;
}

void Hood::CloseHood() {
    Stop();
    isOpened = false;
}

void Hood::SetAngle() {
    if(!isActivated) return;
    isOpened = true;
}

void Hood::Activate() {
    isActivated = true;
}

void Hood::Stop() {
    isActivated = false;
}