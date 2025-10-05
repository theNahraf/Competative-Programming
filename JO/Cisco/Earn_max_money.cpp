#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

       
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (i > j) continue;
            long long maxi = 0;
            for (int ind = i; ind <= j; ind++) {
                long long cost =  nums[i - 1] * nums[ind] * nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi,cost);
            }
            dp[i][j] = (int)maxi;
        }
    }
    return dp[1][n];

        // return maxcoins(1, n, nums, dp);
    }

int main() {
    fast;   
    int n; cin>>n;
    vector<int> arr(n);
    for(int i =0; i<=n ; i++) cin>>arr[i];
 
    int ans = maxCoins(arr);
   
    cout<<ans<<endl;
    return 0;
}