#include "ConcatStringTree.h"

// cout nhiều lần để kiểm tra độ phức tạp (số lần: 3*10^5) (2)
void run() {
  HashConfig config(5, 0.5, 0.5, 0.75, 2.0, 4);
  LitStringHash table(config);

  auto s = new ConcatStringTree("239");

  for (int i = 0; i < 16; i += 2) {
    auto s1 = ReducedConcatStringTree(std::to_string(i).c_str(), &table);
    auto s2 = ReducedConcatStringTree(std::to_string(i + 1).c_str(), &table);
    auto s12 = s1.concat(s2);
    auto newS = new ConcatStringTree(s->concat(s12));
    std::swap(s, newS);
    delete newS;
  }
  for (int i = 0; i < 1e5; i++) {
    std::cout << table.getLastInsertedIndex() << std::endl;
  }
//   delete s;
}