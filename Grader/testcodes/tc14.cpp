#include "ConcatStringTree.h"

void run() {

    // char get(int index) const
    // index > length

    ConcatStringTree *s1 = new ConcatStringTree("DSA!");
    
    try {
        std::cout << "char at index " << s1 -> length() + 1 << " of s1: "
            << s1 -> get(s1 -> length() + 1) << std::endl;
    }
    catch (out_of_range & ofr){
        std::cout <<"Exception out_of_range: " << ofr.what() << std::endl;
    }
}