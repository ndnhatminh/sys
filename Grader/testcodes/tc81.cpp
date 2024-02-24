#include "ConcatStringTree.h"

// LitStringHash không cần thực hiện hashing (2)
void run() {
  HashConfig config(5, 0, 0, 0.75, 2.0, 4);
  LitStringHash table(config);
  auto s1 = ReducedConcatStringTree("hola", &table);
  std::cout << table.getLastInsertedIndex() << std::endl;
  auto s2 = new ReducedConcatStringTree("hola", &table);
  std::cout << table.getLastInsertedIndex() << std::endl;
  delete s2;
  auto s3 = ReducedConcatStringTree("hola", &table);
  std::cout << table.getLastInsertedIndex() << std::endl;
}