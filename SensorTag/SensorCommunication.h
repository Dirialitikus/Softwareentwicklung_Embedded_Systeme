//
// Created by kaane on 13.11.2022.
//

#ifndef EMBEDDED_PRAK_SENSORCOMMUNICATION_H
#define EMBEDDED_PRAK_SENSORCOMMUNICATION_H


#include "Motion.h"
#include "SensorConfiguration.h"

/*
	This Calss is used for the communication with a SensorTag
*/
class CSensorCommunication {
public:
    /*
        Reads the motion sensor from the SensorTag specified by the given SensorTag
        confoguration, converts the raw data and returns it as Motion_t.
        @param[in] conf Configuration of the SensorTag
        @return Motion values
    */
    Motion_t getMotion(CSensorConfiguration conf);
    int writeConfig(CSensorConfiguration conf);
private:
    /*
        Reads the Motion from the SensorTag specified by the given configuration.
        @param[in] conf Configuration of the SensorTag
        @param[out] buffer A 12 byte array that will be filled by the function with
        the raw data of the motion sensor.
        @return 0 for success, -1 for failure
    */
    virtual int readMotion(CSensorConfiguration conf, char* buffer);

    /*
        Converts the raw data of the motion sensor and return the converted values.
        @param[in] rawData	A 12 byte array that contains the raw data of the motion sensor.
        @return Motion_t filled with the converted motion values
    */
    virtual Motion_t convertMotion(char* rawData);
};

#endif //EMBEDDED_PRAK_SENSORCOMMUNICATION_H
