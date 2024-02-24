#include "ConcatStringTree.h"

void run() {

    // random

    ConcatStringTree* s1 = new ConcatStringTree("Assignment 2 ");
    ConcatStringTree* s2 = new ConcatStringTree("DSA!");
    ConcatStringTree* s3 = new ConcatStringTree(s1->concat(*s2));
    std::cout << s3->toString() << std::endl;
}