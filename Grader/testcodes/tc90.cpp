#include "ConcatStringTree.h"

// LitStringHash 4k+3 rehash
void run() {
  HashConfig config(5, 0.5, 0.5, 0.75, 2.0, 7);
  LitStringHash table(config);
  auto s1 = ReducedConcatStringTree("hola", &table);
  auto s2 = ReducedConcatStringTree("hello", &table);
  auto s3 = ReducedConcatStringTree("aloha", &table);
  auto s4 = ReducedConcatStringTree("konnichiwa", &table);
  auto s5 = ReducedConcatStringTree("bonjour", &table);
  std::cout << table.toString() << std::endl;
  auto s6 = ReducedConcatStringTree("xin chao", &table);
  // rehashing xảy ra
  std::cout << table.toString() << std::endl;
}