#include "bits/stdc++.h"
#define fastio ios_base::sync_with_stdio(0), cin.tie(nullptr);
#define ll long long

using namespace std;

const int mxn = 1e6 + 1;
const int mod = 1e9 + 7;
int dp[mxn];

void solve() {
    int n;
    cin >> n;

    dp[0] = 1;
    for (int sum = 1; sum <= n; sum++) {
        for (int dot = 1; dot <= 6; dot++) {
            if (sum - dot >= 0) {
                dp[sum] += dp[sum - dot];
                dp[sum] %= mod;
            }
        }
    }

    cout << dp[n];
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
