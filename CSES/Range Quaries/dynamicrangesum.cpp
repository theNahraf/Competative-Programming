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

class SegmentTree{
public:
     vector<ll> tree;
    SegmentTree(vector<ll> &arr){
        int n =  arr.size();
        tree.resize(4*n);
        build(0, 0, n-1, arr);
    }

    void build(int i , int l, int r, vector<ll> &arr){
        if(l==r){
            tree[i] = arr[l];
            return ;
        }

        int mid = (l+r)/2;
        build(2*i+1, l, mid, arr);
        build(2*i+2, mid+1, r , arr);
        tree[i] =  tree[2*i+1] + tree[2*i+2]; 
    }

    void update(int idx , ll value, int i, int l, int r){
        if(l==r){
            tree[i] = value;
            return ;
        }
        int mid = (l+r)/2;
        if(idx <= mid) update(idx, value, 2*i+1,  l, mid);
        else update(idx, value, 2*i+2, mid + 1, r);
        tree[i] =  tree[2*i+1] + tree[2*i+2];
    }

    ll rangesum(int i, int l, int r, int st, int end){
        if(l>end || r<st) return 0;
        if(l>=st && r<=end) return tree[i];
        int mid = (l+r)/2;
        return rangesum(2*i+1, l, mid, st, end) + rangesum(2*i+2, mid + 1, r, st, end);
    }


};

int main() {
    fast;
    int n, q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(int i = 0; i<n ; i++) cin>>arr[i];
    SegmentTree st(arr);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int k;
            ll u;
            cin>>k>>u;
            st.update(k-1, u, 0,0, n-1);
        }
        else{
            int a, b;
            cin>>a>>b;
            cout<<st.rangesum(0, 0, n-1, a-1, b-1)<<endl;
        }
    }
    return 0;
}