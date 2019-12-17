#include <string>

#include "node.h"

/***********************************************************************
  Задача 4. Даден е символен низ s. Казваме, че двоичното дърво със
  символи по върховете t представя s при следните условия:

    * s е празният низ и t е празното дърво; или
    * ако s = s[0]…s[k-1], a m = ⌊k / 2⌋ (долна цяла част), то коренът
    на t съдържа символа s[m], лявото поддърво на t представя низа
    s[0]…s[m-1], а дясното поддърво на t представя низа s[m+1]…s[k-1].

  Забележка: ако k = 2, то десния низ считаме за празен.

  Нека е даден шаблонът на структурата Node описан в node.h.
************************************************************************/

/***********************************************************************
 а) Да се реализира функция, която построява дърво, представящо низа
 s, и връща указател към корена му.

 Упътване: Можете да ползвате метода std::string::substr(pos, count),
 който връща подниз, започващ със символа с индекс pos и с count на
 брой елемента. Ако пропуснете параметъра count, ще получавите суфикс
 на дадения низ от позиция pos до края на низа.

 Пример: std::string("abcde").substr(1, 3) → "bcd",
 std::string("abcde").substr(3) → "de".

 РЕШЕНИЕ:
************************************************************************/

Node<char>* buildTree (const std::string& s);

/***********************************************************************
 б) Да се реализира функция, която връща низ, съставен от възлите по
 път в дървото от корен до листо, в който брой на срещанията на
 символа c е максимален.

 РЕШЕНИЕ: б)
************************************************************************/

std::string countMax(Node<char>* t, char c);

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
//#include "prob4_tests.h"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
