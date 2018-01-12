#include<iostream>
#include "tree_templ.cpp"
template<typename T>
int height(const node<T>* root)
{ if (root == NULL)
    return 0;
  
  return 1 + max(height(root->Left), height(root->Right));
}

template<typename T>
int findDiameter(const node<T>* root)
{ if (root == NULL)
    return 0;
  
  return max(max(1 + height(root->Left) + height(root->Right), findDiameter(root->Left)), findDiameter(root->Right));
}

using namespace std;
int main()
{ 
  tree<int> t;
  t.Create();
  
  cout << findDiameter(t.getRoot()) << endl;
  
  return 0;
}
