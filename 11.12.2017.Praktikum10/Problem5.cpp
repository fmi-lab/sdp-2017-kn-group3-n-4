#include "binOrdTree.cpp"
#include <iostream>

using namespace std;

template <typename T>
bool contains(const binOrdTree<T>& t, const T x)
{
    if (t.empty()) {
        return false;
    }

    if (t.rootTree() == x) {
        return true;
    } else if (t.rootTree() < x) {
        return contains(t.rightTree(), x);
    } else {
        return contains(t.leftTree(), x);
    }
}

int main()
{
    binOrdTree<int> t;
    t.addNode(5);
    t.addNode(7);
    t.addNode(6);
    t.addNode(3);
    t.addNode(4);
    t.addNode(2);
    t.addNode(1);

    t.print();

    cout << contains(t, 1) << " == 1" << endl;
    cout << contains(t, 5) << " == 1" << endl;
    cout << contains(t, 4) << " == 1" << endl;
    cout << contains(t, 8) << " == 0" << endl;
    cout << contains(t, 10) << " == 0" << endl;
}