#include "../templates/tree.cpp"
#include <iostream>

using namespace std;
template <class T>
bool find(T x, tree<T>& t)
{
    if (t.empty()) {
        return false;
    }

    if (t.getRoot()->inf == x) {
        return true;
    }

    tree<T> left = t.LeftTree();
    tree<T> right = t.RightTree();
    return find(x, right) || find(x, left);
}

int main()
{
    tree<int> tree1;
    tree1.Create3(1, tree<int>(), tree<int>());

    tree<int> tree5;
    tree5.Create3(5, tree<int>(), tree<int>());

    tree<int> tree2;
    tree2.Create3(2, tree1, tree<int>());

    tree<int> tree4;
    tree4.Create3(4, tree<int>(), tree5);

    tree<int> tree3;
    tree3.Create3(3, tree2, tree4);

    tree<int> tree7;
    tree7.Create3(7, tree<int>(), tree<int>());

    tree<int> t;
    t.Create3(6, tree3, tree7);
    cout << "find(5, t): " << find(5, t) << endl;
    /*
            6
           / \
          3   7
         / \
        2   4
       /     \
      1       5
    */
    cout << endl
         << endl
         << endl
         << endl;
    t.print();

    // 6 y 3 y 2 y 1 n n n y 4 y 5 n n n y 7 n n
    // tree<int> tt;
    // tt.Create();
    // tt.print();
}/
