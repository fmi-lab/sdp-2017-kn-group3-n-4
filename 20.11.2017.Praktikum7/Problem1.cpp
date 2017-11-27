#include<iostream>
#include "../13.11.2017/zad1.cpp"
using namespace std;
template<typename T>
bool isXInTheList(LList<T> &l, const T &x)
{ l.iterStart();
  elem_link1<T>* it = l.iter();
  
  while (it)
  { if (it->inf == x)
      return true;
    
    it = l.iter();
  }
  
  return false;
}

template<typename T>
bool alreadyInList(const T &x, T arr[], int s) //x is the element which we search; s is the size of arr (i.e. the number of elements in arr)
{ for (int i = 0; i < s; i++)
    if (arr[i] == x)
      return true;
  
  return false;
}

template<typename T>
bool differentElementsInList(LList<T> &l)
{ int n = l.length();
  if (n == 0)
    return false;
  
  T arr[n];
  int s = 0;
  
  l.iterStart();
  elem_link1<T>* it = l.iter();
  
  while (it)
  { if (alreadyInList(it->inf, arr, s) == true)
      return false;
    
    arr[s++] = it->inf;
    it = l.iter();
  }
  
  return true;
}

template<typename T>
int increasingOrDecreasingOrOther(LList<T> &l) //Function returns -1 if elements are in decreasing order, 1 if they are in increasing order and 0 otherwise.
{ l.iterStart();
  elem_link1<T>* it1 = l.iter();
  elem_link1<T>* it2 = l.iter();
  
  if (it2 == NULL) //If we have only one element in the list, we can return -1, 0 or 1 - all will be correct.
    return 1;
  
  bool increasing = false, decreasing = false;
  
  if (it1->inf <= it2->inf)
    increasing = true;
  
  else decreasing = true;
  
  while (it2)
  { if (increasing == true)
    { if (it1->inf > it2->inf)
        return 0;
    }
    
    else if (decreasing == true)
    { if (it1->inf <= it2->inf)
        return 0;
    }
    
    it1 = it2;
    it2 = l.iter();
  }
  
  if (increasing == true)
    return 1;
  
  return -1; //Elements in the list are neither in increasing order, nor they have no order. So they are in decreasing order.
}

template<typename T>
void moveListToArray(LList<T> &l, T arr[])
{ l.iterStart();
  elem_link1<T>* it = l.iter();
  
  int ind = 0;
  while (it)
  { arr[ind++] = it->inf;
    it = l.iter();
  }
}

template<typename T>
void selectionSort(T arr[], int n)
{ for (int i = 0; i < n - 1; i++)
  { int j = i, minn = arr[i];
    for (int k = j + 1; k < n; k++)
      if (minn > arr[k])
      { minn = arr[k];
        j = k;
      }
    
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
  }
}

template<typename T>
void sortLList(LList<T> &l)
{ int n = l.length(), ind = 0;
  T arr[n];
  
  moveListToArray(l, arr);
  selectionSort(arr, n);
  
  l.iterStart();
  elem_link1<T>* it;
  it = l.iter();
  
  ind = 0;
  while (it)
  { l.insertAfter(it, arr[ind++]);
    
    elem_link1<T>* save = it;
    it = l.iter(); //<=> it = it->link->link;
    
    T _;
    l.deleteElem(save, _);
  }
}

template<typename T>
void reverseLList(LList<T> &l)
{ int n = l.length(), ind = 0;
  T arr[n];
  
  moveListToArray(l, arr);
  ind = n;
  
  l.iterStart();
  elem_link1<T>* it = l.iter();
  
  while (it)
  { l.insertAfter(it, arr[--ind]);
    
    elem_link1<T>* save = it;
    it = l.iter();
    
    T _;
    l.deleteElem(save, _);
  }
}

template<typename T>
void concatLists(LList<T> &l1, LList<T> &l2)
{ l2.iterStart();
  elem_link1<T>* it = l2.iter();
  
  while (it)
  { l1.toEnd(it->inf);
    it = l2.iter();
  }
}

template<typename T>
void intersectOrSubtractArrays(T arr1[], T arr2[], int n1, int n2, LList<T> &l3, bool isIntersection)
{ for (int i = 0; i < n1; i++)
  { bool ok = false;
    for (int j = 0; j < n2; j++)
      if (arr1[i] == arr2[j])
      { ok = true;
        break;
      }
    
    if (ok == isIntersection)
      l3.toEnd(arr1[i]);
  }
}

template<typename T>
void intersection(LList<T> &l1, LList<T> &l2, LList<T> &l3)
{ int n1 = l1.length(), n2 = l2.length();
  T arr1[n1], arr2[n2];
  
  moveListToArray(l1, arr1);
  moveListToArray(l2, arr2);
  
  intersectOrSubtractArrays(arr1, arr2, n1, n2, l3, true);
}

template<typename T>
void subtraction(LList<T> &l1, LList<T> &l2, LList<T> &l3)
{ int n1 = l1.length(), n2 = l2.length();
  T arr1[n1], arr2[n2];
  
  moveListToArray(l1, arr1);
  moveListToArray(l2, arr2);
  
  intersectOrSubtractArrays(arr1, arr2, n1, n2, l3, false);
}

template<typename T>
void Union(LList<T> &l1, LList<T> &l2, LList<T> &l3)
{ LList<T> l4, l5, l6;
  intersection(l1, l2, l4);
  subtraction(l1, l2, l5);
  subtraction(l2, l1, l6);
  
  concatLists(l3, l4);
  concatLists(l3, l5);
  concatLists(l3, l6);
}

int main()
{ 
  return 0;
}
