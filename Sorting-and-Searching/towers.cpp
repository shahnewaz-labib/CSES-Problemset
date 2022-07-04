#include "bits/stdc++.h"
#define fastio ios_base::sync_with_stdio(0),cin.tie(nullptr);
#define ll long long

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...)
#endif

using namespace std;

void solve() {
    int n;
    cin>>n;

    multiset<int> s;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        auto base = s.upper_bound(x);
        if(base == s.end()) {
            s.insert(x);
        } else {
            s.erase(base);
            s.insert(x);
        }
    }

    cout << s.size();
}

int main() {
    fastio;
    int t;
    t = 1;
    for (int tc = 1; tc <= t; tc++) {
        /* printf("Case %d: ", tc); */
        solve();
    }
}
