#include "ConcatStringTree.h"

// LitStringHash intern parent
void run() {
  HashConfig config(5, 0.5, 0.5, 0.75, 2.0, 4);
  LitStringHash table(config);
  auto s1 = new ReducedConcatStringTree("2022", &table);
  auto s2 = ReducedConcatStringTree("2022", &table);
  std::cout << s2.getParTreeStringPreOrder("") << std::endl;
  delete s1;
  std::cout << s2.getParTreeStringPreOrder("") << std::endl;
}