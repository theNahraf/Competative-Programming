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

int lcs(int i, int j, vector<int> & a1,  vector<int> &a2, vector<vector<int>>&dp){

    if(i<0 || j<0) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];

    if(a1[i]!=a2[j]){
        dp[i][j] = max(lcs(i-1, j, a1, a2, dp), lcs(i, j-1, a1, a2, dp));
    }
    else{
        dp[i][j] =  1 + lcs(i-1, j-1, a1, a2, dp);
    }   
    return dp[i][j];
}
int main() {
   fast;
    int n,m;
    cin>>n>>m;
    vector<int> a1(n);
    vector<int> a2(m);
    for(int i =0; i<n ; i++) cin>>a1[i];
    for(int i =0; i<m ; i++) cin>>a2[i];


    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    //1 base indexing
    //base case already done

    for(int i = 1; i<=n ; i++){
        for(int j = 1; j<=m ; j++){
        if(a1[i-1]!=a2[j-1]){
             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        else{
            dp[i][j] =  1 + dp[i-1][j-1];
        }   
        }
    }

    int len = dp[n][m];
    
    int i = n , j = m;
    vector<int> lcsarr;
    while(i>0 && j>0){
        if(a1[i-1] == a2[j-1]){
            lcsarr.push_back(a1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(lcsarr.begin() , lcsarr.end());
    
    cout<<len<<endl;
    for(auto i : lcsarr){
        cout<<i<<" ";
    }
    
    
    return 0;
}   