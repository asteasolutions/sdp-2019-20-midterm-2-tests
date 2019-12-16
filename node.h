#ifndef __NODE_H
#define __NODE_H

template <typename T>
struct Node {
  char data;
  Node *left, *right;

  Node(T const& _data = T(), Node* _left = nullptr, Node* _right = nullptr)
    : data(_data), left(_left), right(_right) {}
};


#endif
