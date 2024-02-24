#include "ConcatStringTree.h"

// LitStringHash toString concat
void run() {
  HashConfig config(5, 0.5, 0.5, 0.75, 2.0, 7);
  LitStringHash table(config);
  auto s1 = new ReducedConcatStringTree("cse ", &table);
  auto s2 = new ReducedConcatStringTree("connection ", &table);
  auto s3 = new ReducedConcatStringTree("2022", &table);
  auto s0 = new ReducedConcatStringTree("5", &table);
  auto s12 = new ConcatStringTree(s1->concat(*s2));
  auto s30 = new ConcatStringTree(s3->concat(*s0));
  auto s1230 = new ConcatStringTree(s12->concat(*s30));
//   std::cout << s1230->toString() << std::endl;
  std::cout << s12->toString() << std::endl;
}