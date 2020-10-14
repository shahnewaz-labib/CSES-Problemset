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
int n, m;
vector<int> adj[200010];
int level[100010];
map<int, int> parent;
void bfs() {
    queue<int> q;
    q.push(1);
    level[1] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int child : adj[u]) {
            if(level[child] == -1) {
                level[child] = level[u]+1;
                q.push(child);
                parent[child] = u;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(level, -1, sizeof level);
    bfs();
    if(level[n] == -1) {cout << "IMPOSSIBLE\n"; return 0;}
    cout << level[n] << '\n';
    vector<int> v;
    v.push_back(n);
    while(true) {
        if(v.back() == 1) break;
        v.push_back(parent[n]);
        n = v.back();        
    }
    reverse(v.begin(), v.end());
    for(int x : v) cout << x << " "; cout << '\n';
}
