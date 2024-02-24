#include "ConcatStringTree.h"

void run() {

    // ConcatStringTree concat(const ConcatStringTree & otherS) const
    // 3 nodes, "cout" 300000 times

    for (int i = 0; i < 3e5; i++) {
        ConcatStringTree* s = new ConcatStringTree("Assignment 2");
        ConcatStringTree* s1 = new ConcatStringTree(" DSA, ");
        ConcatStringTree* s2 = new ConcatStringTree("testcase 38!");
        ConcatStringTree* c = new ConcatStringTree(s->concat(*s1));
        ConcatStringTree* clone = new ConcatStringTree(c->subString(0, c->length()));
        ConcatStringTree* c2 = new ConcatStringTree(clone->concat(*s2));

        std::cout << c2->length() << std::endl;
        std::cout << c2->toString() << std::endl;
    }
}