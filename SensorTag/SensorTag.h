//
// Created by kaane on 13.11.2022.
//

#ifndef EMBEDDED_PRAK_SENSORTAG_H
#define EMBEDDED_PRAK_SENSORTAG_H

#include "SensorConfiguration.h"
#include "SensorCommunication.h"

class CSensorTag: public CSensorConfiguration, private CSensorCommunication {
public:
    int initRead();
    int writeMovementConfig();
    int disconnect();
    /*
        Reads motion sensor from SensorTag
        @return Return Motion_t with convertet values
    */
    Motion_t getMotion();
};

#endif //EMBEDDED_PRAK_SENSORTAG_H
