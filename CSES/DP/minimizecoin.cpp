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
int count(int i, vector<int>&coins, vector<vector<int>>& dp, int total){
    
    if(i == 0){
        if(total%coins[i] == 0 ) return total/coins[0];
        return 1e9;
    }

    if(dp[i][total]!=-1) return dp[i][total];
    
    int take = 1e9;
    if(total >= coins[i])
    {
     take = 1 + count(i, coins, dp, total-coins[i]);
    }

    int nottake =  count(i-1, coins, dp, total);

    return dp[i][total] = min(take,nottake);
}
int main() {
    fast;
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i  = 0; i<n ; i++){
        cin>>coins[i];
    }

    int ans  = -1;
    if(n==1){
        if(x%coins[0]==0) ans =  x/coins[0];
        cout<<ans<<endl;
        return 0;
    }
    vector<vector<int>> dp(n, vector<int>(x+1, 0));

    //base case

    for(int total = 0 ; total<=x ; total++){
        if(total%coins[0]  == 0) dp[0][total]  =  total/coins[0];
        else dp[0][total] = 1e9;
    }
    
    for(int i  = 1 ; i<n; i++){
        for(int total = 0 ; total<=x ; total++){
            int take = 1e9;
        if(total >= coins[i])
        {
        take = 1 + dp[i][total-coins[i]];
        }

        int nottake =  dp[i-1][total];

         dp[i][total] = min(take,nottake);
        }
    }

    ans  = dp[n-1][x];
    cout<<(ans >= 1e9 ? -1 : ans)<<endl;

    return 0;
}