#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, Start, End;
bool used[1024];
vector<int> a[1024];
void in()
{ cin >> n >> m >> Start >> End;
  for (int i = 0; i < m; i++)
  { int v1, v2;
    cin >> v1 >> v2;
    a[v1 - 1].push_back(v2 - 1);
  }
}

void bfs(int i)
{ queue<int> q;
  q.push(i);
  used[i] = true;
  
  int numberOfVerticesOnCurrentLevel = q.size(), level = 0;
  
  while (!q.empty())
  { int g = q.front();
    q.pop();
    
    numberOfVerticesOnCurrentLevel--;
    if (numberOfVerticesOnCurrentLevel == -1)
      level++;
    
    for (int j = 0; j < a[g].size(); j++)
      if (used[a[g][j]] == false)
      { if (a[g][j] == End - 1)
        { cout << level + 1 << endl;
          return;
        }
        
        used[a[g][j]] = true;
        q.push(a[g][j]);
      }
  }
  
  cout << "There is not path between vertices " << Start << " and " << End << '.' << endl;
}

int main()
{ 
  in();
  bfs(Start - 1);
  
  return 0;
}
/*
4 4 1 4
1 2
1 3
2 3
3 4
*/
