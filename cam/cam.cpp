#include "cam.h"

#include <random>

namespace cam {
double t_prev = common::get_timer_ticks();
std::random_device rd;
std::mt19937 gen(rd());

std::uniform_int_distribution<unsigned int> distr(0, 255);

void run(std::vector<unsigned int> image, std::mutex &m, bool &done) {
  while (1){
  done = false;
  {
    std::unique_lock<std::mutex> lk(m);
    std::cout << "[Cam]: Time since last execution: "
              << common::get_timer_ticks() - t_prev << " ms" << std::endl;
  }
  t_prev = common::get_timer_ticks();
  for (auto &px : image) {
    px = distr(gen);
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(
      50 - static_cast<long int>(common::get_timer_ticks() - t_prev)));
  done = true;
}
}
}  // namespace cam
