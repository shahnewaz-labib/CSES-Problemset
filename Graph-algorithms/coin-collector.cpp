#include <bits/stdc++.h>
#define lesgoo		ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll			long long
#define pii 		pair<int, int>
#define MIN(x,y)	(x) < (y) ? x : y
#define MAX(x,y)	(x) > (y) ? x : y
#define TC			int t;cin>>t;for(int tc=1;tc<=t;tc++)
#define Unique(a)   sort(all(a)),a.erase(unique(all(a)),a.end
#define yeet        return 0;
#define nl          "\n"
#define de(x)       cout << #x << " = " << x << "\n";
#define HERE        cout << "HERE\n";
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
using namespace std;

const int mx = 1e5+10;
vector<int> adj[mx], r[mx];
unordered_map<int, unordered_set<int>> g;
int coins[mx], scc = 0;
ll dp[mx], scccoins[mx];
ll which[mx];
bool vis[mx];
int n, m; 
stack<int> st;
vector<int> comp;

void dfs1(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for(int v : adj[u])
        dfs1(v);
    st.push(u);
}

void dfs2(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    which[u] = scc;
    scccoins[scc] += coins[u];
    for(int v : r[u])
        dfs2(v);
    comp.push_back(u);
}

void createNEW() {
    for(int i = 1; i <= n; i++) {
        for(auto v : adj[i]) {
            if(which[i] != which[v]) {
                g[which[i]].emplace(which[v]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> coins[i];
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        r[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i])
            dfs1(i);
    }

    memset(vis,0,sizeof(vis));
    while(!st.empty()) {
        comp.clear();
        int u = st.top();
        st.pop();
        if(!vis[u]) {
            scc++;
            dfs2(u);
        }
    }

    createNEW();

    for(int i = 1; i <= scc; i++) {
        dp[i] = scccoins[i];
    }
    ll ans = 0;
    for(int i = 1; i <= scc; i++) {
        for(int v : g[i]) {
            dp[v] = max(dp[v], dp[i] + scccoins[v]);
            ans = max(dp[v], ans);
        }
        cout << endl;
    }

    cout << ans;
 
    return 0;
}
 
