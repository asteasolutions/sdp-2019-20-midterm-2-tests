#define CHECK_VALID(s)      CHECK(valid(s,error));
#define CHECK_ERROR(s,code) CHECK(!valid(s,error));CHECK_EQ(error,code);

TEST_CASE("Positive tests") {
  unsigned error;

  CHECK_VALID("f(g(x,y),h(k(u)),v)");

  CHECK_VALID("a");
  CHECK_VALID("a(b)");
  CHECK_VALID("a(b,c)");
  CHECK_VALID("a(b(c))");
  CHECK_VALID("a(b(c),d)");
  CHECK_VALID("a(b,c(d),e)");
  CHECK_VALID("a(b(c(d(e)),f),g,h)");
  CHECK_VALID("a(b(c(d(e(f(g(h(i),j),k),l),m),n),o),p)");
  CHECK_VALID("a(b,c(d,e(f,g(h,i(j,k(l,m,n,o))))))");
  CHECK_VALID("a(b(c(d),e(f)),g(h(i),j(k)),l(m(n),o(p)))");
}

TEST_CASE("Negative tests") {
  unsigned error;

  CHECK_ERROR("(f(x),g(x))", 0);
  CHECK_ERROR("f(g(,x)", 4);

  CHECK_ERROR("", 0);
  CHECK_ERROR("(", 0);
  CHECK_ERROR(")", 0);
  CHECK_ERROR(",", 0);
  CHECK_ERROR("?", 0);

  CHECK_ERROR("a)", 1);
  CHECK_ERROR("ab", 1);
  CHECK_ERROR("a,", 1);
  CHECK_ERROR("a?", 1);

  CHECK_ERROR("a()", 2);
  CHECK_ERROR("a(,)", 2);

  CHECK_ERROR("a(bc)", 3);
  CHECK_ERROR("a(b,)", 4);
  CHECK_ERROR("a(b),", 4);
  CHECK_ERROR("a(b()", 4);
  CHECK_ERROR("a(b,(d))", 4);
  CHECK_ERROR("a(b(cd))", 5);
  CHECK_ERROR("a(b(c)", 6);
  CHECK_ERROR("a(b(c),)", 7);
  CHECK_ERROR("a(b(c))(", 7);
  CHECK_ERROR("a(b(c,d),)", 9);
  CHECK_ERROR("a(b(c),d))", 9);
  CHECK_ERROR("a(b(c),d(e(f))", 14);
  CHECK_ERROR("a(b(c),d(e(f))),g(h)", 15);
  CHECK_ERROR("a(b,c(d,e(f,g(h),i),k),l),m)", 25);
}
