#include "ConcatStringTree.h"

void run() {

    // random

    const char* str = "Assignment 2 DSA!";
    ConcatStringTree* s = new ConcatStringTree(str);
    std::cout << s->toString() << std::endl;
}