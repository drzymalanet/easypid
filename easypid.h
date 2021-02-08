#ifndef __EASYPID_H__
#define __EASYPID_H__
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
#include "permil.h"

// Type for pointer to easypid object
typedef void* easypid_ptr_t;

// Get size of memory required by `easypid_init` function.
int easypid_size();

// Initialize a new easypid object
// `p` is a pointer to free memory which must be available.
// The memory must be allocated beforehand and of the size not smaller
// than the size returned by the function `easypid_size`.
// Return value is the same pointer, casted to easypid object type.
easypid_ptr_t easypid_init(void * p);

// Set the PID tuning parameters
// `p` is the easypid object pointer
// `Kp` is the proportional argument [0..1000]
// `Ki` is the integral parameter [0..1000]
// `Kd` is the derivative parameter [0.1000]
void easypid_set(easypid_ptr_t p, permil_t Kp, permil_t Ki, permil_t Kd);

// Run the PID controller
// `p` is the easypid object
// `r` is the desired process value
// `y` is the measured feedback value
// Return value is the controller output value
permil_t easypid_run(easypid_ptr_t p, permil_t r, permil_t y);

#endif // __EASYPID_H__
