#include <string>

#include "node.h"

/***********************************************************************
  Задача 4. TBD
************************************************************************/

/***********************************************************************
 РЕШЕНИЕ: а)
************************************************************************/

Node<char>* buildTree (const std::string& s) {
  if (s.empty())
    return nullptr;

  unsigned mid = s.size() / 2;
  std::string L = s.substr(0, mid), R = s.substr(mid + 1);
  return new Node<char>(s[mid], buildTree(L), buildTree(R));
}

/***********************************************************************
 РЕШЕНИЕ: б)
************************************************************************/

void findMaxCount(Node<char>* t, char c, int count, std::string& s, int& max, std::string& maxPath) {
  if (t == nullptr) {
    if (count > max) {
      max = count;
      maxPath = s;
    }
  } else {
    s.push_back(t->data);
    if (t->data == c)
      count++;
    findMaxCount(t->left , c, count, s, max, maxPath);
    findMaxCount(t->right, c, count, s, max, maxPath);
    if (t->data == c)
      count--;
    s.pop_back();
  }
}

std::string countMax(Node<char>* t, char c) {
  std::string empty, result;
  int max = 0;
  findMaxCount(t, c, 0, empty, max, result);
  return result;
}

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
#include "prob4_tests.h"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
