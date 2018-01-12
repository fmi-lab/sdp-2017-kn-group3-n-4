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

//Second solution using the template friend function reverseLList of the class LList.
//template<typename T>
//void reverseLList(LList<T> &l)
//{ if (l.length() < 2) return;
//  
//  l.iterStart();
//  elem_link1<T>* prev = NULL;
//  elem_link1<T>* current = l.iter();
//  
//  while (current)
//  { elem_link1<T>* savedLink = current->link;
//    current->link = prev;
//    prev = current;
//    current = savedLink;
//  }
//  
//  elem_link1<T>* t = l.Start;
//  l.Start = l.End;
//  l.End = t;
//}

int main()
{ 
  return 0;
}
