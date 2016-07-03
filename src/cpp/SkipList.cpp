//
//  SkipList.cpp
//  SkipList
//
//  Created by Paul Ross on 19/12/2015.
//  Copyright (c) 2015 AHL. All rights reserved.
//

#include <cstdlib>
#include "SkipList.h"

namespace ManAHL {
namespace SkipList {

/* Tosses a virtual coin, returns true if 'heads'.
 *
 * No heads:
 * return false;
 * 6.25% heads:
 * return rand() < RAND_MAX / 16;
 * 12.5% heads:
 * return rand() < RAND_MAX / 8;
 * 25% heads:
 * return rand() < RAND_MAX / 4;
 * Fair coin:
 * return rand() < RAND_MAX / 2;
 * 75% heads:
 * return rand() < RAND_MAX - RAND_MAX / 4;
 * 87.5% heads:
 * return rand() < RAND_MAX - RAND_MAX / 8;
 * 93.75% heads:
 * return rand() < RAND_MAX - RAND_MAX / 16;
 */
bool tossCoin() {
    return rand() < RAND_MAX / 2;
}

void seedRand(unsigned seed) {
    srand(seed);
}

// This throws an IndexError when the index value >= size.
// If possible the error will have an informative message.
void _throw_exceeds_size(size_t size) {
#ifdef INCLUDE_METHODS_THAT_USE_STREAMS
    std::ostringstream oss;
    oss << "Index out of range 0 <= index < " << size;
    std::string err_msg = oss.str();
#else
    std::string err_msg = "Index out of range.";
#endif
    throw IndexError(err_msg);
}

} // namespace SkipList
} // namespace ManAHL
