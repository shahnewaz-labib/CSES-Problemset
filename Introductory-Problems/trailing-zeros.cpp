#include "bits/stdc++.h"
#define d(x) cerr << #x << " = " << x << endl;
using namespace std;
 
int main() {
    int n; cin >> n;
    int zero = 0;
    for(int i = 5; n/i != 0; i *= 5)
        zero += n/i;
    cout << zero << '\n';
}