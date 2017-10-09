#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{ 
  ofstream fout;
  fout.open("inputZad1.txt");
  
  char b[16] = { '\0' };
  strcpy(b, "a b\nc");
  
  fout.write((const char*)(&b), strlen(b));
  fout.close();
  
  ifstream fin;
  fin.open("inputZad1.txt"); //It is possible here to just use the flag ios::ate and then fin.tellg() will give the size of the file in bytes.
  
  
  streampos startPosition = fin.tellg();
  fin.seekg(0, ios::end);
  streampos endPosition = fin.tellg();
  
  cout << "File has size of " << endPosition - startPosition << " bytes." << endl;
  
  fin.close();
  
  return 0;
}
