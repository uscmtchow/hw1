/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
	
  ULListStr* testList = new ULListStr();
  testList->push_back("123");
  testList->push_front("456");

  std::cout <<  testList->back() << std::endl;

  testList->push_front("hello");
  testList->pop_back();
	testList->pop_front();

  std::cout << testList->front() << std::endl;

	std::cout << testList->get(0) << std::endl;

	return 0;
}
