#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<ll> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << v[b] - v[a - 1] << '\n';
    }
}
