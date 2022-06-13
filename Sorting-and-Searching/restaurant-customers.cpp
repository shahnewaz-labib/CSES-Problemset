#include "bits/stdc++.h"
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        ll arrive, leave;
        cin >> arrive >> leave;

        v.push_back({arrive, +1});
        v.push_back({leave, -1});
    }

    sort(v.begin(), v.end());

    ll cur = 0, ans = 0;

    for (pair<int, int> moment : v) {
        cur += moment.second;

        ans = max(ans, cur);
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
