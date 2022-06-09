#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> s;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    for (int i = 0; i < m; i++) {
        cin >> x;
        auto it = s.upper_bound(x);

        if (it == s.begin()) {
            cout << "-1\n";
        } else {
            cout << *(--it) << "\n";
            s.erase(it);
        }
    }
}

int main() {
    int t;
    t = 1;
    for (int tc = 1; tc <= t; tc++) {
        /* printf("Case %d: ", tc); */
        solve();
    }
}

