#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+1;
bool vis[mx];
vector<int> adj1[mx], adj2[mx];
stack<int> st;
vector<int> comp;
vector<int> ans(mx);

void dfs1(int node) {
    vis[node] = 1;
    for(int child : adj1[node])
        if(!vis[child])
            dfs1(child);
    st.push(node);
}

void dfs2(int node) {
    vis[node] = 1;
    for(int child : adj2[node]) {
        if(!vis[child]) {
            dfs2(child);
        }
    }
    comp.push_back(node);
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
    int c = 1;
    while(!st.empty()) {
        int cur = st.top();
        st.pop();
        if(!vis[cur]) {
            comp.clear();
            dfs2(cur);
            for(int x : comp) ans[x-1] = c;
            c++;
        }
    }
    cout << c-1 << "\n";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }



    return 0;
}


