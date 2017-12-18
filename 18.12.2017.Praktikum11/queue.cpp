#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
struct elem_q {
    T inf;
    elem_q<T>* link;
};

template <typename T>
class queue {
public:
    queue();
    ~queue();
    queue(queue const&);
    queue<T>& operator=(queue const&);
    void push(T const&);
    int pop(T&);
    void head(T&);
    void print();
    bool empty() const;

private:
    elem_q<T> *front, *rear;
    void delqueue();
    void copy(queue const&);
};

template <typename T>
queue<T>::queue()
{
    front = rear = NULL;
}

template <typename T>
queue<T>::~queue()
{
    delqueue();
}

template <typename T>
queue<T>::queue(queue<T> const& r)
{
    front = rear = NULL;
    copy(r);
}

template <typename T>
queue<T>& queue<T>::operator=(queue<T> const& r)
{
    if (this != &r) {
        delqueue();
        copy(r);
    }
    return *this;
}

template <typename T>
void queue<T>::push(T const& x)
{
    elem_q<T>* e = new elem_q<T>;
    assert(e != NULL);
    e->inf = x;
    e->link = NULL;

    if (rear) {
        rear->link = e;
        rear = e;
    } else {
        front = rear = e;
    }
}

template <typename T>
void queue<T>::head(T& x)
{
    if (!rear) {
        throw 1;
    }

    x = front->inf;
}

template <typename T>
int queue<T>::pop(T& x)
{
    if (!rear) {
        return 0;
    }

    if (front == rear) {
        rear = NULL;
    }

    elem_q<T>* temp = front;
    front = front->link;

    x = temp->inf;
    delete temp;

    return 1;
}

template <typename T>
void queue<T>::print()
{
    T x;
    while (pop(x)) {
        cout << x << " ";
    }
    cout << endl;
}

template <typename T>
bool queue<T>::empty() const
{
    return rear == NULL;
}

template <typename T>
void queue<T>::delqueue()
{
    elem_q<T>* temp;
    while (front) {
        temp = front;
        front = front->link;
        delete temp;
    }

    front = rear = NULL;
}

template <typename T>
void queue<T>::copy(queue<T> const& r)
{
    elem_q<T>* p = r.front;
    while (p) {
        push(p->inf);
        p = p->link;
    }
}