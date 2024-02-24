#include "ConcatStringTree.h"

void run() {

    // ConcatStringTree concat(const ConcatStringTree & otherS) const
    // 2 nodes

    ConcatStringTree* s1 = new ConcatStringTree("Assignment 2 DSA,");
    ConcatStringTree* s2 = new ConcatStringTree(" testcase 34!");
    ConcatStringTree* s = new ConcatStringTree(s1->concat(*s2));

    std::cout << s->length() << std::endl;
    std::cout << s->toString() << std::endl;
}