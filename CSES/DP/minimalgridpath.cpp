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

string solve(int i, int j, int n, vector<vector<char>> &grid, vector<vector<string>> &dp) {
    if (i >= n || j >= n) return "{"; // '{' is after 'Z' in ASCII, acts as infinity
    if (i == n-1 && j == n-1) return string(1, grid[i][j]);

    if (!dp[i][j].empty()) return dp[i][j];

    string down = solve(i+1, j, n, grid, dp);
    string right = solve(i, j+1, n, grid, dp);

    return dp[i][j] = string(1, grid[i][j]) + min(down, right);
}


int main() {
    fast;
    int n;
    cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<string>> dp(n+1, vector<string>(n+1, ""));

//giving memory limit ans


    string ans  = solve(0, 0, n, grid, dp);
    cout<<ans<<endl;
    return 0;
}

