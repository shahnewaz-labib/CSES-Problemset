#include "bits/stdc++.h"
using namespace std;
vector<int> adj[100010], in(100010, 0);
int main() {
    int nodes, edges; cin >> nodes >> edges;
    for(int i = 0; i < edges; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for(int i = 1; i <= nodes; i++) {
        if(!in[i])
            q.push(i);
    }
    vector<int> ans;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for(int child : adj[u])
            if(!--in[child])
                q.push(child);
    }
    if((int)ans.size() != nodes) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int x : ans) cout << x << ' '; cout << '\n';
    return 0;
}
