#include<iostream>
#include<vector>
using namespace std;
int n, m, Start, End, ans = -1;
bool used[1024];
vector<pair<int, int>> a[1024];
void in()
{ cin >> n >> m >> Start >> End;
  for (int i = 0; i < m; i++)
  { int v1, v2, cost;
    cin >> v1 >> v2 >> cost;
    a[v1 - 1].push_back(make_pair(v2 - 1, cost));
  }
}

void dfs(int i, int sum)
{ if (i == End - 1)
  { if (ans > sum || ans == -1)
      ans = sum;
    
    return;
  }
  
  used[i] = true;
  
  for (int j = 0; j < a[i].size(); j++)
    if (used[a[i][j].first] == false)
    { dfs(a[i][j].first, sum + a[i][j].second);
      used[a[i][j].first] = false;
    }
}

int main()
{ 
  in();
  dfs(Start - 1, 0);
  
  cout << ans << endl;
  
  return 0;
}
/*
3 3 1 3
1 2 1
1 3 5
2 3 2
*/
