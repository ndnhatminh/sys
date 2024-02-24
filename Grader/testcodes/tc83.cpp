#include "ConcatStringTree.h"

// LitStringHash sau khi thực hashing (2)
void run() {
  HashConfig config(5, 0.5, 0.5, 0.75, 2.0, 4);
  LitStringHash table(config);
  //         s123
  //   [s12]
  //[s1]    [s2]    [s3]
  auto s1 = ReducedConcatStringTree("hola", &table);
  auto s2 = new ReducedConcatStringTree("hello", &table);
  auto s3 = new ReducedConcatStringTree("aloha", &table);
  auto s4 = ReducedConcatStringTree("konnichiwa", &table);
  delete s2;
  delete s3;
  // rehashing xảy ra
  std::cout << table.getLastInsertedIndex() << std::endl;
}