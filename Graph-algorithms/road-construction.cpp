#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+1;
int par[mx], sz[mx];

int find(int r) {
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    
    int cc = n, mx = 1;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        int pu = find(a);
        int pv = find(b);

        if(pu != pv) {
            cc--;
            if(sz[pu] > sz[pv]) swap(pu, pv);
            par[pu] = pv;
            sz[pv] += sz[pu];
            mx = max(mx, sz[pv]);
        }

        cout << cc << " " << mx << "\n";
    }

    return 0;
}

