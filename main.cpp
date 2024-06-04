#include <mutex>
#include <vector>

#include "ai.h"
#include "cam.h"
#include "common.h"
#include "navigation.h"

#include "thread"

int main() {
  const unsigned int width = 1920;
  const unsigned int height = 1280;
  std::vector<unsigned int> my_image(width * height, 1);

  std::mutex m;
  bool done_cam = false, done_ai = false, done_nav = false;

  std::thread CamThread(cam::run, std::ref(my_image), std::ref(m), std::ref(done_cam));
  std::thread AiThread(ai::run, std::ref(my_image), std::ref(m), std::ref(done_ai));
  std::thread NavThread(navigation::run, std::ref(my_image), std::ref(m), std::ref(done_nav));

  CamThread.join();
  AiThread.join();
  NavThread.join();
}
//Tagging