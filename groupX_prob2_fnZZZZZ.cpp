#include <vector>

#include "node.h"

/***********************************************************************
  Задача 2. TBD
************************************************************************/

/***********************************************************************
 РЕШЕНИЕ: а)
************************************************************************/

Node<unsigned>* buildTree (const std::vector<unsigned>& v) {
  if (v.empty())
    return nullptr;

  unsigned mid = v.size() / 2;
  std::vector<unsigned>  L(v.begin(), v.begin() + mid), R(v.begin() + mid + 1, v.end());
  return new Node<unsigned>(v[mid], buildTree(L), buildTree(R));
}

/***********************************************************************
 РЕШЕНИЕ: б)
************************************************************************/

void findMaxSum(Node<unsigned>* t, unsigned sum, std::vector<unsigned>& v, unsigned& max, std::vector<unsigned>& maxPath) {
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

std::vector<unsigned> sumMax(Node<unsigned>* t) {
  std::vector<unsigned> empty, result;
  unsigned max = 0;
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
