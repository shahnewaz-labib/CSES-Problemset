#include <bits/stdc++.h>
using namespace std;

int maxdigit(int n) {
    int ans = -1;
    while(n) {
        ans = max(ans, n%10);
        n /= 10;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    int ans = 0;
    while(n) {
        n -= maxdigit(n);
        ans++;
    }
    cout << ans << '\n';
}