#include<iostream>
#include "llist.cpp"
using namespace std;
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
  elem_link1<T>* it = l.iter();
  
  ind = 0;
  while (it)
  { l.insertAfter(it, arr[ind++]);
    
    elem_link1<T>* save = it;
    it = l.iter(); //<=> it = it->link->link;
    
    T _;
    l.deleteElem(save, _);
  }
}

int main()
{ 
  return 0;
}
