/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr* testList = new ULListStr();
  testList->push_back("123");
  testList->push_front("456");

  std::string temp1 = testList->back();

  std::cout << temp1 << std::endl;

  testList->push_front("hello");
  testList->pop_back();

  temp1 = testList->front();
  std::cout << temp1 << std::endl;
  return 0;
}
