#include "ConcatStringTree.h"

// Concat giống ví dụ hình 1 (chuỗi cụ thể có thể khác), cout (một vài) size với
// query hợp lệ. (1)
void run() {
  //           s1234
  //    s12           s34
  // s1     s2     s3     s4
  auto s1 = ConcatStringTree("hello");
  auto s2 = ConcatStringTree(", t");
  auto s12 = new ConcatStringTree(s1.concat(s2));
  auto s3 = ConcatStringTree("his is");
  auto s4 = new ConcatStringTree(" an");
  auto s34 = s3.concat(*s4);
  auto s1234 = s12->concat(s34);
  delete s12;
  delete s4;
  std::cout << s1234.getParTreeSize("") << std::endl;
  std::cout << s1234.getParTreeSize("l") << std::endl;
  std::cout << s1234.getParTreeSize("r") << std::endl;
}