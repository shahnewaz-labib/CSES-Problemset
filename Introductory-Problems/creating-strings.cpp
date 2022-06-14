#include "bits/stdc++.h"

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...)
#endif

using namespace std;

void solve() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    vector<string> ans;

    do {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << ans.size() << "\n";
    for (string x : ans) cout << x << "\n";
}

int main() {
    int t;
    t = 1;
    for (int tc = 1; tc <= t; tc++) {
        /* printf("Case %d: ", tc); */
        solve();
    }
}
