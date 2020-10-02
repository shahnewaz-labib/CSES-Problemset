#include "bits/stdc++.h"
#define d(x) cerr << #x << " = " << x << endl;
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<long long> v(n);
    for(auto&i:v) cin >> i;
    long long mx = v[0];
    long long ans = 0;
    for(int i = 1; i < n; i++) {
        // d(mx)
        if(v[i] < v[i-1]) {
            ans += v[i-1]-v[i];
            v[i] = v[i-1];
        }
        mx = max(mx, v[i]);
    }
    cout << ans;
}