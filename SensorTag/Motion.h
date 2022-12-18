//
// Created by kaane on 13.11.2022.
//

#ifndef EMBEDDED_PRAK_MOTION_H
#define EMBEDDED_PRAK_MOTION_H

struct Accelerometer {
    float x;
    float y;
    float z;
};
typedef struct Accelerometer Accelerometer_t;

struct Gyroscope {
    float x;
    float y;
    float z;
};
typedef struct Gyroscope Gyroscope_t;

struct Motion {
    struct Gyroscope gyro;
    struct Accelerometer acc;
};
typedef struct Motion Motion_t;

#endif //EMBEDDED_PRAK_MOTION_H
