#include "ConcatStringTree.h"

void run() {

    // int length() const
    // random

    ConcatStringTree* s = new ConcatStringTree("Assignment ");
    std::cout << s->length() << std::endl;

    ConcatStringTree* s1 = new ConcatStringTree("2 ");
    std::cout << s1->length() << std::endl;

    ConcatStringTree* c1 = new ConcatStringTree(s->concat(*s1));
    std::cout << c1->length() << std::endl;

    ConcatStringTree* s2 = new ConcatStringTree("DSA!");
    std::cout << s2->length() << std::endl;

    ConcatStringTree* clone = new ConcatStringTree(c1->subString(0, c1->length()));
    std::cout << clone->length() << std::endl;

    ConcatStringTree* c2 = new ConcatStringTree(clone->concat(*s2));
    std::cout << c2->length() << std::endl;
}