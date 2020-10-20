/*
          __      __    _ __  
         / /___ _/ /_  (_) /_ 
        / / __ `/ __ \/ / __ \
       / / /_/ / /_/ / / /_/ /
 _____/_/\__,_/_.___/_/_.___/ 
/_____/                       

*/

#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9+7;

long long bigMod(long long a, long long p) {
    long long res = 1;
    while(p) {
        if(p&1) res = res * a % MOD;
        p >>= 1;
        a = a * a % MOD;
    }
    return res;
}

int main() {
    int p; cin >> p;
    cout << bigMod(2, p) << '\n';
    return 0;
}
