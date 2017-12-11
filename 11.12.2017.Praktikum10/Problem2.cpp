#include<iostream>
#include "tree_templ.cpp"
using namespace std;
template<typename T>
int getCount(const node<T>* root)
{ if (root == NULL)
    return 0;
  
  return 1 + getCount(root->Left) + getCount(root->Right);
}

int calculate(const node<int>* rootI, const node<char>* rootC)
{ if (rootI == NULL)
    return 0;
  
  int currentElement;
  if (rootC->inf == '+')
    currentElement = rootI->inf + getCount(rootI);
  
  else if (rootC->inf == '-')
    currentElement = rootI->inf - getCount(rootI);
  
  else currentElement = rootI->inf * getCount(rootI);
  
  return currentElement + calculate(rootI->Left, rootC->Left) + calculate(rootI->Right, rootC->Right);
}

int main()
{ 
  return 0;
}
/*
   1
  / \
 2   3
 
   +
  / \
 +   *
 
 (1 + 3) + (2 + 1) + (3 * 1) = 4 + 3 + 3 = 10
*/
