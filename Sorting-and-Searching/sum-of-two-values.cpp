#include "bits/stdc++.h"
#define d(x) cerr << #x << " = " << x << endl;
using namespace std;
 
int main() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> p;
    int x;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        p.push_back({x, i});
    }
    sort(p.begin(), p.end());
    int i = 0, j = n-1;
    while(i < j) {
        if(p[i].first + p[j].first == k) {
            cout << p[i].second << " " << p[j].second << '\n';
            return 0;
        } else if(p[i].first + p[j].first < k) i++;
        else j--;
    }
    cout << "IMPOSSIBLE\n" << '\n';
    return 0;
}