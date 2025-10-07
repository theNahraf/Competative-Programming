#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;
int mod  =  1e9 + 7;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int countpath(int i, int j,int n,  vector<vector<char>>& grid, vector<vector<int>> &dp){   
    if(i<0 || j<0 || j>=n || i>=n) return 0;
    if (grid[i][j] == '*') return 0;
    if(i ==0 && j == 0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=0 , left = 0;
    if(i > 0 && grid[i-1][j] != '*'){
        up =  countpath(i-1, j, n, grid, dp);
    }
    if(j > 0 && grid[i][j-1] != '*'){
        left = countpath(i, j-1, n, grid, dp);
    }
    dp[i][j] = (left + up)%mod;
    return dp[i][j]; 
}
int main() {
    fast;
    int n;
    cin>>n;
    vector<vector<char>>grid(n, vector<char>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n ; j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    cout<<countpath(n-1, n-1,n, grid, dp)<<endl;
    return 0;
}