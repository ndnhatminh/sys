#include "ConcatStringTree.h"

// chained free (3)
void run() {
  auto s1 = new ConcatStringTree("hola");
  auto s2 = new ConcatStringTree("halo");
  auto s3 = new ConcatStringTree("ola");
  auto s12 = new ConcatStringTree(s1->concat(*s2));
  auto s123 = new ConcatStringTree(s12->concat(*s3));
  delete s2;
  delete s3;
  delete s123;
  delete s12;
  std::cout << s1->getParTreeStringPreOrder("");
  delete s1;
}