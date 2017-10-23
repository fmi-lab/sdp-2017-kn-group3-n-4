#include <iostream>
#include <stack>

using std::stack;
using std::cin;
using std::cout;
using std::endl;

/*
  fibonacci
  7
  1, 1, 2, 3, 5, 8, 13
  |8|
  |5|
  |3|
  |2|
  |1|
  |1|
*/

void fibonacci(const int& n, stack<int>& prev)
{
    if (n <= 2) {
        return;
    } else {
        int an1, an2;
        an1 = prev.top();
        prev.pop();
        an2 = prev.top();
        prev.pop();
        prev.push(an2);
        prev.push(an1);
        prev.push(an1 + an2);
        fibonacci(n - 1, prev);
    }
}

int main()
{
    stack<int> prev;
    prev.push(1);
    prev.push(1);

    fibonacci(7, prev);
    int res = prev.top();

    cout << res << endl;
    return 0;
}