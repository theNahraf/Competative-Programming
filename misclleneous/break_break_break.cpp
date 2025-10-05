#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;




bool isPossible(const vector<int>& arr, ll k, ll maxVal) {
    ll ops = 0;
    for (int a : arr) {
        ops += (a + maxVal - 1) / maxVal - 1;
        if (ops > k) return false;
    }
    return true;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; ll k;
        cin >> n >> k;
        vector<int> arr(n);
        int maxA = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            maxA = max(maxA, arr[i]);
        }

        int low = 1, high = maxA, ans = maxA;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << '\n';
    }
}
