//
// Created by kaane on 13.11.2022.
//

#ifndef EMBEDDED_PRAK_SENSORCONFIGURATION_H
#define EMBEDDED_PRAK_SENSORCONFIGURATION_H


#include <string>

#include <vector>
#include <iostream>
#include <thread>
#include <atomic>
#include <csignal>

/*
	Configuration of a SensorTag
*/
class CSensorConfiguration {
private:
    /*
        MAC address of the SensorTag
    */
    std::string addr;
public:
    /*
        Sets the MAC address of the SensorTag
        @param[in] addr	MAC addes
    */
    void setAddr(std::string addr);

    /*
        Return the MAC addres of the SensorTag
        @return	MAC address as std::string
    */
    std::string getAddr();
    /*
        Connect to a Sensortag with the given adress
        and verify that it has a movement service and
        the described characteristics
        @return 0 for sucess, -1 for device not found,
        -2 for Service not found and -3 for wrong
        characteristics
    */
    virtual int initializeSensortag();

    virtual int disconnectBLEDevice();
};


#endif //EMBEDDED_PRAK_SENSORCONFIGURATION_H
