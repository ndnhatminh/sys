#include "ConcatStringTree.h"

void run() {

    // ConcatStringTree subString(int from, int to) const
    // from >= to

    ConcatStringTree *s = new ConcatStringTree("Assignment 2 DSA, testcase 41!");
    
    try {
        ConcatStringTree *test = new ConcatStringTree(s -> subString(10, 5));
    }
    catch (logic_error & ofr) {
        std::cout << "Exception logic_error: " << ofr.what() << std::endl;
    }
}
