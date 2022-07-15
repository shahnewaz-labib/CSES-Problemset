#include "bits/stdc++.h"
#define fastio ios_base::sync_with_stdio(0), cin.tie(nullptr);
#define ll long long

using namespace std;

const int mxn = 1e6 + 1;
const int mod = 1e9 + 7;
int dp[mxn];

void solve() {
    int n, target;
    cin >> n >> target;

    vector<int> v(n);
    for (int &i : v) cin >> i;

    dp[0] = 1;
    for (int sum = 1; sum <= target; sum++) {
        for (int i = 0; i < n; i++) {
            int coin = v[i];
            if (sum - coin >= 0) {
                dp[sum] += dp[sum - coin];
                dp[sum] %= mod;
            }
        }
    }

    cout << dp[target];
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
