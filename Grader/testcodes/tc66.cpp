#include "ConcatStringTree.h"

// Concat 2 string được string kết quả là s3. cout size 3 query hợp lệ trên s3
// ("","l","r")
void run() {
  auto s1 = ConcatStringTree("hello");
  auto s2 = new ConcatStringTree("world");
  auto s3 = s1.concat(*s2);
  delete s2;
  std::cout << s3.getParTreeStringPreOrder("") << std::endl;
  std::cout << s3.getParTreeStringPreOrder("l") << std::endl;
  std::cout << s3.getParTreeStringPreOrder("r") << std::endl;
}