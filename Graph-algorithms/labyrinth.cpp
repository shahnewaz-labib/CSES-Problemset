/*
          __      __    _ __  
         / /___ _/ /_  (_) /_ 
        / / __ `/ __ \/ / __ \
       / / /_/ / /_/ / / /_/ /
 _____/_/\__,_/_.___/_/_.___/ 
/_____/                       

*/

#include "bits/stdc++.h"
#define pii pair<int, int>
using namespace std;
int n, m, sx, sy, ex, ey, p, q;
int fx[] = {0, 1, 0, -1}; // R D L U
int fy[] = {1, 0, -1, 0};
string grid[1010];
int level[1010][1010];

map<pii, pii> parent;

bool valid(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m and level[x][y] == -1 and grid[x][y] != '#';
}

void bfs() {
    queue<pii> q;
    q.push({sx, sy});
    level[sx][sy] = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x+fx[i];
            int ny = y+fy[i];
            if(valid(nx, ny)) {
                level[nx][ny] = level[x][y]+1;
                q.push({nx, ny});
                parent[{nx, ny}] = {x, y};
                if(grid[nx][ny] == 'B') return;
            }
        }
        
    }
}

char move(pii a, pii b) {
    int ax = a.first, ay = a.second;
    int bx = b.first, by = b.second;
    int x = bx-ax, y = by-ay;
    if(x == 0) {
        if(y == 1) return 'R';
        else if(y == -1) return 'L';
    } else if(y == 0) {
        if(x == 1) return 'D';
        else if(x == -1) return 'U';
    }
    return 'X';
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') sx = i, sy = j;
            else if(grid[i][j] == 'B') ex = i, ey = j;
        }
    }
    p = ex, q = ey;
    memset(level, -1, sizeof level);

    bfs();

    if(level[ex][ey] == -1) {cout << "NO\n"; return 0;}

    vector<pii> ans;
    ans.push_back({ex, ey});
    
    for( ; ; ) {
        pii a = parent[{ex, ey}];
        int x = a.first, y = a.second;
        ans.push_back({x, y});
        if(grid[x][y] == 'A') break;
        ex = x, ey = y;
    }
    
    reverse(ans.begin(), ans.end());
    cout << "YES\n" << level[p][q] << '\n';
    string path;
    for(int i = 1; i < (int)ans.size(); i++) {
        path.push_back(move(ans[i-1], ans[i]));
    }
    cout << path << '\n';
}
