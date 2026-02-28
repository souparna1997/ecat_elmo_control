// This is a single-producer single-consumer circular buffer

#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include <stdint.h>

#define BUFFER_SIZE 2048

typedef struct {
    int16_t torque_cmd;
    int16_t torque_actual;
    uint64_t timestamp;
} MotorSample;

typedef struct {
    volatile uint32_t write_index;
    MotorSample buffer[BUFFER_SIZE];
} SharedMemory;

#endif