#include "ConcatStringTree.h"

void run() {

    // random

    ConcatStringTree* s = new ConcatStringTree("0123456789");
    ConcatStringTree* s1 = new ConcatStringTree(*s);
    std::cout << s1->toString() << std::endl;
}