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
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int mod =  1e9 + 7;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main() {
    fast;
    int n;
    cin>>n;
    vector<vector<ll>>arr(n, vector<ll>(3));
    vector<ll> endidx(n);
    for(int i =0 ; i<n ; i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
        cin>>arr[i][2];

    }


    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
        return a[1] < b[1];
    });

 for(int i = 0 ; i<n ; i++) endidx[i] = arr[i][1];

   vector<ll> dp(n+1, 0);
    
   for(int i = 1; i<=n ; i++){
        ll st =  arr[i-1][0];
        ll end = arr[i-1][1];
        ll reward = arr[i-1][2];

        int idx =  upper_bound(endidx.begin(), endidx.end(), st-1) - endidx.begin();
        ll nottake =  dp[i-1];
        ll take = reward + dp[idx];
        dp[i] =  max(nottake, take);
   }
    
    cout<<dp[n]<<endl;
    return 0;
}