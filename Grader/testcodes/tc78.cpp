#include "ConcatStringTree.h"

// LitStringHash lúc chưa phần tử nào được chèn (2)
void run() {
  auto config = new HashConfig(5, 0, 0, 0.75, 2.0, 4);
  auto table = new LitStringHash(*config);
  std::cout << table->getLastInsertedIndex() << std::endl;
  delete table;
  delete config;
}