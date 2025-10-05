#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <string.h>

using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dp[10][2][64];


bool isprime(int n){
 if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


int solve(string &s, int idx, int tight, int sum){

    //base condition 
    if(idx == s.length()){
        if(isprime(sum)) return 1;
        return 0; 
    }

    if(dp[idx][tight][sum]!=-1) return dp[idx][tight][sum];

    int limit = tight == 1 ? s[idx]-'0' : 9;
    int ans = 0;
    for(int i = 0; i<=limit ; i++){
        int sumupdate =  sum + i;
        ans+= solve(s, idx+1, (tight & (i==s[idx]-'0')), sumupdate);
    }
    return dp[idx][tight][sum]  = ans;
}

int main() {
    fast;
    int t;
    cin>>t;
    while(t--){
        int l, r;
        cin>>l>>r;
        string ri =  to_string(r);
        memset(dp, -1, sizeof(dp));
        int rightans = solve(ri, 0, 1, 0);
        memset(dp, -1, sizeof(dp));
        string li = to_string(l-1);
        int leftans = solve(li, 0, 1, 0);
        cout<<rightans - leftans<<endl;
    }
    return 0;
}