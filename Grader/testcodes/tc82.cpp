#include "ConcatStringTree.h"

// LitStringHash sau khi thực hashing
void run() {
  HashConfig config(5, 0.5, 0.5, 0.75, 2.0, 4);
  LitStringHash table(config);
  auto s1 = ReducedConcatStringTree("hola", &table);
  auto s2 = ReducedConcatStringTree("hello", &table);
  auto s3 = ReducedConcatStringTree("aloha", &table);
  auto s4 = ReducedConcatStringTree("konnichiwa", &table);
  // rehashing xảy ra
  std::cout << table.getLastInsertedIndex() << std::endl;
}