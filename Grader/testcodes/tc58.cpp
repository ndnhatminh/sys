#include "ConcatStringTree.h"

// Concat 10 string, cout (một vài) size với query hợp lệ. (2)
void run() {
  auto s1 = ConcatStringTree("one");
  auto s2 = ConcatStringTree("two");
  auto s3 = ConcatStringTree("three");
  auto s4 = ConcatStringTree("four");
  auto s5 = ConcatStringTree("five");
  auto s6 = ConcatStringTree("six");
  auto s7 = ConcatStringTree("seven");
  auto s8 = ConcatStringTree("eight");
  auto s9 = ConcatStringTree("nine");
  auto s10 = ConcatStringTree("ten");

  auto s12 = new ConcatStringTree(s1.concat(s2));
  auto s34 = s3.concat(s4);
  auto s56 = new ConcatStringTree(s5.concat(s6));
  auto s78 = s7.concat(s8);
  auto s910 = s9.concat(s10);

  auto s1234 = s12->concat(s34);
  auto s123456 = new ConcatStringTree(s1234.concat(*s56));
  auto s78910 = s78.concat(s910);

  auto s12345678910 = s123456->concat(s78910);

  delete s12;
  delete s56;
  delete s123456;

  std::cout << s12345678910.getParTreeSize("l") << std::endl;
  std::cout << s12345678910.getParTreeSize("lr") << std::endl;
  std::cout << s12345678910.getParTreeSize("llll") << std::endl;
}