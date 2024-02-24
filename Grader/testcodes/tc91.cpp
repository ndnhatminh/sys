#include "ConcatStringTree.h"

// LitStringHash khi vừa thực hiện thu hồi vùng nhớ và thêm một phần tử
void run() {
  HashConfig config(5, 0, 0, 0.75, 2.0, 4);
  LitStringHash table(config);
  {
    auto s1 = ReducedConcatStringTree("hola", &table);
    std::cout << table.toString() << std::endl;
  }
  auto s2 = ReducedConcatStringTree("halo", &table);
  std::cout << table.toString() << std::endl;
}