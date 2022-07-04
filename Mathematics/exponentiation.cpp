#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
 
ll power(ll a, ll b) {
    ll result = 1;
    while(b) {
        if(b&1) result = (result * a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return result;
}
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << power(a, b) << '\n';
    }
}
