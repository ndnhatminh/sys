#include "ConcatStringTree.h"

void run() {

    // ConcatStringTree reverse() const
    // 2 nodes

    ConcatStringTree* s1 = new ConcatStringTree("Testcase");
    ConcatStringTree* s2 = new ConcatStringTree(" 48!");
    ConcatStringTree* s = new ConcatStringTree(s1->concat(*s2));
    ConcatStringTree* r = new ConcatStringTree(s->reverse());

    std::cout << r->length() << std::endl;
    std::cout << r->toString() << std::endl;
}