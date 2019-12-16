TEST_CASE("Positive tests") {
  unsigned error;

  CHECK("(a->b->b)->b->a->b", error);

  CHECK(valid("a", error));
  CHECK(valid("a->b", error));
  CHECK(valid("(a->b)", error));
  CHECK(valid("(((((a->b)))))", error));
  CHECK(valid("a->b->c", error));
  CHECK(valid("(a->b->c)", error));
  CHECK(valid("(a->b)->c", error));
  CHECK(valid("((((a->b))))->c", error));
  CHECK(valid("((a->b)->c)->d", error));
  CHECK(valid("((((a->b))->c))->d", error));
  CHECK(valid("(a->b)->c->d->(e->f)->g", error));
  CHECK(valid("((a->(b->c)->d)->(e->f->g)->(h->i)->k->l->m", error));
}

TEST_CASE("Negative tests") {
  unsigned error;

  CHECK(!valid("a->b(->c)", error) && error == 4);
  CHECK(!valid("(a->(b)->b)", error) && error == 6);

  CHECK(!valid("", error) && error == 0);
  CHECK(!valid(")", error) && error == 0);
  CHECK(!valid("-", error) && error == 0);
  CHECK(!valid("?", error) && error == 0);

  CHECK(!valid("(", error) && error == 1);
  CHECK(!valid("a)", error) && error == 1);
  CHECK(!valid("a-", error) && error == 1);
  CHECK(!valid("a>", error) && error == 1);

  CHECK(!valid("(a)", error) && error == 2);
  CHECK(!valid("(a>", error) && error == 2);

  CHECK(!valid("a->)", error) && error == 3);
  CHECK(!valid("a->->)", error) && error == 3);
  CHECK(!valid("a->bc", error) && error == 4);
  CHECK(!valid("(a->b", error) && error == 5);
  CHECK(!valid("a->(b)->c", error) && error == 5);
  CHECK(!valid("a->b->", error) && error == 6);
  CHECK(!valid("a->b->cd", error) && error == 7);
  CHECK(!valid("a->(b->)c", error) && error == 7);
  CHECK(!valid("a->(b->c)", error) && error == 9);

  CHECK(!valid("(a->b)->c)", error) && error == 9);
  CHECK(!valid("(a->(b->c))", error) && error == 10);
  CHECK(!valid("a->(b->c->d)->e)", error) && error == 15);
  CHECK(!valid("(a->b->c)->((d->e)->f)", error) && error == 22);

}
