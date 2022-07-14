#include "bits/stdc++.h"
#define fastio ios_base::sync_with_stdio(0), cin.tie(nullptr);
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    ll sum = 0;
    for (int &i : v) cin >> i, sum += i;

    ll ans = INT_MAX;
    for (ll mask = 1; mask < (1 << n); mask++) {
        ll cur = 0;
        for (int i = 0; i < 31; i++) {
            if (mask & (1 << i)) {
                cur += v[i];
            }
        }
        ll rest = sum - cur;
        ans = min(ans, abs(cur - rest));
    }
    cout << ans << "\n";
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
