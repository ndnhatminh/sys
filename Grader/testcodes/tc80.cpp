#include "ConcatStringTree.h"

// LitStringHash không cần thực hiện hashing
void run() {
  HashConfig config(5, 0, 0, 0.75, 2.0, 4);
  LitStringHash table(config);
  auto s1 = ReducedConcatStringTree("hola", &table);
  std::cout << table.getLastInsertedIndex() << std::endl;
  auto s2 = ReducedConcatStringTree("hola", &table);
  std::cout << table.getLastInsertedIndex() << std::endl;
}