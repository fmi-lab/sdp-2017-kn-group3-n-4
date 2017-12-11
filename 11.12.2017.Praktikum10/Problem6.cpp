#include<iostream>
#include"binOrdTree.cpp"
using namespace std;
template<typename T>
bool isBST(const node_bin<T>* root)
{ if (root == NULL)
    return true;
  
  if (root->left != NULL && root->right == NULL)
    return root->left->inf <= root->inf && isBST(root->left);
  
  if (root->left == NULL && root->right != NULL)
    return root->right->inf > root->inf && isBST(root->right);
  
  if (root->left == NULL && root->right == NULL)
    return true;
  
  return root->left->inf <= root->inf && root->right->inf > root->inf && isBST(root->left) && isBST(root->right);
}

int main()
{ 
  binOrdTree<int> t;
  t.addNode(5);
  t.addNode(2);
  t.addNode(1);
  t.addNode(3);
  t.addNode(7);
  t.addNode(9);
  t.addNode(6);
  
  binOrdTree<int> t1;
  t1.create3(1, binOrdTree<int>(), binOrdTree<int>());
  
  binOrdTree<int> t2;
  t2.create3(2, binOrdTree<int>(), binOrdTree<int>());
  
  binOrdTree<int> t3;
  t3.create3(3, t1, t2);
  
  cout << boolalpha;
  cout << isBST(t.getRootPointer()) << endl;
  cout << isBST(t3.getRootPointer()) << endl;
  
  return 0;
}
