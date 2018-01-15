#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned MAX = 1024;

class MinHeap {
public:
    MinHeap()
    {
        N = 0;
        memset(arr, 0, sizeof(arr));
    }
    ~MinHeap() = default;
    int leftChild(const int&) const;
    int rightChild(const int&) const;
    int parent(const int&) const;
    void push(const long long&);
    long long top() const;
    void pop();
    bool empty() const;

private:
    int N;
    long long arr[MAX];
    void heapify(int);
};

int MinHeap::leftChild(const int& i) const { return 2 * i + 1; }
int MinHeap::rightChild(const int& i) const { return 2 * i + 2; }
int MinHeap::parent(const int& i) const { return (i - 1) / 2; }

void MinHeap::heapify(int i)
{
    int leftC = leftChild(i), rightC = rightChild(i), smallest = i;

    if (leftC < N - 1 && arr[leftC] < arr[smallest])
        smallest = leftC;
    if (rightC < N - 1 && arr[rightC] < arr[smallest])
        smallest = rightC;
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        heapify(smallest);
    }
}
void MinHeap::push(const long long& x)
{
    arr[N++] = x;
    int i = N - 1;
    while (i != 0 && arr[i] < arr[parent(i)]) {
        std::swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::pop()
{
    arr[0] = arr[N - 1];
    N--;
    heapify(0);
}

long long MinHeap::top() const { return arr[0]; }

bool MinHeap::empty() const { return N == 0; }

int main()
{
    int a[5] = { 9, 4, 6, 7, 8 };
    MinHeap h;
    for (int i = 0; i < 5; ++i) {
        h.push(a[i]);
    }
    h.push(5);
    while (!h.empty()) {
        printf("%lld ", h.top());
        h.pop();
    }
    printf("\n");
}
