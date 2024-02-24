#include "ConcatStringTree.h"

void run() {

    // char get(int index) const
    // index - valid, 3 nodes, index in node 0

    ConcatStringTree *s1 = new ConcatStringTree("Assignment 2 ");
    ConcatStringTree *s2 = new ConcatStringTree("DSA,");
    ConcatStringTree *s3 = new ConcatStringTree(" testcase 15!");
    ConcatStringTree *s4 = new ConcatStringTree(s1 -> concat(*s2));
    ConcatStringTree *s5 = new ConcatStringTree(s4 -> subString(0, s4 -> length()));
    ConcatStringTree *s = new ConcatStringTree(s5 -> concat(*s3));

    for (int i = 0; i < 13; i++){
        std::cout << "char at index " << i << "of s: "
            << s -> get(i) << std::endl;
    }
}