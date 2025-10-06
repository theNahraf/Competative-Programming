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

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int mod =  1e9 + 7;
int solve(int i, int total, vector<vector<int>>&dp, vector<int>& coins){
    if(total == 0) return 1;
    if(i>=coins.size() || total < 0) return 0;
    if(dp[i][total] != -1) return dp[i][total];

    int nottake = solve(i+1, total,  dp, coins);
    int take = 0;
    if(total >= coins[i]){
        take = solve(i, total-coins[i], dp, coins);
    }
    return dp[i][total] =  (take + nottake)%mod;
}

int main() {
    fast;
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for (int &c : coins) cin >> c;
    vector<vector<int>>dp(n+1, vector<int>(x + 1, 0));
    
    for(int i =0; i<=n ; i++) dp[i][0]  = 1;

    for(int i = n - 1; i>=0 ; i--){
        for(int total = 0 ; total<=x ; total++){
        int nottake = dp[i+1][total];
        int take = 0;
        if(total >= coins[i]){
            take = dp[i][total-coins[i]];
        }
         dp[i][total] =  (take + nottake)%mod;
        }
    }
    cout<<dp[0][x];
    return 0;
}