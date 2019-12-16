#include <string>
#include <stack>

/***********************************************************************
  Задача 1. TBD
************************************************************************/

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/

bool isLetter (char c) { return 'a' <= c && c <= 'z'; }
bool isLetterQ(char c) { return isLetter(c) || c == '?'; }

bool valid(const std::string& s, unsigned& error) {
  unsigned& i = error;
  std::stack<char> stack;
  for(i = 0; i < s.size(); ++i)
    if (s[i] == '(') {
      if (stack.empty() || !isLetter(stack.top()))
        return false;
      stack.push(s[i]);
    }
    else if (isLetter(s[i])) {
      if (!stack.empty() && stack.top() != '(')
        return false;
      stack.push(s[i]);
    }
    else if (s[i] == ',') {
      if (stack.empty() || !isLetterQ(stack.top()))
        return false;
      stack.pop();
      if (stack.empty() || stack.top() != '(')
        return false;
    }
    else if (s[i] == ')') {
      if (stack.empty() || !isLetterQ(stack.top()))
        return false;
      stack.pop();
      if (stack.empty() || stack.top() != '(')
        return false;
      stack.pop();
      if (stack.empty() || !isLetter(stack.top()))
        return false;
      stack.pop();
      stack.push('?');
    }
    else return false;
  if (stack.empty() || !isLetterQ(stack.top()))
    return false;
  stack.pop();
  return stack.empty();
}

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
#include "prob1_tests.h"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
