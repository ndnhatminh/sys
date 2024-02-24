#include "ConcatStringTree.h"

// cout nhiều lần để kiểm tra độ phức tạp (số lần: 3*10^5)
void run() {
  HashConfig config(5, 0.5, 0.5, 0.75, 2.0, 4);
  LitStringHash table(config);
  ReducedConcatStringTree *ss[16];

  for (int i = 0; i < 16; i++) {
    ss[i] = new ReducedConcatStringTree(std::to_string(i).c_str(), &table);
  }
  for (int i = 0; i < 1e4; i++) {
    std::cout << table.toString() << std::endl;
  }
//   for (int i = 0; i < 16; i++) {
//     delete ss[i];
//   }
}