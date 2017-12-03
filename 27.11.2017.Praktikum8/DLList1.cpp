#include<iostream>
#include<cassert>
using namespace std;
template<typename T>
struct elem_link2
{ T inf;
  elem_link2<T>* pred;
  elem_link2<T>* succ;
};

template<typename T>
class DLList
{ public:
  elem_link2<T>* Start;
  elem_link2<T>* End;
  elem_link2<T>* Current;
  
  void Copy(const DLList<T>&);
  void Erase();
  
  public:
  DLList();
  DLList(const DLList<T>&);
  ~DLList();
  DLList<T>& operator=(const DLList<T>&);
  
  void iterStart(elem_link2<T>* = NULL);
  elem_link2<T>* iter();
  
  void toEnd(const T&);
  void insertAfter(elem_link2<T>*, const T&);
  void insertBefore(elem_link2<T>*, const T&);
  
  void deleteElem(elem_link2<T>*);
  void deleteAfter(elem_link2<T>*);
  void deleteBefore(elem_link2<T>*);
  
  int length() const;
  bool isEmpty() const;
  void print() const;
};

template<typename T>
void DLList<T>::Copy(const DLList<T> &other)
{ elem_link2<T>* it = other.Start;
  
  while (it)
  { toEnd(it->inf);
    it = it->succ;
  }
}

template<typename T>
void DLList<T>::Erase()
{ while (Start)
    deleteElem(Start);
}

template<typename T>
DLList<T>::DLList()
{ Start = End = NULL;
}

template<typename T>
DLList<T>::DLList(const DLList<T> &other)
{ Start = End = NULL;
  Copy(other);
}

template<typename T>
DLList<T>::~DLList()
{ Erase();
}

template<typename T>
DLList<T>& DLList<T>::operator=(const DLList<T> &other)
{ if (this != &other)
  { Erase();
    Copy(other);
  }
  
  return *this;
}

template<typename T>
void DLList<T>::iterStart(elem_link2<T>* p)
{ if (p == NULL)
    Current = Start;
  
  else Current = p;
}

template<typename T>
elem_link2<T>* DLList<T>::iter()
{ elem_link2<T>* save = Current;
  
  if (Current)
    Current = Current->succ;
  
  return save;
}

template<typename T>
void DLList<T>::toEnd(const T &el)
{ if (End == NULL)
  { End = new elem_link2<T>;
    assert(End != NULL);
    End->inf = el;
    End->pred = NULL;
    End->succ = NULL;
    
    Start = End;
  }
  
  else
    insertAfter(End, el);
}

template<typename T>
void DLList<T>::insertAfter(elem_link2<T>* p, const T &el)
{ if (p == NULL)
  { cerr << "Error ! Trying to insert elements after NULL !" << endl;
    return;
  }
  
  elem_link2<T>* newElem = new elem_link2<T>;
  assert(newElem != NULL);
  newElem->inf = el;
  newElem->pred = p;
  newElem->succ = p->succ;
  
  p->succ = newElem;
  if (p != End)
    newElem->succ->pred = newElem;
  
  else
    End = newElem;
}

template<typename T>
void DLList<T>::insertBefore(elem_link2<T>* p, const T &el)
{ if (p == NULL)
  { cerr << "Error ! Trying to insert elements before NULL !" << endl;
    return;
  }
  
  else if (p == Start)
  { elem_link2<T>* newElem = new elem_link2<T>;
    assert(newElem != NULL);
    newElem->inf = el;
    newElem->pred = NULL;
    newElem->succ = Start;
    
    Start->pred = newElem;
    Start = newElem;
  }
  
  else
  { p = p->pred;
    insertAfter(p, el);
  }
}

template<typename T>
void DLList<T>::deleteElem(elem_link2<T>* p)
{ if (p == NULL)
  { cerr << "Error ! Trying to delete NULL !" << endl;
    return;
  }
  
  if (Start == End)
  { delete Start;
    Start = End = NULL;
    return;
  }
  
  elem_link2<T>* savepPred = p->pred;
  elem_link2<T>* savepSucc = p->succ;
  
  if (p == Start)
  { savepSucc->pred = NULL;
    Start = savepSucc;
  }
  
  else if (p == End)
  { savepPred->succ = NULL;
    End = savepPred;
  }
  
  else
  { savepPred->succ = savepSucc;
    savepSucc->pred = savepPred;
  }
  
  delete p;
}

template<typename T>
void DLList<T>::deleteAfter(elem_link2<T>* p)
{ if (p == NULL)
  { cerr << "Error ! Trying to delete NULL !" << endl;
    return;
  }
  
  if (p == End)
  { cerr << "Error ! Trying to delete after the end of the list !" << endl;
    return;
  }
  
  p = p->succ;
  deleteElem(p);
}

template<typename T>
void DLList<T>::deleteBefore(elem_link2<T>* p)
{ if (p == NULL)
  { cerr << "Error ! Trying to delete NULL !" << endl;
    return;
  }
  
  if (p == Start)
  { cerr << "Error ! Trying to delete before the start of the list !" << endl;
    return;
  }
  
  p = p->pred;
  deleteElem(p);
}

template<typename T>
int DLList<T>::length() const
{ elem_link2<T>* it = Start;
  int br = 0;
  
  while (it)
  { br++;
    it = it->succ;
  }
  
  return br;
}

template<typename T>
bool DLList<T>::isEmpty() const
{ return Start == NULL;
}

template<typename T>
void DLList<T>::print() const
{ elem_link2<T>* it = Start;
  
  while (it)
  { cout << it->inf << endl;
    it = it->succ;
  }
}

int main()
{ 
  return 0;
}
