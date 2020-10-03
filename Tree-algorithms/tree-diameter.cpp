#include <bits/stdc++.h>
#define d(x) cerr << #x << " = " << x << endl;
#define HERE cout << "here" << endl;
using namespace std;
vector<int> adj[200010];
int mx = -1, mxdist = -1;
int level[200010];

void dfs(int node, int dist) {
    level[node] = dist;
    if(dist > mxdist) {
        mxdist = dist;
        mx = node;
    }
    // cout << "visiting " << node << endl;
    for(int child : adj[node])
        if(level[child] == -1)
            dfs(child, dist+1);
}

int main() {
    int nodes;
    cin >> nodes;
    for(int i = 0; i < 200010; i++) level[i] = -1;
    for(int i = 0; i < nodes-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs(1, 0);
    for(int i = 0; i < 200010; i++) level[i] = -1;
    dfs(mx, 0);
    cout << mxdist << '\n';
}