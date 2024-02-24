#include "ConcatStringTree.h"

// Concat 1000 string, cout size nhiều lần để kiểm tra độ phức tạp (số lần cout
// khoảng: 2 * 10^5) (1)
void run() {
  auto s = new ConcatStringTree("");
  auto pathToS = std::string("");
  for (int i = 0; i < 1000; i++) {
    auto t = ConcatStringTree("aaa");
    auto newS = new ConcatStringTree(s->concat(t));
    pathToS += "l";
    std::swap(s, newS);
    delete newS;
  }
  for (int i = 0; i < 100; i++) {
    std::cout << s->getParTreeStringPreOrder(pathToS);
  }
  delete s;
}