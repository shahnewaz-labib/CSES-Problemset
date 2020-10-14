/*
          __      __    _ __  
         / /___ _/ /_  (_) /_ 
        / / __ `/ __ \/ / __ \
       / / /_/ / /_/ / / /_/ /
 _____/_/\__,_/_.___/_/_.___/ 
/_____/                       

*/

// Classic Bipartite graph test

#include "bits/stdc++.h"
#define pii pair<int, int>
using namespace std;
int n, m;
vector<int> adj[200010];
int color[100010];
bool bipartite = true;

void dfs(int node, int col) {
    color[node] = col;
    for(int child : adj[node]) {
        if(color[child] == 0) {
            dfs(child, (col == 1 ? 2 : 1));
        } else if(color[child] == color[node]) {
            bipartite = false;
            return;
        }
    }
} 

int main() {
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++)
        cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) {
            dfs(i, 1);
        }
    }
    if(!bipartite) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i = 1; i <= n; i++) cout << color[i] << " "; cout << '\n';
    return 0;
}
