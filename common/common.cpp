#include "common.h"

namespace common {

const std::chrono::time_point<sys_clock> t_epoch = sys_clock::now();

double get_timer_ticks() {
  std::chrono::duration<double, std::milli> t_dur = sys_clock::now() - t_epoch;
  return static_cast<double>(t_dur.count());
}
}  // namespace common