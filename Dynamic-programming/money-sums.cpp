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

int arr[101], n;
bool dp[101][100001];

void f(int pos, int sum) {
    if (pos > n or dp[pos][sum]) return;

    dp[pos][sum] = true;

    f(pos + 1, sum);
    f(pos + 1, sum + arr[pos]);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    f(0, 0);

    V ans;
    for (int i = 1; i <= 100000; i++) {
        if (dp[n][i]) ans.push_back(i);
    }

    srtv(ans);

    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x << " ";
    }
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

/*
 * From: ssshanto
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, mx = 0; cin >> n;
  vector<int> coins(n, 0);
  for(auto &i:coins) cin >> i, mx += i;

  vector<vector<bool>> dp(n+1, vector<bool>(mx+1, 0));
  vector<int> possible;

  function<void(int, int)> f = [&](int idx, int sum) {
    if(idx > n or dp[idx][sum]) return;
    dp[idx][sum] = true;
    f(idx+1, sum+coins[idx]), f(idx+1, sum);
  };

  f(0, 0);

  for(int i=1; i<=mx; i++) if(dp[n][i]) possible.push_back(i);
  sort(possible.begin(), possible.end());
  
  cout << possible.size() << "\n";
  for(auto v:possible) cout << v << " ";
}
*/


