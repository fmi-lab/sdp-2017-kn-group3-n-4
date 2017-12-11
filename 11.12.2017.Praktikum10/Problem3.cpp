#include<iostream>
#include "tree_templ.cpp"
using namespace std;
template<typename T>
bool check(const node<T>* root1, const node<T>* root2)
{ if (root1 == NULL && root2 != NULL)
    return false;
  
  if (root1 != NULL && root2 == NULL)
    return false;
  
  if (root1 == NULL && root2 == NULL)
    return true;
  
  return root1->inf == root2->inf && check(root1->Left, root2->Right) && check(root1->Right, root2->Left);
}

int main()
{ 
  return 0;
}
/*
   1
  / \     -> false
 2   3
 
     1
    / \
   2   2   -> true
  /     \
 3       3
*/
