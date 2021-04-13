#include "bits/stdc++.h"
#define fastio		    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll			    long long
#define pii 		    pair<int, int>
#define MIN(x,y)	    (x) < (y) ? x : y
#define MAX(x,y)	    (x) > (y) ? x : y
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end
#define de(x)           cout << #x << " = " << x << "\n";
#define HERE            cout << "HERE\n";
#define precision(a)    fixed << setprecision(a)
#define endl            '\n'

#ifdef lmao 
#include "dbg.h" 
#else 
#define dbg(...) {} 
#endif

int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
using namespace std;

const int mxn = 1e6+1;
int c[101];
int dp[mxn];
void solve() {
    int n,s;cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=s;i++){
        dp[i]=1000000000;
        for(int j=0;j<n;j++){
            if(c[j]<=i){
                dp[i] = min(dp[i],dp[i-c[j]]+1);
            }
        }
    }
    cout<<(dp[s] == 1000000000 ? -1 : dp[s]);
}

int main() {
    int T=1;
    //cin>>T;
    for(int tc=1;tc<=T;tc++) {
        //printf("Case %d:\n", tc);
        solve();
    }

	return 0;
}
