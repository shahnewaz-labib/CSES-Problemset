#include<bits/stdc++.h>
#define ll long long
#define MAX(a, b) (a) > (b) ? (a) : (b)
 
using namespace std;
 
ll solve(vector<long long>& v) {
	ll ans = -1e18+5;
	ll sum = 0;
	for(int x : v) {
		sum += x;
		ans = MAX(ans, sum);
		sum = MAX(0, sum);
	}
	return ans;
}
 
int main() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for(auto& i : v) cin >> i;
	cout << solve(v) << '\n';
 
}