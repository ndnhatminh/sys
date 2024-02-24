#include "ConcatStringTree.h"

void run() {

    // ConcatStringTree reverse() const
    // 1 node

    ConcatStringTree* s = new ConcatStringTree("Testcase 47!");
    ConcatStringTree* r = new ConcatStringTree(s->reverse());
    
    std::cout << r->length() << std::endl;
    std::cout << r->toString() << std::endl;
}