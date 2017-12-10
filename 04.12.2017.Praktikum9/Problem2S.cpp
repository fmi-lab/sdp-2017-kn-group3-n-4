#include<iostream>
#include "tree_templ.cpp"
using namespace std;
template<typename T>
bool findSum(const node<T>* root, int sum, int currentSum = 0)
{ if (currentSum > sum)
    return false;
  
  if (sum == currentSum)
    return true;
  
  if (root == NULL)
    return 0;
  
  return findSum(root->Left, sum, currentSum + root->inf) || findSum(root->Right, sum, currentSum + root->inf);
}

int main()
{ 
  tree<int> tree1;
  tree1.Create3(1, tree<int>(), tree<int>());

  tree<int> tree5;
  tree5.Create3(5, tree<int>(), tree<int>());

  tree<int> tree2;
  tree2.Create3(2, tree1, tree<int>());

  tree<int> tree4;
  tree4.Create3(4, tree<int>(), tree5);

  tree<int> tree3;
  tree3.Create3(3, tree2, tree4);

  tree<int> tree7;
  tree7.Create3(7, tree<int>(), tree<int>());

  tree<int> t;
  t.Create3(6, tree3, tree7);
  
  cout << boolalpha << findSum(t.getRoot(), 18) << endl;
  
  return 0;
}
