#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
long long dp[20][2][4];

int solve(string &s, int idx, int tight, long long cnt)
{
    if(idx==s.length()) return 1;
    if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];

    int limit = (tight==1 ? (s[idx]-'0') : 9);
    int ans = 0 ;
    for(int i = 0; i<=limit ; i++){
        int updatecnt = cnt + (i != 0 ? 1 : 0);
        if(updatecnt <= 3){
            ans +=  solve(s, idx+1, (tight && (i == s[idx]-'0')) , updatecnt);
        }
    }
    return dp[idx][tight][cnt]= ans;
}

int main() {
    fast;
    int t; cin>>t;
    while(t--){
    long long l, r;
    cin>>l>>r;
    string ri = to_string(r);
    memset(dp, -1, sizeof(dp));
    int rightans = solve(ri, 0, 1, 0);
    string li =  to_string(l-1);
    memset(dp, -1, sizeof(dp));
    int leftans = solve(li, 0, 1, 0);
    cout<<rightans - leftans<<endl;
    }
    return 0;
}