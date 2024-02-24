#include "ConcatStringTree.h"

// Concat 1000 string, cout size nhiều lần để kiểm tra độ phức tạp (số lần cout
// khoảng: 2 * 10^5) (2)
void run() {
  auto s = new ConcatStringTree("");
  auto pathToS = std::string("");
  for (int i = 0; i < 1000; i++) {
    auto t = ConcatStringTree("aaa");
    ConcatStringTree *newS;
    if (i % 2 == 0) {
      newS = new ConcatStringTree(s->concat(t));
      pathToS += "l";
    } else {
      newS = new ConcatStringTree(t.concat(*s));
      pathToS += "r";
    }
    std::swap(s, newS);
    delete newS;
  }
  for (int i = 0; i < 2e5; i++) {
    std::cout << s->getParTreeSize(pathToS);
  }
  delete s;
}