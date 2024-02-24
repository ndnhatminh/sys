#include "ConcatStringTree.h"

void run() {

    // ConcatStringTree reverse() const
    // random

    ConcatStringTree* s1 = new ConcatStringTree("Assignment 2 DSA, ");
    ConcatStringTree* s2 = new ConcatStringTree("testcase 50!");
    ConcatStringTree* s = new ConcatStringTree(s1->concat(*s2));
    ConcatStringTree* r1 = new ConcatStringTree(s->reverse());
    ConcatStringTree* r2 = new ConcatStringTree(r1->reverse());

    std::cout << r1->length() <<" "<< r2->length() << std::endl;
    std::cout << r1->toString() <<" "<< r2->toString() << std::endl;
}