#include<iostream>
#include "tree_templ.cpp"
using namespace std;
template<typename T>
bool findWord(const node<T>* root, char word[], int n, int i = 0)
{ if (root == NULL)
    return false;
  
  if (root != NULL && root->Left == NULL && root->Right == NULL)
    return root->inf == word[i] - '0' && i == n - 1;
  
  if (i == n)
    return false;
  
  if (root->inf == word[i] - '0')
    return findWord(root->Left, word, n, i + 1) || findWord(root->Right, word, n, i + 1);
  
  return false;
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
  
  cout << boolalpha << findWord(t.getRoot(), "6345", 4) << endl;
  
  return 0;
}
