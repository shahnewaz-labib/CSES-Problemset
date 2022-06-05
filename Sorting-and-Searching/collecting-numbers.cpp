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

const int mxn = 2e5 + 10;

int arr[mxn];
int idx[mxn];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        idx[arr[i]] = i + 1;
    }

    int ans = 1;

    for (int i = 1; i <= n - 1; i++) {
        if (idx[i] > idx[i + 1]) ans++;
    }

    cout << ans << "\n";
}

int main() {
    int t;
    t = 1;
    /* cin >> t; */
    for (int tc = 1; tc <= t; tc++) {
        /* printf("Case %d: ", tc); */
        solve();
    }
}


