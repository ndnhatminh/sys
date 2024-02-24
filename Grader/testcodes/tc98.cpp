#include "ConcatStringTree.h"

// LitStringHash xóa phần tử được intern
void run() {
  HashConfig config(5, 0.5, 0.5, 0.75, 2.0, 4);
  LitStringHash table(config);
  auto s3a = new ReducedConcatStringTree("2022", &table);
  { auto s3b = ReducedConcatStringTree("2022", &table); }
  std::cout << table.toString() << std::endl;
  delete s3a;
}