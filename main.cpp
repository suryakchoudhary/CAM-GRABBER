#include <mutex>
#include <vector>

#include "ai.h"
#include "cam.h"
#include "common.h"
#include "navigation.h"

int main() {
  const unsigned int width = 1920;
  const unsigned int height = 1280;
  std::vector<unsigned int> my_image(width * height, 1);

  std::mutex m;
  bool done_cam = false, done_ai = false, done_nav = false;

  while (1) {
    navigation::run(my_image, m, done_nav);
    ai::run(my_image, m, done_ai);
    cam::run(my_image, m, done_cam);
  }
}