#include<iostream>
#include<stdlib.h> //In order to use function exit() we need to add this library.
#include<cassert>
using namespace std;
template<typename T>
struct elem
{ T inf;
  elem<T>* link;
};

template<typename T>
class Stack
{ private:
  elem<T>* el; //This is the pointer to the top of the stack.
  
  public:
  Stack();
  ~Stack();
  
  void push(const T&);
  void pop();
  T top() const;
  int length();
  bool isEmpty() const;
  void print();
};

template<typename T>
Stack<T>::Stack()
{ el = NULL;
}

template<typename T>
Stack<T>::~Stack()
{ while (!isEmpty())
    pop();
}

template<typename T>
void Stack<T>::push(const T &newElement)
{ elem<T>* nextElement = new elem<T>;
  assert(nextElement != NULL);
  nextElement->inf = newElement;
  nextElement->link = el;
  el = nextElement;
}

/*
//Another possible implementation of push method.
template<typename T>
void Stack<T>::push(const T &newElement)
{ elem<T>* save = el;
  el = new elem<T>;
  assert(el != NULL);
  el->inf = newElement;
  el->link = save;
}
*/

template<typename T>
void Stack<T>::pop()
{ if (isEmpty())
  { cerr << "There are no elements in the stack !" << endl;
    exit(1);
  }
  
  elem<T>* pred = el->link;
  delete el;
  el = pred;
}

template<typename T>
T Stack<T>::top() const
{ if (isEmpty())
  { cerr << "There are no elements in the stack !" << endl;
    exit(1);
  }
  
  return el->inf;
}

template<typename T>
int Stack<T>::length()
{ int br = 0;
  while (!isEmpty()) //While we have elements in the stack.
  { br++;
    pop();
  }
  
  return br;
}

template<typename T>
bool Stack<T>::isEmpty() const
{ return el == NULL;
}

template<typename T>
void Stack<T>::print()
{ while (!isEmpty())
  { cout << top() << endl;
    pop();
  }
}

int main()
{ 
  Stack<int> s;
  
  cout << boolalpha;
  cout << "Is stack s empty: " << s.isEmpty() << endl << endl;
  
  cout << "Pushing element 3 into stack s..." << endl;
  s.push(3);
  cout << "Pushing element 7 into stack s..." << endl << endl;
  s.push(7);
  
  cout << "Is stack s empty: " << s.isEmpty() << endl << endl;
  
  cout << "The top element of the stack is: " << s.top() << endl;
  cout << "Deleting element from the stack s..." << endl << endl;
  s.pop();
  cout << "The top element of the stack is: " << s.top() << endl << endl;
  
  cout << "The length of the stack is: " << s.length() << endl;
  cout << "... and now the length of the stack is: " << s.length() << endl << endl;
  
  cout << "Pushing element 9 into stack s..." << endl;
  s.push(9);
  cout << "Pushing element 15 into stack s..." << endl << endl;
  s.push(15);
  
  cout << "Stack s contains: " << endl;
  s.print();
  cout << endl;
  
  cout << "Is stack s empty: " << s.isEmpty() << endl;
  
  return 0;
}
