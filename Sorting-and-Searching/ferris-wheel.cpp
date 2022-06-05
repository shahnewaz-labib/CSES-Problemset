#include "bits/stdc++.h"
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int ans = n, i = 0, j = n - 1;

    while (i < j) {
        if (v[i] + v[j] <= m) {
            ans--;
            i++, j--;
        } else {
            j--;
        }
    }

    cout << ans << "\n";
}

int main() { solve(); }
