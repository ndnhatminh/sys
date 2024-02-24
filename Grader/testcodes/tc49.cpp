#include "ConcatStringTree.h"

void run() {

    // ConcatStringTree reverse() const
    // 3 nodes

    ConcatStringTree* s = new ConcatStringTree("Assignment 2 ");
    ConcatStringTree* s1 = new ConcatStringTree("DSA, ");
    ConcatStringTree* s2 = new ConcatStringTree("testcase 49!");
    ConcatStringTree* c = new ConcatStringTree(s->concat(*s1));
    ConcatStringTree* clone = new ConcatStringTree(c->subString(0, c->length()));
    ConcatStringTree* c2 = new ConcatStringTree(clone->concat(*s2));
    ConcatStringTree* r = new ConcatStringTree(c2->reverse());

    std::cout << r->length() << std::endl;
    std::cout << r->toString() << std::endl;
}