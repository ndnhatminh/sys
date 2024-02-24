#include "ConcatStringTree.h"

void run() {

    // char get(int index) const
    // index < 0

    ConcatStringTree *s1 = new ConcatStringTree("Assignment 2 DSA!");
    
    try {
        std::cout << "char at index -1 of s1: " << s1 -> get(-1) << std::endl;
    }
    catch (out_of_range & ofr){
        std::cout << "Exception out_of_range: " << ofr.what() << std::endl;
    }
}