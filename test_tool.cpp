#include "test_tool.h"

std::vector<std::function<void(void)>> functionList;

void runTest() {
  std::vector<AssertFail> afList;
  
  for (auto fun : functionList) {
    try {
      fun();
    } catch (const AssertFail& af) {
      afList.push_back(af);
    }
  }

  for (auto af : afList)
    std::cerr << af.what() << std::endl;
}
