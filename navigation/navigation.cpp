#include "navigation.h"

namespace navigation {
double t_prev = common::get_timer_ticks();

void run(std::vector<unsigned int> image) {
  std::cout << "[Nav]: Time since last execution: "
            << common::get_timer_ticks() - t_prev << " ms" << std::endl;
  t_prev = common::get_timer_ticks();
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
}
}  // namespace navigation
