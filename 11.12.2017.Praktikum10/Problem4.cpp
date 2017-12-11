#include<iostream>
#include<math.h>
#include "tree_templ.cpp"
using namespace std;
template<typename T>
void takeElementsOnLevelK(const node<T>* root, int br, T &res, int k)
{ if (root == NULL)
    return;
  
  if (br == k)
  { res = res * 10 + root->inf;
    return;
  }
  
  takeElementsOnLevelK(root->Left, br + 1, res, k);
  takeElementsOnLevelK(root->Right, br + 1, res, k);
}

bool isPalindrome(int nmb)
{ int n = (int)(log10(nmb)) + 1;
  int arr[n], t = 0;
  
  while (nmb != 0)
  { arr[t++] = nmb % 10;
    nmb /= 10;
  }
  
  for (int i = 0; i < n / 2; i++)
    if (arr[i] != arr[n - i - 1])
      return false;
  
  return true;
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
 
      1
    /    \
   3      7   -> true
  / \    /  \
 1   2  2    1
 
 2
*/
