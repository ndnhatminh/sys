#include "ConcatStringTree.h"

void run() {

    // char get(int index) const
    // index = length - 1

    ConcatStringTree *s1 = new ConcatStringTree("DSA!");
    ConcatStringTree *s2 = new ConcatStringTree("987654321");

    std::cout << "char at index " << s1 -> length() - 1 << " of s1: "
        << s1 -> get(s1 -> length() - 1) << std::endl;

    std::cout << "char at index " << s2 -> length() - 1 << " of s2: "
        << s2 -> get(s2 -> length() - 1) << std::endl;
}