#include<iostream>
#include<fstream>
using namespace std;
struct Result
{ int sum;
  int prod;
  
  Result()
  { sum = 0;
    prod = 1;
  }
};

void solve()
{ ifstream fin;
  fin.open("input.txt");
  
  ofstream fout;
  fout.open("output.bin", ios::binary);
  
  int k;
  while (fin >> k)
  { fin.get();
    
    int n, sum = 0, prod = 1;
    Result current;
    
    for (int i = 0; i < k; i++)
    { fin >> n;
      current.sum += n;
      current.prod *= n;
    }
    
    fout.write((const char*)(&current), sizeof(current));
    
    fin.get();
  }
  
  fin.close();
  fout.close();
}

void print()
{ ifstream fin;
  fin.open("output.bin", ios::binary);
  
  Result current;
  while (fin.read((char*)(&current), sizeof(current)))
    cout << current.sum << ' ' << current.prod << endl;
  
  fin.close();
}

int main()
{ 
  solve();
  print();
  
  return 0;
}
