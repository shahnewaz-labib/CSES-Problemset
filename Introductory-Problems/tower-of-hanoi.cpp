#include "bits/stdc++.h"
#define fastio ios_base::sync_with_stdio(0), cin.tie(nullptr);
#define ll long long

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...)
#endif

using namespace std;

void move(int n, int a, int b, int c) {
    if (n) {
        move(n - 1, a, c, b);
        cout << a << " " << c << "\n";
        move(n - 1, b, a, c);
    }
}

void solve() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    move(n, 1, 2, 3);
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
