#include "ConcatStringTree.h"

void run() {

    // ConcatStringTree subString(int from, int to) const
    // 3 nodes, from and to in node 0

    ConcatStringTree *s1 = new ConcatStringTree("Assignment 2 ");
    ConcatStringTree *s2 = new ConcatStringTree("DSA, ");
    ConcatStringTree *s3 = new ConcatStringTree("testcase 42!");
    ConcatStringTree *s4 = new ConcatStringTree(s1 -> concat(*s2));
    ConcatStringTree *s5 = new ConcatStringTree(s4 -> subString(0, s4 -> length()));
    ConcatStringTree *s = new ConcatStringTree(s5 -> concat(*s3));
    ConcatStringTree *test = new ConcatStringTree(s -> subString(0, 12));

    std::cout << "test: " << test -> toString() << std::endl;
}
