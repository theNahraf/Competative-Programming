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
int solve(int i, int n, int money, vector<int>& prices, vector<int>&pages, vector<vector<int>> &dp){

    if(i<0 || money < 0) return 0;
    
    if(dp[i][money] != -1) return dp[i][money];

    int notbuy = solve(i-1, n, money, prices, pages, dp);
    int buy = 0;
    if(money >= prices[i]){
        buy = pages[i]  + solve(i-1, n, money - prices[i],prices,  pages, dp);
    }

    return dp[i][money]  = max(buy, notbuy);

}
int main() {
    fast;
    int n, x;
    cin>>n>>x;
    vector<int> prices(n);
    vector<int> pages(n);
    for(int i = 0; i<n ; i++) cin>>prices[i];
    for(int i = 0; i<n ; i++) cin>>pages[i];
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    
    for(int i = 0 ; i<=n ; i++){
        for(int money  = 0 ; money<=x ; money++){

        if(i==0){
            dp[i][money] = (money >= prices[i]) ? pages[i] : 0;
        }else{

            int notbuy = dp[i-1][money];
            int buy = 0;
            if(money >= prices[i]){
                buy = pages[i]  + dp[i-1][money- prices[i]];
            }
            
            dp[i][money]  = max(buy, notbuy);
        }
        }
    }

    // cout<<solve(n-1, n, x, price, pages, dp)<<endl;
    cout<<dp[n][x];
    return 0;
}