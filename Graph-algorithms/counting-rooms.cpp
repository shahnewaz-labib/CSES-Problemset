#include <bits/stdc++.h>
using namespace std;
string s[100000];
int row, col;
int fx[] = {0, 1, 0, -1};
int fy[] = {1, 0, -1, 0};
 
 
void dfs(int x, int y) {
    if(!(x >= 0 and x < row and y >= 0 and y < col and s[x][y] == '.')) return;
    s[x][y] = '#';
    for(int i = 0; i < 4; i++)
        dfs(x+fx[i], y+fy[i]);
}
 
int main() {
    cin >> row >> col;
    for(int i = 0; i < row; i++) cin >> s[i];
    int ans = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(s[i][j] == '.') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
}
