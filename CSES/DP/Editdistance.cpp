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

//let s1 small 
int solve(int i, int j, string s1, string s2, vector<vector<int>>&dp){
    if(i<0 ) return j+1;
    if(j<0) return i+1;

    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i] != s2[j]){
        int remove = 1 + solve(i-1, j, s1, s2, dp);
        int add = 1 + solve(i, j-1, s1, s2, dp); 
        int replace = 1 + solve(i-1, j-1, s1, s2, dp);
        dp[i][j] = min(add, min(remove, replace));
    }   
    else{
        dp[i][j] =  0 + solve(i-1, j-1, s1, s2, dp);
    }
    return dp[i][j];
}

int main() {
    fast;
    string s1, s2;
    cin>>s1>>s2;
    int n =  s1.length();
    int m = s2.length();

    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    //Edit distance is symmetric — the number
    //  of edits required to convert s1 → s2 
    // is the same as s2 → s1.
    
    // vector<vector<int>>dp2(m+1, vector<int>(n+1, -1));
    // //s1 to s2 conversion
    // int ans = solve(n-1, m-1, s1, s2, dp);
    

    // //s2 to s1 converstion 
    // int ans2 =  solve(m-1, n-1, s2, s1, dp2);
    // cout<<min(ans2, ans)<<endl;

    for(int i = 0; i<=n ; i++) dp[i][0]  = i;
    for(int j  = 0; j<=m ; j++) dp[0][j] = j;

    for(int i = 1; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++){
        if(s1[i-1] != s2[j-1]){
        int remove = 1 + dp[i-1][j];
        int add = 1 + dp[i][j-1]; 
        int replace = 1 + dp[i-1][j-1];
        dp[i][j] = min(add, min(remove, replace));
    }   
    else{
        dp[i][j] =  0 + dp[i-1][j-1];
    }
        }
    }

    cout<<dp[n][m]<<endl;


    return 0;
}