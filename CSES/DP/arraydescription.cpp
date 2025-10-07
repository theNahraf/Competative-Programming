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
int mod =  1e9 + 7;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



int main() {
    fast;
    int n, m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i =0; i<n ; i++) cin>>arr[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    //base case
    if(arr[0]!=0) dp[0][arr[0]] = 1;
    else{
        for(int k = 1; k<=m ; k++) dp[0][k] = 1;
    }

    for(int i = 1; i<n ; i++){
        if(arr[i]!=0){
            int v = arr[i];
            long long val =  dp[i-1][v];
            if(v-1>=1) val =  (val + dp[i-1][v-1])%mod;
            if(v+1 <= m) val = (val + dp[i-1][v + 1])%mod;
            dp[i][v] = val%mod;
        }
        else{
            for (int v = 1; v <= m; v++) {
                long long val = dp[i - 1][v];
                if (v - 1 >= 1) val = (val + dp[i - 1][v - 1]) % mod;
                if (v + 1 <= m) val = (val + dp[i - 1][v + 1]) % mod;
                dp[i][v] = val % mod;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i<=m ; i++){
     ans = (ans + dp[n-1][i]) % mod;
    }

    cout<<ans%mod<<endl;

    return 0;
}