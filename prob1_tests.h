TEST_CASE("Positive tests") {
  unsigned error;

  CHECK("f(g(x,y),h(k(u)),v)", error);

  CHECK(valid("a", error));
  CHECK(valid("a(b)", error));
  CHECK(valid("a(b,c)", error));
  CHECK(valid("a(b(c))", error));
  CHECK(valid("a(b(c),d)", error));
  CHECK(valid("a(b,c(d),e)", error));
  CHECK(valid("a(b(c(d(e)),f),g,h)", error));
  CHECK(valid("a(b(c(d(e(f(g(h(i),j),k),l),m),n),o),p)", error));
  CHECK(valid("a(b,c(d,e(f,g(h,i(j,k(l,m,n,o))))))"), error);
  CHECK(valid("a(b(c(d),e(f)),g(h(i),j(k)),l(m(n),o(p)))", error));
}

TEST_CASE("Negative tests") {
  unsigned error;

  CHECK(!valid("(f(x),g(x))", error) && error == 0);
  CHECK(!valid("f(g(,x)", error) && error == 4);

  CHECK(!valid("", error) && error == 0);
  CHECK(!valid("(", error) && error == 0);
  CHECK(!valid(")", error) && error == 0);
  CHECK(!valid(",", error) && error == 0);
  CHECK(!valid("?", error) && error == 0);

  CHECK(!valid("a)", error) && error == 1);
  CHECK(!valid("ab", error) && error == 1);
  CHECK(!valid("a,", error) && error == 1);
  CHECK(!valid("a?", error) && error == 1);

  CHECK(!valid("a()", error) && error == 2);
  CHECK(!valid("a(,)", error) && error == 2);

  CHECK(!valid("a(b,)", error) && error == 3);
  CHECK(!valid("a(bc)", error) && error == 3);
  CHECK(!valid("a(b),", error) && error == 4);
  CHECK(!valid("a(b()", error) && error == 4);
  CHECK(!valid("a(b,(d))", error) && error == 4);
  CHECK(!valid("a(b(cd))", error) && error == 5);
  CHECK(!valid("a(b(c)", error) && error == 6);
  CHECK(!valid("a(b(c),)", error) && error == 7);
  CHECK(!valid("a(b(c))(", error) && error == 7);
  CHECK(!valid("a(b(c,d),)", error) && error == 8);
  CHECK(!valid("a(b(c),d))", error) && error == 9);
  CHECK(!valid("a(b(c),d(e(f))", error) && error == 14);
  CHECK(!valid("a(b(c),d(e(f))),g(h)", error) && error == 15);
  CHECK(!valid("a(b,c(d,e(f,g(h),i),k),l),m)", error) && error == 25);
}
