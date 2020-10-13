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
int n, k;
vector<int> adj[200010];
bool vis[100010];

void dfs(int node) {
    vis[node] = 1;
    for(int child : adj[node]) {
        if(!vis[child])
            dfs(child);
    }
}

int main() {
    cin >> n >> k;
    int a, b;
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int roads = -1;
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            roads++;
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << roads << '\n';
    for(int i = 1; i < (int) ans.size(); i++) {
        cout << ans[i] << " " << ans[i-1] << '\n';
    }



}
