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

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans ^= x;
    }
    if (ans == 0)
        cout << "second\n";
    else
        cout << "first\n";
}

int main() {
    int t;
    t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        /* printf("Case %d: ", tc); */
        solve();
    }
}
