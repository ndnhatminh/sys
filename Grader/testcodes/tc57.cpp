#include "ConcatStringTree.h"

// Concat 10 string, cout (một vài) size với query hợp lệ. (1)
void run() {
  //                            s1234567890
  //                    s123456
  //         [s1234]                                   s7890
  //    s12           s34           s56          [s78]          s90
  // s1     s2     s3     s4     s5     s6     s7     s8     s9     s0

  auto s1 = ConcatStringTree("one");
  auto s2 = ConcatStringTree("two");
  auto s3 = ConcatStringTree("three");
  auto s4 = ConcatStringTree("four");
  auto s5 = ConcatStringTree("five");
  auto s6 = ConcatStringTree("six");
  auto s7 = ConcatStringTree("seven");
  auto s8 = ConcatStringTree("eight");
  auto s9 = ConcatStringTree("nine");
  auto s0 = ConcatStringTree("ten");

  auto s12 = s1.concat(s2);
  auto s34 = s3.concat(s4);
  auto s56 = s5.concat(s6);
  auto s78 = new ConcatStringTree(s7.concat(s8));
  auto s90 = s9.concat(s0);

  auto s1234 = new ConcatStringTree(s12.concat(s34));
  auto s123456 = s1234->concat(s56);
  auto s7890 = s78->concat(s90);

  auto s1234567890 = s123456.concat(s7890);

  delete s1234;
  delete s78;

  std::cout << s1234567890.getParTreeSize("llr") << std::endl;
  std::cout << s1234567890.getParTreeSize("rlr") << std::endl;
  std::cout << s1234567890.getParTreeSize("r") << std::endl;
}