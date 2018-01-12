#include<iostream>
#include "tree_templ.cpp"
using namespace std;
template<typename T>
int sizeOfTree(const node<T>* root)
{ if (root == NULL)
    return 0;
  
  return 1 + sizeOfTree(root->Left) + sizeOfTree(root->Right);
}

template<typename T>
bool isBinarySearchTree(const node<T>* root)
{ if (root == NULL)
    return true;
  
  if (root->Left != NULL && root->Right == NULL)
    return root->Left->inf <= root->inf && isBinarySearchTree(root->Left);
  
  if (root->Left == NULL && root->Right != NULL)
    return root->inf < root->Right->inf && isBinarySearchTree(root->Right);
  
  if (root->Left == NULL && root->Right == NULL)
    return true;
  
  return root->Left->inf <= root->inf && root->inf < root->Right->inf && isBinarySearchTree(root->Left) && isBinarySearchTree(root->Right);
}

template<typename T>
int biggestBinarySearchSubtree(const node<T>* root)
{ if (root == NULL)
    return 0;
  
  bool BST = isBinarySearchTree(root);
  int current = (int)(BST) * sizeOfTree(root);
  
  return max(max(current, biggestBinarySearchSubtree(root->Left)), biggestBinarySearchSubtree(root->Right));
}

int main()
{ 
  tree<int> t;
  t.Create();
  
  cout << biggestBinarySearchSubtree(t.getRoot()) << endl;
  
  return 0;
}
