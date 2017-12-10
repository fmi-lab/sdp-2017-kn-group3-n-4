#include "../templates/tree.cpp"
#include <iostream>
using namespace std;

bool containsWord(tree<char>& t, string word, int i = 0)
{
    if (t.empty()) {
        return false;
    }

    if (t.LeftTree().empty() && t.RightTree().empty()) {
        return word[i] == t.getRoot()->inf && word.length() == i + 1;
    }

    if (word.length() == i) {
        return false;
    }

    if (t.getRoot()->inf == word[i]) {
        tree<char> left = t.LeftTree();
        tree<char> right = t.RightTree();
        return containsWord(left, word, i + 1) || containsWord(right, word, i + 1);
    } else {
        return false;
    }
}

int main()
{
    // b y a y b y x y a n n y y n y z n n y a n n n y u y u n y u n n n
    /*
             b
            / \
           a   u
          /   /
         b   u
        / \   \
       x   a   u
      / \
     a   y
          \
           z
  */
    tree<char> ct;
    ct.Create();
    cout << endl
         << endl
         << endl
         << endl;
    ct.print();

    cout << containsWord(ct, "baba") << " == 1" << endl;
    cout << containsWord(ct, "buuu") << " == 1" << endl;
    cout << containsWord(ct, "ba") << " == 0" << endl;
    cout << containsWord(ct, "babx") << " == 0" << endl;
    cout << containsWord(ct, "babxy") << " == 0" << endl;
}
