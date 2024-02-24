#include "ConcatStringTree.h"

// LitStringHash
void run() {
  HashConfig config(0, 0, 0, 0.75, 2.0, 4);
  LitStringHash table(config);

  auto s1a = ReducedConcatStringTree("hello", &table);
  auto s2a = ReducedConcatStringTree("world", &table);

  auto s1b = ReducedConcatStringTree("hello", &table);
  auto s2b = ReducedConcatStringTree("world", &table);

  auto sa = s1a.concat(s2a);
  auto sb = s1b.concat(s2b);

  std::cout << s1a.getParTreeStringPreOrder("") << std::endl;
  std::cout << s2b.getParTreeStringPreOrder("") << std::endl;
}