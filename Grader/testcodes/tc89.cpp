#include "ConcatStringTree.h"

// LitStringHash dead probing
void run() {
  // h = 0
  HashConfig config(0, 0, 0, 0.75, 2.0, 4);
  LitStringHash table(config);

  auto s1a = ReducedConcatStringTree("hello", &table);
  try {
    auto s2 = ReducedConcatStringTree("leeho", &table);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}