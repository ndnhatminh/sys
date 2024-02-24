#include "ConcatStringTree.h"

void run() {

    // ConcatStringTree concat(const ConcatStringTree & otherS) const
    // 2 nodes, "cout" 300000 times

    for (int i = 0; i < 3e5; i++) {
        ConcatStringTree* s1 = new ConcatStringTree("Assignment 2 DSA, ");
        ConcatStringTree* s2 = new ConcatStringTree("testcase 37!");
        ConcatStringTree* c = new ConcatStringTree(s1->concat(*s2));

        std::cout << c->length() << std::endl;
        std::cout << c->toString() << std::endl;
    }
}