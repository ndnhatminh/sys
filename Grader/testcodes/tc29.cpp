#include "ConcatStringTree.h"

void run() {

    // string toStringPreOrder() const
    // 2 nodes, cout 300000 times

    ConcatStringTree *s1 = new ConcatStringTree("Assignment 2 DSA, ");
    ConcatStringTree *s2 = new ConcatStringTree("testcase 29!");
    ConcatStringTree *s = new ConcatStringTree(s1 -> concat(*s2));

    for (int i = 0; i < 100000; i++){
        std::cout << "s1: " << s1 -> toStringPreOrder() << std::endl;
        std::cout << "s2: " << s2 -> toStringPreOrder() << std::endl;
        std::cout << "s: " << s -> toStringPreOrder() << std::endl;
    }
}
