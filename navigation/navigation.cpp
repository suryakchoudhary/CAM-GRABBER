#include "navigation.h"

namespace navigation {
double t_prev = common::get_timer_ticks();

void run(std::vector<unsigned int> image, std::mutex& m, bool& done) {
  done = false;
  {
    std::unique_lock<std::mutex> lk(m);
    std::cout << "[Nav]: Time since last execution: "
              << common::get_timer_ticks() - t_prev << " ms" << std::endl;
  }
  t_prev = common::get_timer_ticks();
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  done = true;
}
}  // namespace navigation
