void checkAndErase(std::string const& v, std::string s) {
  Node<char>* t = buildTree(v);
  CHECK_EQ(printTree(t), s);
  eraseTree(t);
}

TEST_CASE("buildTree tests") {
  checkAndErase("", ".");
  checkAndErase("1", "(49..)");
  checkAndErase("12", "(50(49..).)");
  checkAndErase("123", "(50(49..)(51..))");
  checkAndErase("1234", "(51(50(49..).)(52..))");
  checkAndErase("12345", "(51(50(49..).)(53(52..).))");
  checkAndErase("123456", "(52(50(49..)(51..))(54(53..).))");
  checkAndErase("1234567", "(52(50(49..)(51..))(54(53..)(55..)))");
  checkAndErase("12345678", "(53(51(50(49..).)(52..))(55(54..)(56..)))");
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
