#ifndef MY_TIMER_H_
#define MY_TIMER_H_

#include <chrono>

using sys_clock = std::chrono::high_resolution_clock;

namespace common {
extern const std::chrono::time_point<sys_clock> t_epoch;

/**
 * @brief Get the timer ticks since system startup
 *
 * @return timer ticks in milliseconds
 */
double get_timer_ticks();
}  // namespace common

#endif