#include "bits/stdc++.h"
using namespace std;
 
int main() {
    string s; cin >> s;
    int ans = 1;
    for(int i = 0; i < s.size()-1; i++) {
        int count = 1;
        while(s[i] == s[i+1]) count++, i++;
        ans = max(ans, count);
    }
    cout << ans;
}