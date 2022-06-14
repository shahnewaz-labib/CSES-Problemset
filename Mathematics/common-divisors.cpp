#include "bits/stdc++.h"

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...)
#endif

using namespace std;

const int mxAns = 1e6;
int mp[mxAns + 1];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    for (int ans = mxAns; ans >= 0; ans--) {
        int cnt = 0;

        for (int num = ans; num <= mxAns; num += ans) {
            cnt += mp[num];
        }

        if (cnt > 1) {
            cout << ans << "\n";
            break;
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
