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
typedef long long ll;
int mod =  1e9 + 7;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
vector<ll> presum(vector<ll> &arr){
    vector<ll> ps(arr.size() + 1);
    ps[0] = 0;
    for(int i = 0; i<arr.size() ; i++){
        ps[i+1] = ps[i] + arr[i];
    }
    return ps;
}
int main() {
    fast;
    int n, q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(int i = 0 ; i<n ; i++) cin>>arr[i];
    vector<ll> ps = presum(arr);
    while(q--){
        ll q1, q2;
        cin>>q1>>q2;
        cout<<ps[q2] - ps[q1-1]<<endl;
    }

    return 0;
}