#include "ConcatStringTree.h"

void run() {

    // char get(int index) const
    // index = length - 1, list has 3 nodes, cout 100.000 times

    ConcatStringTree *s1 = new ConcatStringTree("Assignment 2 ");
    ConcatStringTree *s2 = new ConcatStringTree("DSA,");
    ConcatStringTree *s3 = new ConcatStringTree(" testcase 18!");
    ConcatStringTree *s4 = new ConcatStringTree(s1 -> concat(*s2));
    ConcatStringTree *s5 = new ConcatStringTree(s4 -> subString(0, s4 ->length()));
    ConcatStringTree *s = new ConcatStringTree(s5 -> concat(*s3));

    for (int i = 0; i < 100000; i++){
        std::cout << "char at index " << s -> length() - 1 << ": "
            << s -> get(s -> length() - 1) << std::endl;
    }
      
}