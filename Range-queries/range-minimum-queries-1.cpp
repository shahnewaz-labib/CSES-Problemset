#include "bits/stdc++.h"
#define ll long long
using namespace std;
ll n, k, q;
ll arr[200010];
ll table[200010][20];

void gen() {
    for (int i = 0; i < n; i++) table[i][0] = arr[i];
    for (int k = 1; k < 20; k++) {
        for (int i = 0; i + (1 << k) <= n; i++)
            table[i][k] =
                min(table[i][k - 1], table[i + (1 << (k - 1))][k - 1]);
    }
}

void rmq(int l, int r) {
    ll k = log2(r - l + 1);
    cout << min(table[l][k], table[r - (1 << k) + 1][k]) << '\n';
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];
    gen();
    int l, r;
    while (q--) {
        cin >> l >> r;
        l--, r--;
        rmq(l, r);
    }
    return 0;
}
