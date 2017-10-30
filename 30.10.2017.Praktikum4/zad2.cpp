#include<iostream>
#include<queue>
using namespace std;
int main()
{ 
  int n, minElement = -1;
  
  cin >> n;
  
  queue<int> q2, q3, q5;
  q2.push(2);
  q3.push(3);
  q5.push(5);
  
  for (int i = 0; i < n; i++)
  { minElement = min(min(q2.front(), q3.front()), q5.front());
    if (q2.front() == minElement)
      q2.pop();
    
    if (q3.front() == minElement)
      q3.pop();
    
    if (q5.front() == minElement)
      q5.pop();
    
    q2.push(minElement * 2);
    q3.push(minElement * 3);
    q5.push(minElement * 5);
  }
  
  cout << minElement << endl;
  
  return 0;
}
