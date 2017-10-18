#include<iostream>
#include<fstream>
using namespace std;
struct Gas
{ int counterId;
  double quantity;
};

int numberOfCounters = 0, maxCounterId = 0;

int findMaxCounterId()
{ ifstream fin;
  fin.open("sales.txt");
  
  int counterId, _; //Often _ is used for variables which are not going to be used.
  int maximalCounterId = 0;
  
  while (fin >> counterId >> _)
    if (counterId > maximalCounterId)
      maximalCounterId = counterId;
  
  fin.close();
  
  return maximalCounterId;
}

double totalForCounter(int counterId)
{ ifstream fin;
  fin.open("sales.txt");
  
  int currentCounterId;
  double currentQuantity;
  double totalQuantityForCounter = 0;
  
  numberOfCounters = 0;
  
  while (fin >> currentCounterId >> currentQuantity)
    if (currentCounterId == counterId)
    { totalQuantityForCounter += currentQuantity;
      numberOfCounters++;
    }
  
  fin.close();
  
  return totalQuantityForCounter;
}

void writeAverages()
{ ofstream fout;
  fout.open("averages.bin", ios::binary);
  
  for (int i = 1; i <= maxCounterId; i++)
  { double averageQuantityForCounter = totalForCounter(i);
    if (numberOfCounters != 0)
      averageQuantityForCounter /= numberOfCounters;
    
    fout.write((const char*)(&averageQuantityForCounter), sizeof(averageQuantityForCounter));
  }
  
  fout.close();
}

int main()
{ 
  maxCounterId = findMaxCounterId();
  writeAverages();
  
  ifstream fin;
  fin.open("averages.bin", ios::binary);
  
  double average = 0.0;
  while (fin.read((char*)(&average), sizeof(average)))
    cout << average << endl;
  
  fin.close();
  
  return 0;
}
