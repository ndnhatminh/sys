#include "ConcatStringTree.h"

void run() {

    // ConcatStringTree concat(const ConcatStringTree & otherS) const
    // 3 nodes

    ConcatStringTree* s = new ConcatStringTree("Assignment 2");
    ConcatStringTree* s1 = new ConcatStringTree(" DSA, ");
    ConcatStringTree* s2 = new ConcatStringTree("testcase 35!");
    ConcatStringTree* c = new ConcatStringTree(s->concat(*s1));
    ConcatStringTree* clone = new ConcatStringTree(c->subString(0, c->length()));
    ConcatStringTree* c2 = new ConcatStringTree(clone->concat(*s2));

    std::cout << c->length() << std::endl;
    std::cout << c->toString() << std::endl;

    std::cout << c2->length() << std::endl;
    std::cout << c2->toString() << std::endl;
}