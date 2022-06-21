#include "bits/stdc++.h"
#define ll long long

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...)
#endif

using namespace std;

const int mxn = 2e5 + 1;
vector<int> adj[mxn];
vector<int> ans;

void dfs(int u) {
    int sub = 0;
    for (int v : adj[u]) {
        dfs(v);
        sub += 1 + ans[v];
    }
    ans[u] = sub;
}

void solve() {
    int n;
    cin >> n;

    ans.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;

        adj[x].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main() {
    int t;
    t = 1;
    for (int tc = 1; tc <= t; tc++) {
        /* printf("Case %d: ", tc); */
        solve();
    }
}
