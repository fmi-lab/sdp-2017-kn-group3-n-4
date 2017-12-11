#include "treeT.cpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int toInt(string& word)
{
    int res = 0;
    bool sign = (word[0] == '-')? true : false;
    for(int i = 0; i < word.length(); i++)
    {
        if(word[i] == '-') continue;
        res = res * 10 + word[i] - '0';
    }
    return (sign) ? (-1)*res :res;
}

int calculate(const tree<string>& t)
{
    if (t.empty())
    {
        return 0;
    }

    if (((t.getRoot()->inf)[0] >= '0' && (t.getRoot()->inf)[0] <= '9') 
        || ((t.getRoot()->inf)[0] == '-' && (t.getRoot()->inf).length() > 1))
    {
        return toInt(t.getRoot()->inf);
    }

    int left = calculate(t.LeftTree());
    int right = calculate(t.RightTree());
    switch ((t.getRoot()->inf)[0])
    {
    case '*':
        return left * right;
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '/':
        return right == 0 ? 0 : left / right;
    default:
        return 0;
    }
}

int main()
{
    tree<string> t10;
    t10.Create3("10", tree<string>(), tree<string>());

    tree<string> t3;
    t3.Create3("3", tree<string>(), tree<string>());

    tree<string> t5;
    t5.Create3("5", tree<string>(), tree<string>());

    tree<string> t2;
    t2.Create3("2", tree<string>(), tree<string>());

    tree<string> t_1;
    t_1.Create3("-", t10, t3);

    tree<string> t_2;
    t_2.Create3("+", t2, t5);

    tree<string> t;
    t.Create3("*", t_2, t_1);

    cout << calculate(t) << " == 49" << endl;
}
