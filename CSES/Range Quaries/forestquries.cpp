#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> pre(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<long long>> prefixsum(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prefixsum[i][j] = grid[i][j];
            if (i > 0) prefixsum[i][j] += prefixsum[i - 1][j];
            if (j > 0) prefixsum[i][j] += prefixsum[i][j - 1];
            if (i > 0 && j > 0) prefixsum[i][j] -= prefixsum[i - 1][j - 1];
        }
    }

    return prefixsum;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> grid(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            grid[i][j] = (row[j] == '*') ? 1 : 0;
        }
    }

    vector<vector<long long>> prefixsum = pre(grid);

    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--; // Convert to 0-based indexing

        long long ans = prefixsum[y2][x2];
        cout<<ans<<endl;

        if (y1 > 0) ans -= prefixsum[y1 - 1][x2];
               cout<<ans<<endl;
        if (x1 > 0) ans -= prefixsum[y2][x1 - 1];
               cout<<ans<<endl;
        if (y1 > 0 && x1 > 0) ans += prefixsum[y1 - 1][x1 - 1];
        

        cout << ans << "\n";
    }

    return 0;
}
