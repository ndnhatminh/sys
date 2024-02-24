#include "ConcatStringTree.h"

void run() {

    // string toStringPreOrder() const
    // 1 node

    ConcatStringTree *s = new ConcatStringTree("Assignment 2 DSA!");
    std::cout << "s: " << s -> toStringPreOrder() << std::endl;
}