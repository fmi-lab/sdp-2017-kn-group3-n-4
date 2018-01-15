#include "bits/stdc++.h"

int a[1024];
int N = 0;
//HEAP SORT
void pushDown(int i) // Min Heap
{
    int leftC = i * 2 + 1, smallest;

    while (leftC < N) {

        smallest = leftC;

        if (smallest < N - 1 && a[leftC] > a[leftC + 1]) {
            smallest = leftC + 1;
        }

        if (a[i] > a[smallest]) {
            std::swap(a[i], a[smallest]);
            i = leftC;
            leftC = leftC * 2 + 1;
        } else {
            leftC = N;
        }
    }
}

void pop()
{
    a[0] = a[N - 1];
    N--;
    pushDown(0);
}

void push(const int& x)
{
    a[N++] = x;
    int i = N;
    while (i >= 0 && a[i] > a[i - 1 / 2]) {
        std::swap(a[i], a[i - 1 / 2]);
        i /= 2;
    }
}

void heapSort()
{
    for (int i = N - 1; i >= 0; --i) {
        pushDown(i);
    }
}
void in()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
}

bool empty()
{
    return N == 1;
}
void print()
{
    while (!empty()) {
        printf("%d ", a[0]);
        pop();
    }
    printf("%d\n", a[0]);
}

int main()
{
    in();
    heapSort();
    print();
    return 0;
}
