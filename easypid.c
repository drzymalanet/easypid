// Title:       Easy PID
// Description: Simple PID controller implementation
// Author:      Marcin Drzymala
//
// License MIT:
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// to deal in the Software without restriction, including without
// limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software,
// and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
#include <stdint.h>
#include "permil.h"
#include "easypid.h"

// Structure of easypid object
struct __easypid_s {
    permil_t Kp;
    permil_t Ki;
    permil_t Kd;
    permil_t sum_i;
};

// Get size of memory required by `easypid_init` function.
int easypid_size() {
    struct __easypid_s dummy;
    return sizeof dummy;
}

// Initialize a new easypid object
// `p` is a pointer to free memory which must be available.
// The memory must be allocated beforehand and of the size not smaller
// than the size returned by the function `easypid_size`.
// Return value is the same pointer, casted to easypid object type.
easypid_ptr_t easypid_init(void * p) {
    uint8_t * byte_array = (uint8_t*) p;
    int size = 0;

    // Ensure the pointer is not null
    if ( ! byte_array ) {
        return p;
    }

    // Get the number of bytes and set all to zero
    size = easypid_size();
    while ( 0 < size ) {
        byte_array[size-1] = 0;
        size--;
    }
}

// Set the PID tuning parameters
// `p` is the easypid object pointer
// `Kp` is the proportional argument [0..1000]
// `Ki` is the integral parameter [0..1000]
// `Kd` is the derivative parameter [0.1000]
void easypid_set(easypid_ptr_t p, permil_t Kp, permil_t Ki, permil_t Kd) {
    struct __easypid_s * pid = p;

    // Ensure the pointer is not null
    if ( ! pid ) {
        return;
    }

    // Copy the coefficients
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
}

// Run the PID controller
// `p` is the easypid object
// `r` is the desired process value
// `y` is the measured feedback value
// Return value is the controller output value
permil_t easypid_run(easypid_ptr_t p, permil_t r, permil_t y) {
    struct __easypid_s * pid = p;

    // Calculate the error
    permil_t error = PERMIL_CLIP( PERMIL_CLIP(r) - PERMIL_CLIP(y) );

    // Calculate the proportional gain: Gp = Kp * e
    permil_t Kp = PERMIL_CLIP((permil_t)(((int32_t)error) * ((int32_t)pid->Kp) / 1000));
}


permil_t pvalue(permil_t error, permil_t p) {
    return PERMIL_CLIP(error * p / 1000);
}

permil_t ivalue(permil_t error, permil_t i) {
    
}
