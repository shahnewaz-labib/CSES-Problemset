#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll want[n], have[m];

    for (int i = 0; i < n; i++) cin >> want[i];
    for (int i = 0; i < m; i++) cin >> have[i];

    sort(want, want + n);
    sort(have, have + m);

    int i = 0, j = 0, ans = 0;

    while (i < n and j < m) {
        if (want[i] - k > have[j]) {
            j++;
        } else if (want[i] + k < have[j]) {
            i++;
        } else {
            i++, j++, ans++;
        }
    }

    cout << ans << "\n";
}
