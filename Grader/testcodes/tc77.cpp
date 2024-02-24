#include "ConcatStringTree.h"

// LitStringHash lúc chưa phần tử nào được chèn
void run() {
  HashConfig config(5, 0, 0, 0.75, 2.0, 4);
  LitStringHash table(config);

  std::cout << table.getLastInsertedIndex() << std::endl;
}