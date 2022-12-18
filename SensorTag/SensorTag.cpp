//
// Created by kaane on 13.11.2022.
//
#include "SensorTag.h"

int CSensorTag::initRead(){
    return initializeSensortag();
}

int CSensorTag::disconnect(){
    return disconnectBLEDevice();
}

int CSensorTag::writeMovementConfig(){
    return CSensorCommunication::writeConfig(*this);
}

Motion_t CSensorTag::getMotion() {
    return CSensorCommunication::getMotion(*this);
}
