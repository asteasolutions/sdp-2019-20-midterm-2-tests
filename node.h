#ifndef __NODE_H
#define __NODE_H

#include <string>

template <typename T>
struct Node {
  char data;
  Node *left, *right;

  Node(T const& _data = T(), Node* _left = nullptr, Node* _right = nullptr)
    : data(_data), left(_left), right(_right) {}
};

template <typename T>
std::string printTree(Node<T>* t) {
  std::string s;
  if (t != nullptr) {
    s += '(';
    s += std::to_string(t->data);
    s += printTree(t->left);
    s += printTree(t->right);
    s += ')';
  }
  else
    s += '.';
  return s;
}

template <typename T>
void eraseTree(Node<T>* t) {
  if (t != nullptr) {
    eraseTree(t->left);
    eraseTree(t->right);
    delete t;
  }
}

#endif
