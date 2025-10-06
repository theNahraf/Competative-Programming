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
int mod = 1e9 + 7;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int ways( vector<int>& dice, int total, vector<int>&dp){
    if(total == 0 ) return 1;
    if(total < 0 ) return 0;

    if(dp[total]!=-1) return dp[total];
    long long ans = 0;
    for(auto face : dice){
        ans  = ans + ways(dice, total - face, dp);
    }
    return dp[total] =  ans%mod;
   
}
int main() {
    fast;
    int total;
    cin>>total;
    vector<int> dice = {1, 2, 3, 4, 5, 6};
    vector<int> dp(total + 1 , -1);
    int ans = ways( dice, total, dp);
    cout<<ans<<endl;

   return 0;
}