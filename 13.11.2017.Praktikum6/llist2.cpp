#include<iostream>
#include<cassert>
using namespace std;
template<typename T>
struct elem_link1
{ T inf;
  elem_link1<T>* link;
};

template<typename T>
class LList
{ private:
  elem_link1<T>* Start;
  elem_link1<T>* End;
  elem_link1<T>* Current;
  
  void Copy(const LList<T>&);
  void Erase();
  
  public:
  LList();
  LList(const LList<T>&);
  ~LList();
  LList<T>& operator=(const LList<T>&);
  
  void iterStart(elem_link1<T>* = NULL);
  elem_link1<T>* iter();
  
  void toEnd(const T&);
  void insertBefore(elem_link1<T>*, const T&);
  void insertAfter(elem_link1<T>*, const T&);
  
  void deleteElem(elem_link1<T>*, T&);
  void deleteBefore(elem_link1<T>*, T&);
  void deleteAfter(elem_link1<T>*, T&);
  
  bool isEmpty() const;
  int length() const;
  void print() const;
};

template<typename T>
void LList<T>::Copy(const LList<T> &other)
{ elem_link1<T>* it = other.Start;
  
  while (it)
  { toEnd(it->inf);
    it = it->link;
  }
}

template<typename T>
void LList<T>::Erase()
{ while (Start)
  { elem_link1<T>* save = Start;
    Start = Start->link;
    delete save;
  }
}

template<typename T>
LList<T>::LList()
{ Start = NULL;
  End = NULL;
}

template<typename T>
LList<T>::LList(const LList<T> &other)
{ Start = NULL;
  End = NULL;
  Copy(other);
}

template<typename T>
LList<T>::~LList()
{ Erase();
}

template<typename T>
LList<T>& LList<T>::operator=(const LList<T> &other)
{ if (this != &other)
  { Erase();
    Copy(other);
  }
  
  return *this;
}

template<typename T>
void LList<T>::iterStart(elem_link1<T>* p)
{ if (p == NULL)
    Current = Start;
  
  else Current = p;
}

template<typename T>
elem_link1<T>* LList<T>::iter()
{ elem_link1<T>* save = Current;
  
  if (Current != NULL)
    Current = Current->link;
  
  return save;
}

template<typename T>
void LList<T>::toEnd(const T &el)
{ if (Start == NULL)
  { Start = new elem_link1<T>;
    assert(Start != NULL);
    Start->inf = el;
    Start->link = NULL;
    End = Start;
    return;
  }
  
  elem_link1<T>* save = End;
  End = new elem_link1<T>;
  assert(End != NULL);
  End->inf = el;
  End->link = NULL;
  save->link = End;
}

template<typename T>
void LList<T>::insertBefore(elem_link1<T>* p, const T &x) //This implementation of insertBefore() method is with O(1) time complexity.
{ if (p == NULL)
  { cerr << "Error ! Trying to insert before NULL !" << endl;
    return;
  }
  
  elem_link1<T>* q = new elem_link1<T>;
  assert(q != NULL);
  *q = *p;
  
  if (p == End)
    End = q;
  
  p->inf = x;
  p->link = q;
}

/* //Another possible implementation of insertBefore() method, but with O(n) time complexity, where n is the size of the list.
template<typename T>
void LList<T>::insertBefore(elem_link1<T>* p, const T &x)
{ if (p == NULL)
  { cerr << "Error ! Trying to insert before NULL !" << endl;
    return;
  }
  
  elem_link1<T>* it = Start;
  elem_link1<T>* newElem = new elem_link1<T>;
  assert(newElem != NULL);
  
  if (p == Start)
  { newElem->inf = x;
    newElem->link = Start;
    Start = newElem;
    return;
  }
  
  while (it->link != p)
    it = it->link;
  
  newElem->inf = x;
  newElem->link = p;
  it->link = newElem;
}*/

template<typename T>
void LList<T>::insertAfter(elem_link1<T>* p, const T &x)
{ if (p == NULL)
  { cerr << "Error ! Trying to insert after NULL !" << endl;
    return;
  }
  
  elem_link1<T>* newElem = new elem_link1<T>;
  assert(newElem != NULL);
  newElem->inf = x;
  newElem->link = p->link;
  
  if (p == End)
    End = newElem;
  
  p->link = newElem;
}

template<typename T>
void LList<T>::deleteElem(elem_link1<T>* p, T &x)
{ if (p == NULL)
  { cerr << "Error ! Trying to delete NULL !" << endl;
    return;
  }
  
  x = p->inf;
  
  if (Start == End)
  { delete Start;
    
    Start = NULL;
    End = NULL;
    return;
  }
  
  T _;
  
  if (p == End)
  { elem_link1<T>* it = Start;
    while (it->link != End)
      it = it->link;
    
    deleteAfter(it, _);
    return;
  }
  
  p->inf = p->link->inf;
  deleteAfter(p, _);
}

template<typename T>
void LList<T>::deleteAfter(elem_link1<T>* p, T &x)
{ if (p == NULL)
  { cerr << "Error ! Trying to delete after NULL !" << endl;
    return;
  }
  
  if (p == End)
  { cerr << "Error ! Trying to delete after the last element of the list !" << endl;
    return;
  }
  
  elem_link1<T>* save = p->link->link;
  x = p->link->inf;
  delete p->link;
  p->link = save;
  
  if (save == NULL) //If we have deleted the last element int the list, i.e. End, we should change End.
    End = p;
}

template<typename T>
void LList<T>::deleteBefore(elem_link1<T>* p, T &x)
{ if (p == NULL)
  { cerr << "Error ! Trying to delete NULL !" << endl;
    return;
  }
  
  if (p == Start)
  { cerr << "Error ! Trying to delete before the first element of the list !" << endl;
    return;
  }
  
  elem_link1<T>* it = Start;
  while (it->link != p)
    it = it->link;
  
  x = it->inf;
  it->inf = p->inf;
  T _;
  deleteAfter(it, _);
}

template<typename T>
bool LList<T>::isEmpty() const
{ return Start == NULL;
}

template<typename T>
int LList<T>::length() const
{ elem_link1<T>* it = Start;
  int br = 0;
  
  while (it != NULL)
  { br++;
    it = it->link;
  }
  
  return br;
}

template<typename T>
void LList<T>::print() const
{ elem_link1<T>* it = Start;
  while (it)
  { cout << it->inf << endl;
    it = it->link;
  }
}

int main()
{ 
  return 0;
}
