#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+1;
bool vis[mx];
vector<int> adj1[mx], adj2[mx];
stack<int> st;
vector<int> comp;

vector<vector<int>> ans;

void dfs1(int node) {
    vis[node] = 1;
    for(int child : adj1[node]) {
        if(!vis[child])
            dfs1(child);
    }
    st.push(node);
}

void dfs2(int node) {
    vis[node] = 1;
    comp.push_back(node);
    for(int child : adj2[node]) {
        if(!vis[child])
            dfs2(child);
    }
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj1[a].emplace_back(b);
        adj2[b].emplace_back(a);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs1(i);
        }
    }

    memset(vis,0,sizeof(vis));
    

    while(!st.empty()) {
        int cur = st.top();
        st.pop();
        comp.clear();
        if(!vis[cur]) {
            dfs2(cur);
        }
        if(!comp.empty()) {
            //for(int x : comp) cout << x << " ";
            //cout << "\n";
            ans.push_back(comp);
        }
    }
    if(ans.size() == 1) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    cout << ans[1][0] << " " << ans[0][0] << "\n";





    return 0;
}


