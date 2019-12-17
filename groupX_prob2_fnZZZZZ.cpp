#include <vector>

#include "node.h"

/***********************************************************************
  Задача 2. TBD
************************************************************************/

/***********************************************************************
 РЕШЕНИЕ: а)
************************************************************************/

Node<int>* buildTree (const std::vector<int>& v) {
  if (v.empty())
    return nullptr;

  unsigned mid = v.size() / 2;
  std::vector<int>  L(v.begin(), v.begin() + mid), R(v.begin() + mid + 1, v.end());
  return new Node<int>(v[mid], buildTree(L), buildTree(R));
}

/***********************************************************************
 РЕШЕНИЕ: б)
************************************************************************/

void findMaxSum(Node<int>* t, int sum, std::vector<int>& v, int& max, std::vector<int>& maxPath) {
  if (t == nullptr) {
    if (sum > max) {
      max = sum;
      maxPath = v;
    }
  } else {
    v.push_back(t->data);
    findMaxSum(t->left , sum + t->data, v, max, maxPath);
    findMaxSum(t->right, sum + t->data, v, max, maxPath);
    v.pop_back();
  }
}

std::vector<int> sumMax(Node<int>* t) {
  std::vector<int> empty, result;
  int max = 0;
  findMaxSum(t, 0, empty, max, result);
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
#include "prob2_tests.h"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
