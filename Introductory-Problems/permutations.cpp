#include "bits/stdc++.h"
#define d(x) cerr << #x << " = " << x << endl;
using namespace std;
 
int main() {
    int n; cin >> n;
    if(n <= 3 and n != 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for(int i = 2; i <= n; i += 2) cout << i << " ";
    for(int i = 1; i <= n; i += 2) cout << i << " ";
}