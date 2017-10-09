#include <fstream>
#include <iostream>

using std::ios;
using std::cout;
using std::endl;
using std::ifstream;

int main()
{
    ifstream file("bigfile.txt");

    int symbols = 0, words = 0, lines = 0;

    bool inWord = false;
    char c, last;

    while (file.get(c)) {
        symbols++;
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
            inWord = true;
        } else {
            if (inWord) {
                words++;
            }
            inWord = false;
            if (c == '\n')
                lines++;
        }
        last = c;
    }
    if (('a' <= last && last <= 'z') || ('A' <= last && last <= 'Z'))
        words++;

    cout << symbols << " " << words << " " << lines << endl;

    file.close();
    return 0;
}