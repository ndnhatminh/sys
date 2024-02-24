#include "ConcatStringTree.h"

void run() {

    // ConcatStringTree subString(int from, int to) const
    // index "from" invalid

    ConcatStringTree *s1 = new ConcatStringTree("Assignment 2 DSA, ");
    ConcatStringTree *s2 = new ConcatStringTree("testcase 39!");
    ConcatStringTree *s = new ConcatStringTree(s1 -> concat(*s2));

    try {
        ConcatStringTree *test = new ConcatStringTree(s -> subString(-2, 20));    
    }
    catch (out_of_range & ofr){
        std::cout << "Exception out_of_range: " << ofr.what() << std::endl;
    }
}
