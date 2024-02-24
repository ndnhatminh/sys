#include "ConcatStringTree.h"

void run() {

    // int length() const
    // 2 nodes

    ConcatStringTree* s1 = new ConcatStringTree("Assignment 2 ");
    ConcatStringTree* s2 = new ConcatStringTree("DSA!");
    ConcatStringTree* s = new ConcatStringTree(s1->concat(*s2));
    
    std::cout << s->length() << std::endl;
}