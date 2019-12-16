#define CHECK_VALID(s)      CHECK(valid(s,error));
#define CHECK_ERROR(s,code) CHECK(!valid(s,error));CHECK_EQ(error,code);

TEST_CASE("Positive tests") {
  unsigned error;

  CHECK_VALID("(a->b->b)->b->a->b");

  CHECK_VALID("a");
  CHECK_VALID("a->b");
  CHECK_VALID("(a->b)");
  CHECK_VALID("a->b->c");
  CHECK_VALID("(a->b->c)");
  CHECK_VALID("(a->b)->c");
  CHECK_VALID("((a->b)->c)->d");
  CHECK_VALID("((a->b)->(c->d)->e)->f");
  CHECK_VALID("(a->b)->c->d->(e->f)->g");
  CHECK_VALID("((a->(b->c)->d)->(e->f->g)->(h->i)->k)->l->m");
}

TEST_CASE("Negative tests") {
  unsigned error;

  CHECK_ERROR("a->b(->c)", 4);
  CHECK_ERROR("(a->(b)->b)", 6);

  CHECK_ERROR("", 0);
  CHECK_ERROR(")", 0);
  CHECK_ERROR("-", 0);
  CHECK_ERROR("?", 0);

  CHECK_ERROR("(", 1);
  CHECK_ERROR("a)", 1);
  CHECK_ERROR("a>", 1);

  CHECK_ERROR("a-", 2);
  CHECK_ERROR("(a)", 2);
  CHECK_ERROR("(a>", 2);

  CHECK_ERROR("a->)", 3);
  CHECK_ERROR("a->->)", 3);
  CHECK_ERROR("a->bc", 4);
  CHECK_ERROR("(a->b", 5);
  CHECK_ERROR("a->(b)->c", 5);
  CHECK_ERROR("a->b->", 6);
  CHECK_ERROR("a->b->cd", 7);
  CHECK_ERROR("a->(b->)c", 7);
  CHECK_ERROR("((a->b))", 7);
  CHECK_ERROR("a->(b->c)", 9);

  CHECK_ERROR("(a->b)->c)", 9);
  CHECK_ERROR("(a->(b->c))", 10);
  CHECK_ERROR("a->(b->c->d)->e)", 15);
  CHECK_ERROR("(a->b->c)->((d->e)->f)", 22);
}
