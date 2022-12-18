//
// Created by kaane on 13.11.2022.
//

#include "SensorConfiguration.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void CSensorConfiguration::setAddr(std::string addr) {
    this->addr = addr;
}

std::string CSensorConfiguration::getAddr() {
    return this->addr;
}

int CSensorConfiguration::initializeSensortag() {



    /* Start the discovery of devices */

    /* Get the list of devices */

    /* Search for the device with the address given as a parameter to the program */


    /* Connect to the device and get the list of services exposed by it */

    /* Search for the movement service, by UUID */

    /* If there is a movement service on the device with the given UUID,
     * get it's characteristics, by UUID again */

    std::cout <<  "Platzhalter Connect und Initialisierung Sensortag" << std::endl;
    return 0;

}

int CSensorConfiguration::disconnectBLEDevice(){
    /* Disconnect from the device */
    std::cout <<  "Platzhalter Disconnect Sensortag" << std::endl;
    return 0;
}
