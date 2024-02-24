#include "ConcatStringTree.h"

// Concat 2 string và in ra size của 3 string (tính thêm string kết quả)
void run() {
  auto s1 = ConcatStringTree("hello");
  auto s2 = new ConcatStringTree("world");
  auto s3 = s1.concat(*s2);
  std::cout << s1.getParTreeSize("") << std::endl;
  std::cout << s2->getParTreeSize("") << std::endl;
  delete s2;
  std::cout << s3.getParTreeSize("") << std::endl;
}