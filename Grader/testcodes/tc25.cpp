#include "ConcatStringTree.h"

void run() {

    // int indexOf(char c) const
    // 3 nodes, cout 300000 times

    ConcatStringTree* s = new ConcatStringTree("Assignment 2");
    ConcatStringTree* s1 = new ConcatStringTree(" DSA, ");
    ConcatStringTree* s2 = new ConcatStringTree("testcase 25!");
    ConcatStringTree* c = new ConcatStringTree(s->concat(*s1));
    ConcatStringTree* clone = new ConcatStringTree(c->subString(0, c->length()));
    ConcatStringTree* c2 = new ConcatStringTree(clone->concat(*s2));

    for (int i = 0; i < 300000; i++)
        std::cout << c2->indexOf('!') << std::endl;
}