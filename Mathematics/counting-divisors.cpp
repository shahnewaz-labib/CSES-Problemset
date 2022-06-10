#include "bits/stdc++.h"
using namespace std;

// Sol 1
void solve1() {
    int n;
    cin >> n;

    int cnt = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt += 2;
            cout << n / i << " " << i << "\n";
        }
        if (n == i * i) cnt--;
    }

    cout << cnt << "\n";
}

// Sol 2

void solve2() {
    int n;
    cin >> n;

    int cnt = 1, val = sqrt(n);

    for (int i = 2; i <= val; i++) {
        int c = 0;
        while (n % i == 0) n /= i, c++;
        cnt *= (c + 1);
    }

    if (n > 1) cnt *= 2;

    cout << cnt << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve2();
    }
}
