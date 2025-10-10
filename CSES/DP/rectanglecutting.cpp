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
int mod =  1e9 + 7;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int n = 501;
// full size de dia, taaki outof bound na jaaye agar a ,b k size allot krenge to
int dp[n][n];
int solve( int a, int b){
 
  if(a==b) return 0;
  if(a==1) return b  - 1;
  if(b==1) return a - 1;
 
  if(dp[a][b] != -1) return dp[a][b];
  if(dp[b][a]!=-1) return dp[b][a];

  dp[a][b] = 1e9;

    for(int i= 1; i<=a-1; i++){
        dp[a][b] = min(dp[a][b], solve(a-i, b) + solve(i, b) + 1);
    }
    for(int i= 1; i<=b-1; i++){
        dp[a][b] = min(dp[a][b], solve(a, i) + solve(a, b-i) + 1 );
    }
    return dp[a][b];
 
}
 
int main() {
    fast;
    int a, b;
    cin>>a>>b;
   memset(dp , -1, sizeof dp);
    int ans = solve( a, b);
    cout<<ans<<endl;
    return 0;
}