#include "../templates/tree.cpp"
#include <iostream>

using namespace std;


struct OpNode {
  char operation;
  int value;

  OpNode() {
    this->operation = 0;
    this->value = 0;
  }

  OpNode(char operation) {
    this->operation = operation;
    this->value = 0;
  }

  OpNode(int value) {
    this->operation = 0;
    this->value = value;
  }

  bool isOperation() {
    return this->operation != 0;
  }
};

int calculate(const tree<OpNode>& t) {
  if (t.empty()) {
    return 0;
  }

  if (!(t.getRoot()->inf).isOperation()) {
    return (t.getRoot()->inf).value;
  }

  int left = calculate(t.LeftTree());
  int right = calculate(t.RightTree());

  switch ((t.getRoot()->inf).operation) {
    case '*': return left * right;
    case '+': return left + right;
    case '-': return left - right;
    case '/': return right == 0 ? 0 : left / right;
    default: return 0;
  }
}

int main() {
  tree<OpNode> t10;
  t10.Create3(OpNode(10), tree<OpNode>(), tree<OpNode>());

  tree<OpNode> t3;
  t3.Create3(OpNode(3), tree<OpNode>(), tree<OpNode>());

  tree<OpNode> t5;
  t5.Create3(OpNode(5), tree<OpNode>(), tree<OpNode>());

  tree<OpNode> t2;
  t2.Create3(OpNode(2), tree<OpNode>(), tree<OpNode>());

  tree<OpNode> t_1;
  t_1.Create3(OpNode('-'), t10, t3);

  tree<OpNode> t_2;
  t_2.Create3(OpNode('+'), t2, t5);

  tree<OpNode> t;
  t.Create3(OpNode('*'), t_2, t_1);

  cout << calculate(t) << " == 49" << endl;
}