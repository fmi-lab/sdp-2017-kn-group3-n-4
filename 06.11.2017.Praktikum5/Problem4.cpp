#include<iostream>
#include<stack>
using namespace std;
void getCoordinate(int &coordinate)
{ cin.get();
  cin >> coordinate;
}

void in(int &n, int &m, int &startX, int &startY, int &endX, int &endY, int a[][32])
{ cin >> n >> m;
  
  cin.get();
  getCoordinate(startX);
  getCoordinate(startY);
  
  cin.get();
  
  cin.get();
  getCoordinate(endX);
  getCoordinate(endY);
  
  cin.get();
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
}

bool isValidCell(int n, int m, int x, int y, bool used[][32], int a[][32])
{ return !(x < 0 || x >= n || y < 0 || y >= m || used[x][y] == true || a[x][y] == 0);
}

void solve(int n, int m, int startX, int startY, int endX, int endY, int a[][32])
{ if (startX == endX && startY == endY)
  { cout << "There is a path from cell (" << startX << ", " << startY << ") to cell (" << endX << ", " << endY << ")" << endl;
    return;
  }
  
  stack< pair<int, int> > st;
  bool used[32][32] = { false };
  int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
  
  used[startX - 1][startY - 1] = true;
  st.push(make_pair(startX - 1, startY - 1));
  
  while (!st.empty())
  { int x = st.top().first;
    int y = st.top().second;
    
    bool check = false;
    for (int i = 0; i < 4; i++)
    { int newX = x + dx[i];
      int newY = y + dy[i];
      
      if (isValidCell(n, m, newX, newY, used, a))
      { if (newX == endX - 1 && newY == endY - 1)
        { cout << "There is a path from cell (" << startX << ", " << startY << ") to cell (" << endX << ", " << endY << ")." << endl;
          return;
        }
        
        used[newX][newY] = true;
        st.push(make_pair(newX, newY));
        check = true;
        break;
      }
    }
    
    if (check == false)
      st.pop();
  }
  
  cout << "There is no path from cell (" << startX << ", " << startY << ") to cell (" << endX << ", " << endY << ")." << endl;
}

int main()
{ 
  int n, m, startX, startY, endX, endY, a[32][32];
  
  in(n, m, startX, startY, endX, endY, a);
  solve(n, m, startX, startY, endX, endY, a);
  
  return 0;
}
