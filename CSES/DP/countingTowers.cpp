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
int maxn = 1e6;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
int main() {
    fast;

    //dp[i][0] for width 1
    //dp[i][1] for widht 2
    // vector<vector<ll>> dp(maxn+1, vector<ll>(2, 0));
    // vector<ll> w1(maxn + 1, 0);
    // vector<ll> w2(maxn + 1, 0);

    //base case
    // dp[1][0] = 1;
    // dp[1][1] = 1;
    // w1[1] = 1;
    // w2[1] = 1;
    
    ll prevw1 = 1;
    ll prevw2 = 1;
    //1 base indexing

    vector<int> totalways(maxn +1 , 0);
    totalways[1] = (prevw1 + prevw2)%mod;
    for(int i = 2; i<=maxn ; i++){
       ll curretw1  = (4*prevw1 + prevw2)%mod;
       ll currentw2 = (2*prevw2 + prevw1)%mod;
        prevw1 = curretw1;
        prevw2 =  currentw2;
        totalways[i] = (currentw2 + curretw1)%mod;
    }
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans =  totalways[n]%mod;
        cout<<ans<<endl;
    }
    return 0;
}