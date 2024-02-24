#include "ConcatStringTree.h"

void run() {
    
    // string toStringPreOrder() const
    // 3 nodes

    ConcatStringTree *s1 = new ConcatStringTree("Assignment 2");
    std::cout << "s1: " << s1 -> toStringPreOrder() << std::endl;

    ConcatStringTree *s2 = new ConcatStringTree(" DSA, ");
    std::cout << "s2: " << s2 -> toStringPreOrder() << std::endl;

    ConcatStringTree *s3 = new ConcatStringTree("testcase 28!");
    std::cout << "s3: " << s3 -> toStringPreOrder() << std::endl;

    ConcatStringTree *s4 = new ConcatStringTree(s1 -> concat(*s2));
     std::cout << "s4: " << s4 -> toStringPreOrder() << std::endl;

    ConcatStringTree *s5 = new ConcatStringTree(s4 -> subString(0, s4 -> length()));
    std::cout << "s5: " << s5 -> toStringPreOrder() << std::endl;

    ConcatStringTree *s = new ConcatStringTree(s5 -> concat(*s3));
    std::cout << "s: " << s -> toStringPreOrder() << std::endl;
}