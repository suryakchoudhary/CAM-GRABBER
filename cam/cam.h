#ifndef _CAM_H_
#define _CAM_H_

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#include "common.h"

namespace cam {
void run(std::vector<unsigned int> image, std::mutex& m, bool& done);
}

#endif