//
// Created by kaane on 13.11.2022.
//
#include "SensorCommunication.h"
#include "SensorConfiguration.h"
#include <iostream>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
// system
#include <stdlib.h>
// fifo
#include <fcntl.h>
#include <sys/stat.h>
// read
#include <unistd.h>

#define MAX_BUF 12
const int test = 0x01;
#define is_bigendian() ((*(char *)&test) == 0)

Motion_t CSensorCommunication::getMotion(CSensorConfiguration conf) {
    char buffer[MAX_BUF];
    memset(buffer, 0, MAX_BUF);
    if (readMotion(conf, buffer) != 0) {
        std::cerr << "can't read motion" << std::endl;
    }
    return convertMotion(buffer);
}
static int16_t extractValue(char *start) {
    unsigned char *data_cell = (unsigned char *)start;
    uint16_t result = 0x0000;
    result |= *data_cell;
    result |= (*(data_cell + 1)) << 8;
    return *(int16_t *)&result;
}
Motion_t CSensorCommunication::convertMotion(char *rawData) {
    Motion_t motion;
    // encoded two bytes signed integer
    // (raw * 1.0) / (65536/500) -> gyroscope
    // (raw * 1.0) / (32768/2) -> acc  ??? why 32768
    /* Umrechnung hier einfügen */
    motion.gyro.x = (extractValue(rawData) * 1.0) / (65536 / 500);
    motion.gyro.y = (extractValue(rawData + 2) * 1.0) / (65536 / 500);
    motion.gyro.z = (extractValue(rawData + 4) * 1.0) / (65536 / 500);
    motion.acc.x = (extractValue(rawData + 6) * 1.0) / (32768 / 2);
    motion.acc.y = (extractValue(rawData + 8) * 1.0) / (32768 / 2);
    motion.acc.z = (extractValue(rawData + 10) * 1.0) / (32768 / 2);
    return motion;
}

int CSensorCommunication::writeConfig(CSensorConfiguration conf) {
    std::cout << "Write Config Platzhalter" << std::endl;
    /* Activate the motion measurements */
    return 0;
}

int CSensorCommunication::readMotion(CSensorConfiguration conf, char *buffer) {
    buffer[0] = 0x0d;
    buffer[1] = 0x01;
    buffer[2] = 0x6c;
    buffer[3] = 0xfc;
    buffer[4] = 0xd9;
    buffer[5] = 0xfc;
    buffer[6] = 0xf4;
    buffer[7] = 0xfd;
    buffer[8] = 0x85;
    buffer[9] = 0x00;
    buffer[10] = 0xd2;
    buffer[11] = 0x0f;

    /* Read movement data and display it */

  // std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}