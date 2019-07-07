#ifndef TEST_TOOL_H
#define TEST_TOOL_H

#include <exception>
#include <string>
#include <vector>
#include <functional>
#include <iostream>

class AssertFail : public std::exception {
 public:
  AssertFail(const std::string& msg, const std::string& filename,
	     const std::string& funcname, int line)
    : m_msg{msg}, m_filename{filename}, m_funcname{funcname}, m_line{line} {}
  const char* what() const noexcept {
    static std::string format_msg;

    format_msg = "[" + m_filename + "]"
      + "[" + m_funcname + "]"
      + "[" + std::to_string(m_line) + "]: "
      + m_msg;

    return format_msg.c_str();
  }
 private:
  const std::string m_msg;
  const std::string m_filename;
  const std::string m_funcname;
  const int m_line;
};

extern std::vector<std::function<void(void)>> functionList;

class RegisterTest {
 public:
  RegisterTest(std::function<void(void)> fun) {
    functionList.push_back(fun);
  }
};

void runTest();

#define AssertEqual(actual, expect, msg)			\
  do {								\
    if (!((actual) == (expect))) {				\
      throw AssertFail(msg, __FILE__, __FUNCTION__, __LINE__);	\
    }								\
  } while (0)

#define AssertTrue(cond, msg)					\
  do {								\
    if (!(cond)) {						\
      throw AssertFail(msg, __FILE__, __FUNCTION__, __LINE__);	\
    }								\
  } while (0)

#define ADD_TEST(fun)				\
  static const RegisterTest RegisterTest##fun{fun};

#endif // TEST_TOOL_H
