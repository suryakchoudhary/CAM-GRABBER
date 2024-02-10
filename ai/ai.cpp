#include "ai.h"

namespace ai {
double t_prev = common::get_timer_ticks();

void run(std::vector<unsigned int> image) {
  std::cout << "[AI ]: Time since last execution: "
            << common::get_timer_ticks() - t_prev << " ms" << std::endl;
  t_prev = common::get_timer_ticks();
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
}  // namespace ai
