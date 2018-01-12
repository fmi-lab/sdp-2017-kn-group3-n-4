#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int n, m, s;
bool used[1024], canWeFindTheWord = false;
vector<int> a[1024];
char word[1024];
void in()
{ cin >> n >> m >> word;
  s = strlen(word);
  
  for (int i = 0; i < m; i++)
  { char v1, v2;
    cin >> v1 >> v2;
    a[v1 - 'a'].push_back(v2 - 'a');
  }
}

void dfs(int i, int t)
{ if (t == s)
  { canWeFindTheWord = true;
    return;
  }
  
  used[i] = true;
  
  for (int j = 0; j < a[i].size(); j++)
    if (a[i][j] == word[t] - 'a' && used[a[i][j]] == false)
      dfs(a[i][j], t + 1);
}

int main()
{ 
  in();
  dfs(word[0] - 'a', 1);
  
  cout << boolalpha;
  cout << canWeFindTheWord << endl;
  
  return 0;
}
/*
3 3 abo
a b
a o
b o
*/
