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
    string s;
    cin >> s;

    map<char, int> mp;

    for (char c : s) {
        mp[c]++;
    }

    list<char> ans;
    int odd = 0, oddn = -1;
    char oc = '%';

    for (auto [x, y] : mp) {
        if (y & 1) {
            odd++;
            oddn = y;
            oc = x;
        }
    }

    if (odd > 1) {
        cout << "NO SOLUTION\n";
        return;
    }

    while (odd and oddn--) {
        ans.push_back(oc);
    }

    for (auto [x, y] : mp) {
        if (x == oc) continue;

        for (int i = 0; i < y / 2; i++) {
            ans.push_back(x);
            ans.push_front(x);
        }
    }

    for (char x : ans) cout << x;
    cout << "\n";
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
