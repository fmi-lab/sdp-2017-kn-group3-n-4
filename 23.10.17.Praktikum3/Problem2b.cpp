#include <iostream>
#include <stack>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::stack;

string s1 = "";
string s2 = "ala bala";
string s3 = "{}";
string s4 = "()";
string s5 = "[]";
string s6 = "}{";
string s7 = ")(";
string s8 = "][";
string s9 = "({})";
string s10 = "({[[[()]]]})";
string s11 = "({[[[(]]]})";
string s12 = "<<()>>";
string s13 = "{<[]>}";

/*
    |   |
    |   |
    |   |
    |   |
    |___|
    // fail:
    1. empty stack && closing bracket
    2. not empty stack && closing bracket does not match stack top
    3. stack is not empty in the end
*/

struct bracketPair {
    char open;
    char close;
};

bracketPair supportedBrackets[] = {
    { '(', ')' },
    { '[', ']' },
    { '{', '}' },
    { '<', '>' }
};

int BRACKETS_COUNT = 4;

bool isOpeningBracket(const char& c)
{
    for (int i = 0; i < BRACKETS_COUNT; i++) {
        if (supportedBrackets[i].open == c) {
            return true;
        }
    }
    return false;
}

bool isClosingBracket(const char& c)
{
    for (int i = 0; i < BRACKETS_COUNT; i++) {
        if (supportedBrackets[i].close == c) {
            return true;
        }
    }
    return false;
}

bool areMatchingBracket(const char& opening, const char& closing)
{
    for (int i = 0; i < BRACKETS_COUNT; i++) {
        if (supportedBrackets[i].open == opening) {
            return supportedBrackets[i].close == closing;
        }
    }
    return false;
}

bool brackets(const string& str)
{
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        if (isOpeningBracket(str[i])) {
            s.push(str[i]);
        } else if (isClosingBracket(str[i])) {
            if (s.empty()) {
                return false;
            }
            char c;
            c = s.top();
            s.pop();
            if (!areMatchingBracket(c, str[i])) {
                return false;
            }
        }
    }

    return s.empty();
}

void valid_brackets(const string& s)
{
    if (brackets(s) == true) {
        cout << s << " is correct :)" << endl;
    } else {
        cout << s << " is not correct, sry :(" << endl;
    }
}

int main()
{
    valid_brackets(s1);
    valid_brackets(s2);
    valid_brackets(s3);
    valid_brackets(s4);
    valid_brackets(s5);
    valid_brackets(s6);
    valid_brackets(s7);
    valid_brackets(s8);
    valid_brackets(s9);
    valid_brackets(s10);
    valid_brackets(s11);
    valid_brackets(s12);
    valid_brackets(s13);
    return 0;
}