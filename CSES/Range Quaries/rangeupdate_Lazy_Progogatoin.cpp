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
    vector<ll> lazy;  
    
    SegmentTree(vector<ll>&arr){
        int n = arr.size();
        tree.resize(4*n);
        lazy.resize(4*n, 0);
        build(0, 0, n-1, arr);
    }

    void build(int i , int l, int r, vector<ll> &arr){
        if(l==r){
            tree[i] =  arr[l];
            return ;
        }
        int mid =  (l+r)/2;
        build(2*i+1, l, mid, arr);
        build(2*i+2, mid + 1, r, arr);
        tree[i] =  tree[2*i+1] + tree[2*i+2]; 
    }

    ll indvalue(int idx, int i, int l, int r){
        if (lazy[i] != 0) {
        tree[i] += (r - l + 1) * lazy[i];
        if (l != r) {
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
         }

        if(l==r){
            return tree[i];
        }
        int mid = l  + (r-l)/2;
        if(idx <= mid) return indvalue(idx, 2*i+1, l, mid);
        return indvalue(idx, 2*i+2, mid + 1, r);
    }

    void rangeupdate(int i, int l, int r, int st, int end, ll val){
        if(lazy[i]!=0){
            tree[i] += (r-l+1)*lazy[i];
            if(l!=r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
        //out of the bound
        if(r<st || l>end) return ;
        
        //occupied
        if(l>=st && r<=end){
            tree[i]+=(r-l+1)*val;
            if(l!=r){
                lazy[2*i+1] += val;
                lazy[2*i+2] += val;
            }
            return ;
        }

        //overlapping
        int mid = l + (r-l)/2;
        
        rangeupdate(2*i+1, l, mid, st, end, val);
        rangeupdate(2*i+2, mid + 1, r, st, end, val);

        tree[i] =  tree[2*i+1] + tree[2*i+2];
    }

};

int main() {
    fast;
    int n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(int i = 0; i<n ; i++) cin>>arr[i];
    SegmentTree st(arr);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int a, b;
            ll u;
            cin>>a>>b>>u;
            st.rangeupdate(0, 0, n-1,a-1, b-1, u);
        }
        else{
            int k;
            cin>>k;
            cout<<st.indvalue(k-1, 0, 0, n-1)<<endl;
        }
    }
    return 0;
}