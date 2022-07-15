#include "bits/stdc++.h"
#define fastio ios_base::sync_with_stdio(0), cin.tie(nullptr);
#define ll long long

using namespace std;

const int mxn = 1e3 + 1;
const int mod = 1e9 + 7;
ll dp[mxn][mxn];

void solve() {
    int n;
    cin >> n;

    string g[n];
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    dp[0][0] = g[0][0] != '*';
    for (int i = 1; i < n; i++) {
        if (g[0][i] != '*') {
            dp[0][i] += dp[0][i - 1];
        }
    }

    for (int i = 1; i < n; i++) {
        if (g[i][0] != '*') {
            dp[i][0] += dp[i - 1][0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (g[i][j] != '*') {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= mod;
            }
        }
    }

    cout << dp[n - 1][n - 1];
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
