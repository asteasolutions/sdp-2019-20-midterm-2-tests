namespace doctest
{
  template <typename T>
  struct StringMaker<std::vector<T>>
  {
    static String convert(const std::vector<T>& v) {
      std::ostringstream oss;

      oss << "{ ";
      for (auto el : v)
        {
          oss << el << " ";
        }
      oss << "}";

      return oss.str().c_str();
    }
  };
}

void checkAndErase(std::vector<int> const& v, std::string s) {
  Node<int>* t = buildTree(v);
  CHECK_EQ(printTree(t), s);
  eraseTree(t);
}

TEST_CASE("buildTree tests") {
  checkAndErase({}, ".");
  checkAndErase({1}, "(1..)");
  checkAndErase({1,2}, "(2(1..).)");
  checkAndErase({1,2,3}, "(2(1..)(3..))");
  checkAndErase({1,2,3,4}, "(3(2(1..).)(4..))");
  checkAndErase({1,2,3,4,5}, "(3(2(1..).)(5(4..).))");
  checkAndErase({1,2,3,4,5,6}, "(4(2(1..)(3..))(6(5..).))");
  checkAndErase({1,2,3,4,5,6,7}, "(4(2(1..)(3..))(6(5..)(7..)))");
  checkAndErase({1,2,3,4,5,6,7,8}, "(5(3(2(1..).)(4..))(7(6..)(8..)))");
}

TEST_CASE("sumMax tests") {
  Node<int>* t = nullptr;
  CHECK_EQ(sumMax(t), std::vector<int>{});
  t = new Node<int>(1);
  CHECK_EQ(sumMax(t), std::vector<int>{1});
  t->left = new Node<int>(3);
  CHECK_EQ(sumMax(t), std::vector<int>{1, 3});
  t->right = new Node<int>(10);
  CHECK_EQ(sumMax(t), std::vector<int>{1, 10});
  t->left->right = new Node<int>(5);
  CHECK_EQ(sumMax(t), std::vector<int>{1, 10});
  t->left->left = new Node<int>(8);
  CHECK_EQ(sumMax(t), std::vector<int>{1, 3, 8});
  t->right->left = new Node<int>(4);
  CHECK_EQ(sumMax(t), std::vector<int>{1, 10, 4});
  t->right->right = new Node<int>(2);
  CHECK_EQ(sumMax(t), std::vector<int>{1, 10, 4});
  eraseTree(t);
}
