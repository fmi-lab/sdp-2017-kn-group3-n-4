#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned MAX = 1024;

class MaxHeap {
public:
    MaxHeap()
    {
        N = 0;
        memset(arr, 0, sizeof(arr));
    }
    ~MaxHeap() = default;
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

int MaxHeap::leftChild(const int& i) const { return 2 * i + 1; }
int MaxHeap::rightChild(const int& i) const { return 2 * i + 2; }
int MaxHeap::parent(const int& i) const { return (i - 1) / 2; }

void MaxHeap::heapify(int i)
{
    int leftC = leftChild(i), rightC = rightChild(i), biggest = i;

    if (leftC < N - 1 && arr[leftC] > arr[biggest])
        biggest = leftC;
    if (rightC < N - 1 && arr[rightC] > arr[biggest])
        biggest = rightC;
    if (biggest != i) {
        std::swap(arr[i], arr[biggest]);
        heapify(biggest);
    }
}
void MaxHeap::push(const long long& x)
{
    arr[N++] = x;
    int i = N - 1;
    while (i != 0 && arr[i] > arr[parent(i)]) {
        std::swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::pop()
{
    arr[0] = arr[N - 1];
    N--;
    heapify(0);
}

long long MaxHeap::top() const { return arr[0]; }

bool MaxHeap::empty() const { return N == 0; }

int main()
{
    int a[5] = { 9, 4, 6, 7, 8 };
    MaxHeap h;
    for (int i = 0; i < 5; ++i) {
        h.push(a[i]);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%lld ", h.top());
        h.pop();
    }
    printf("\n");
}
