#include "bits/stdc++.h"
#define fastio ios_base::sync_with_stdio(0), cin.tie(nullptr);
#define ll long long

using namespace std;

const int N = 2e5 + 9;

int a[N];
struct ST {
    int t[4 * N];
    static const int inf = INT_MAX;
    ST() { memset(t, 0, sizeof t); }
    void build(int n, int b, int e) {
        if (b == e) {
            t[n] = a[b];
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = min(t[l], t[r]);
    }
    void upd(int n, int b, int e, int i, int x) {
        if (b > i || e < i) return;
        if (b == e && b == i) {
            t[n] = x;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[n] = min(t[l], t[r]);
    }
    int query(int n, int b, int e, int i, int j) {
        if (b > j || e < i) return inf;
        if (b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        int L = query(l, b, mid, i, j);
        int R = query(r, mid + 1, e, i, j);
        return min(L, R);
    }
} t;

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    t.build(1, 1, n);

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << t.query(1, 1, n, x, y) << "\n";
    }
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
