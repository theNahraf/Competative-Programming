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
typedef long long ll;
int mod =  1e9 + 7;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll solve(int i, ll target, vector<int> &arr, vector<vector<ll>>&dp){
    if(target == 0) return 1;
    if (i == arr.size()) return (target == 0);
    if(dp[i][target]!=-1) return dp[i][target];

    ll notpick  = solve(i+1, target, arr, dp);
    ll pick = 0;
    if(target >= arr[i]) pick  =  solve(i+1, target - arr[i], arr, dp);
    
    return dp[i][target] = (pick  + notpick)%mod;
}

int main() {
    fast;
    ll n;
    cin>>n;
    int totalsum  = (n*(n+1))/2;
    if(totalsum%2==1){
        cout<<0<<endl;
        return 0;
    }
    ll target = totalsum/2;
    vector<int> arr(n);
    for(int i = 0; i<n ; i++) arr[i] = i+1;

    vector<vector<ll>>dp(n+1, vector<ll>(target  + 1 , 0));

// cout << (solve(0, target, arr, dp) * ((mod + 1) / 2)) % mod;

    for(int i = 0; i<=n ; i++){
        dp[i][0] = 1;
    }
    for(int i = n-1; i>=0; i--){
        for(int t  = 0; t<=target; t++){
            ll notpick  = dp[i+1][t];
            ll pick = 0;
            if(t >= arr[i]) pick  =  dp[i+1][t - arr[i]];
         dp[i][t] = (pick  + notpick)%mod;
        }
    }
    int inv = (mod + 1)/2;
    cout<<dp[0][target]*inv % mod;

    return 0;
}   