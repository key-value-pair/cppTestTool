#include "test_tool.h"

std::vector<std::function<void(void)>> functionList;

void runTest() {
  std::vector<AssertFail> afList;
  std::vector<bool> passList;
  
  for (auto fun : functionList) {
    try {
      fun();
      passList.push_back(true);
    } catch (const AssertFail& af) {
      afList.push_back(af);
      passList.push_back(false);
    }
  }

  std::cerr << "all: " << functionList.size()
	    << ", fail: " << afList.size()
	    << ", pass: " << (functionList.size()-afList.size())
	    << std::endl;

  for (auto p : passList)
    std::cerr << (p ? "." : "x");
  std::cerr << std::endl;
  
  for (auto af : afList)
    std::cerr << af.what() << std::endl;
}
