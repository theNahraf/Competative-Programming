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
int solve(int total, vector<int> &dp){
    if(total <= 0) return 0;
    if(dp[total] != -1) return dp[total];

    string st = to_string(total);
    int ans = INT_MAX;
    for(auto &c : st){
        int d  =  c-'0';
        if(d==0) continue; 
         ans  = min(ans, 1 + solve(total - d , dp));
    }
   return dp[total] = ans;
}
int main() {
    fast;
    int x;
    cin>>x;
    vector<int> dp(x+1, -1);
    cout<<solve(x, dp)<<endl;
    return 0;
}