#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#include "common.h"

namespace navigation {
void run(std::vector<unsigned int> image, std::mutex &m, bool &done);
}

#endif