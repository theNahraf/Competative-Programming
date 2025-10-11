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
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int mod =  1e9 + 7;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int ans(vector<ll>&arr, int q1, int q2){
    ll mini =1e9 + 1 ;
    for(int i = q1 ; i<=q2 ; i++){
        mini = min(mini, arr[i]);
    }
    return mini;
}

int main() {
    fast;
    int n, q;
    cin>>n>>q;
    vector<ll> arr(n+1);
    for(int i= 1; i<=n ; i++) cin>>arr[i];
    while(q--){
        int q1, q2;
        cin>>q1>>q2;
        cout<<ans(arr, q1, q2)<<endl;
    }
   return 0;
}