#include "bits/stdc++.h"
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n], dp[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }
    int len = -1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j]+1);
            len = max(len, dp[i]);
        }
    }
    assert(len != -1);
    cout << len << '\n';
    return 0;
}
