#include <vector>

#include "ai.h"
#include "common.h"
#include "navigation.h"

int main() {
  const unsigned int width = 1920;
  const unsigned int height = 1280;
  std::vector<unsigned int> my_image(width * height, 1);

  while (1) {
    navigation::run(my_image);
    ai::run(my_image);
  }
}