#include "bits/stdc++.h"
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    int ans = 0, time = 0;

    for(pair<int,int> m : v) {
        if(time <= m.first) {
            ans++;
            time = m.second;
        }
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
