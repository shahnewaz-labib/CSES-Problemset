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
#define precision(a) fixed << setprecision(a)
#define endl '\n'
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
using namespace std;

struct edge {
    int u, v, w;
    bool operator<(const edge& p) const {
        return w < p.w;
    }
};

const int mx = 1e5+1;
vector<edge> e;
int par[mx];

int find(int r) {
    if(par[r] == r) return r;
    return par[r] = find(par[r]);
}

ll mst(int n, int m) {
    sort(e.begin(), e.end());
    for(int i = 1; i <= n; i++) {
        par[i] = i;
    }

    ll count = 0, s = 0;
    for(int i = 0; i < m; i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if(u != v) {
            count++;
            par[u] = v;
            s += e[i].w;
            if(count == n-1) {
                // There exists a single tree
                return s;
            }
        }
    }
    // No vaild tree
    return -1;

}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e.push_back({u, v, w});
    }
    ll ans = mst(n, m);
    if(ans != -1)   cout << ans << "\n";
    else            cout << "IMPOSSIBLE\n";


	return 0;
}
