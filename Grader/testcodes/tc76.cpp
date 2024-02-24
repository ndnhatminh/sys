#include "ConcatStringTree.h"

// LitStringHash không có chỗ trống để thêm vào, ném ra ngoại lệ
void run() {
  // h = 0
  HashConfig config(0, 0, 0, 0.75, 2.0, 4);
  LitStringHash table(config);

  auto s1 = ReducedConcatStringTree("hello", &table);
  try {
    auto s2 = ReducedConcatStringTree("hola", &table);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}