#ifndef _AI_H_
#define _AI_H_

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#include "common.h"

namespace ai {
void run(std::vector<unsigned int> image, std::mutex& m, bool& done);
}

#endif