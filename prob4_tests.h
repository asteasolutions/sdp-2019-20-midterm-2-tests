void checkAndErase(std::string const& v, std::string s) {
  Node<char>* t = buildTree(v);
  CHECK_EQ(printTree(t), s);
  eraseTree(t);
}

TEST_CASE("buildTree tests") {
  checkAndErase("", ".");
  checkAndErase("1", "(1..)");
  checkAndErase("12", "(2(1..).)");
  checkAndErase("123", "(2(1..)(3..))");
  checkAndErase("1234", "(3(2(1..).)(4..))");
  checkAndErase("12345", "(3(2(1..).)(5(4..).))");
  checkAndErase("123456", "(4(2(1..)(3..))(6(5..).))");
  checkAndErase("1234567", "(4(2(1..)(3..))(6(5..)(7..)))");
  checkAndErase("12345678", "(5(3(2(1..).)(4..))(7(6..)(8..)))");
}

TEST_CASE("countMax tests") {
  Node<char>* t = nullptr;
  CHECK_EQ(countMax(t, 'a'), "");
  t = new Node<char>('a');
  CHECK_EQ(countMax(t, 'a'), "a");
  t->left = new Node<char>('b');
  CHECK_EQ(countMax(t, 'a'), "ab");
  t->right = new Node<char>('a');
  CHECK_EQ(countMax(t, 'a'), "aa");
  t->left->right = new Node<char>('c');
  CHECK_EQ(countMax(t, 'a'), "aa");
  CHECK_EQ(countMax(t, 'c'), "abc");
  t->left->left = new Node<char>('b');
  CHECK_EQ(countMax(t, 'b'), "abb");
  t->right->left = new Node<char>('a');
  CHECK_EQ(countMax(t, 'a'), "aaa");
  t->right->right = new Node<char>('b');
  CHECK_EQ(countMax(t, 'a'), "aaa");
  CHECK_EQ(countMax(t, 'b'), "abb");
  eraseTree(t);
}
