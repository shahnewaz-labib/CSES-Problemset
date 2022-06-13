#include "bits/stdc++.h"
#define ll long long
#define V vector<ll>
#define srtv(x) sort(x.begin(), x.end())
#define srta(x, n) sort(x, x + n)

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...)
#endif

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    map<int, int> mp;
    int ans = 0;

    for (int i = 0, j = 0; i < n and j < n; i++) {
        while (j < n and mp[v[j]] < 1) {
            mp[v[j]]++, j++;
        }
        ans = max(ans, j - i);
        mp[v[i]]--;
    }

    cout << ans << "\n";
}

int main() {
    int t;
    t = 1;
    for (int tc = 1; tc <= t; tc++) {
        /* printf("Case %d: ", tc); */
        solve();
    }
}
