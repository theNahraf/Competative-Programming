#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);       
    for (int &c : coins) cin >> c;
    
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    
    for (int total = 1; total <= x; total++) {
        for (int c : coins) {
            if (total >= c) {
                dp[total] += dp[total - c];
                if (dp[total] >= MOD) dp[total] -= MOD; // faster than %
            }
        }
    }
    
    cout << dp[x];
    return 0;
}
