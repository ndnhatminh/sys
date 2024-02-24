#include "ConcatStringTree.h"

// chained free (1)
void run() {
  auto s1 = new ConcatStringTree("hola");
  auto s2 = new ConcatStringTree("halo");
  auto s3 = new ConcatStringTree("ola");
  auto s12 = new ConcatStringTree(s1->concat(*s2));
  auto s123 = new ConcatStringTree(s12->concat(*s3));
  delete s1;
  delete s2;
  delete s3;
  delete s12;
  std::cout << s123->getParTreeSize("") << std::endl;
  std::cout << s123->getParTreeSize("l") << std::endl;
  std::cout << s123->getParTreeSize("r") << std::endl;
  std::cout << s123->getParTreeSize("ll") << std::endl;
  std::cout << s123->getParTreeSize("lr") << std::endl;
  delete s123;
}
