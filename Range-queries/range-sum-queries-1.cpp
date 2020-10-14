#include "bits/stdc++.h"
using namespace std;
 
int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> v(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }
    // for(int x : v) cout << x << " ";
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << v[b]-v[a-1] << '\n';
    }
    return 0;
 
}
