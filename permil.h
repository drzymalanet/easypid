#ifndef __PERMIL_H__
#define __PERMIL_H__
// Title:       Permil type implementation
// Description: Type for values between -1000 and 1000
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

// Type for permil value (-1000..1000)
typedef int16_t permil_t;

// Smallest value of permil
#define PERMIL_MIN ((permil_t)-1000)

// Biggest value of permil
#define PERMIL_MAX ((permil_t)1000)

// Clip the value to be between PERMIL_MIN and PERMIL_MAX
#define PERMIL_CLIP(p) ( ((permil_t)(p)) <= PERMIL_MIN ? PERMIL_MIN : ( PERMIL_MAX <= ((permil_t)(p)) ? PERMIL_MAX : ((permil_t)(p)) ))

#endif // __PERMIL_H__
