#include "bits/stdc++.h"
#define fastio ios_base::sync_with_stdio(0), cin.tie(nullptr);
#define ll long long

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...)
#endif

using namespace std;

void solve() {
    int t, n;
    cin >> t >> n;

    set<int> s;
    s.insert(0);
    s.insert(t);

    multiset<int> ans;
    ans.insert(t);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);

        auto pos = s.lower_bound(x);
        int ager = *prev(pos);
        int porer = *next(pos);

        ans.erase(ans.find(porer - ager));
        ans.insert(x - ager);
        ans.insert(porer - x);

        cout << *ans.rbegin() << " ";
    }
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
