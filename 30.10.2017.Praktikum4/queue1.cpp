#include<iostream>
#include<stdlib.h>
#include<cassert>
using namespace std;
template<typename T>
struct elem
{ T inf;
  elem<T>* link;
};

template<typename T>
class Queue
{ private:
  elem<T>* Front;
  elem<T>* End;
  
  void Copy(const Queue<T>&);
  void Erase();
  
  public:
  Queue();
  Queue(const Queue<T>&);
  ~Queue();
  Queue& operator=(const Queue<T>&);
  
  void push(const T&);
  void pop();
  T top() const;
  bool isEmpty() const;
  int length();
  void print();
};

template<typename T>
void Queue<T>::Copy(const Queue<T> &other)
{ elem<T>* otherFront = other.Front;
  
  while (otherFront)
  { push(otherFront->inf);
    otherFront = otherFront->link;
  }
}

template<typename T>
void Queue<T>::Erase()
{ while (!isEmpty())
    pop();
}

template<typename T>
Queue<T>::Queue()
{ Front = NULL;
  End = NULL;
}

template<typename T>
Queue<T>::Queue(const Queue<T> &other)
{ Front = NULL;
  End = NULL;
  Copy(other);
}

template<typename T>
Queue<T>::~Queue()
{ Erase();
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T> &other)
{ if (this != &other)
  { Erase();
    Copy(other);
  }
  
  return *this;
}

template<typename T>
void Queue<T>::push(const T &element)
{ elem<T>* save = End;
  End = new elem<T>;
  End->inf = element;
  End->link = NULL;
  
  if (Front == NULL)
    Front = End;
  
  else save->link = End;
}

template<typename T>
void Queue<T>::pop()
{ if (Front == NULL)
  { cerr << "Error ! The queue is empty !" << endl;
    exit(1);
  }
  
  elem<T>* save = Front;
  Front = Front->link;
  delete save;
}

template<typename T>
T Queue<T>::top() const
{ if (isEmpty())
  { cerr << "Error ! The queue is empty and there is no top element !" << endl;
    exit(1);
  }
  
  return Front->inf;
}

template<typename T>
bool Queue<T>::isEmpty() const
{ return Front == NULL;
}

template<typename T>
int Queue<T>::length()
{ int br = 0;
  while (!isEmpty())
  { br++;
    pop();
  }
  
  return br;
}

template<typename T>
void Queue<T>::print()
{ while (!isEmpty())
  { cout << top() << endl;
    pop();
  }
}

int main()
{ 
  return 0;
}
