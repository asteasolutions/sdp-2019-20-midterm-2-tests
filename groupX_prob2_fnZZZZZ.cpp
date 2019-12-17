#include <vector>

#include "node.h"

/***********************************************************************
  Задача 2. TBD
************************************************************************/

/***********************************************************************
 РЕШЕНИЕ: а)
************************************************************************/

Node<int>* buildTree (const std::vector<int>& v);

/***********************************************************************
 РЕШЕНИЕ: б)
************************************************************************/

std::vector<int> sumMax(Node<int>* t);

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
//#include "prob2_tests.h"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
