#include "ConcatStringTree.h"

// query không hợp lệ: Invalid character of query
void run() {
  auto s1 = ConcatStringTree("hello");
  try {
    s1.getParTreeSize("???");
  } catch (std::runtime_error &e) {
    std::cout << "run time error: " << e.what();
  } catch (std::exception &e) {
    std::cout << "exception: " << e.what();
  }
}