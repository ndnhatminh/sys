#include "ConcatStringTree.h"

void run() {

    // char get(int index) const
    // index = 0

    ConcatStringTree *s1 = new ConcatStringTree("!DSA");
    ConcatStringTree *s2 = new ConcatStringTree("987654321");
    

    std::cout << "char at index 0 of s1: " << s1 -> get(0) << std::endl;
    std::cout << "char at index 0 of s2: " << s2 -> get(0) << std::endl;
}