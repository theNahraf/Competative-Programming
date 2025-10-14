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
private:
      vector<ll> tree;
      vector<ll> lazy;
    int n;
    void build(int i, int l, int r, vector<ll> &arr){
        if(l==r){
            tree[i] =  arr[l];
            return ;
        }

        int mid = (l + r)/2;
        build(2*i + 1, l, mid, arr);
        build(2*i +2 , mid + 1, r, arr);
        tree[i] = tree[2*i +1] + tree[2*i + 2];
    }

    void updatequery(int idx, int value, int i, int l, int r){
        if(l==r){
            tree[i] = value;
            return ;
        }

        int mid = (l+r)/2;
        if(idx<=mid) updatequery(idx, value, 2*i+1, l , mid);
        else updatequery(idx, value, 2*i+2, mid + 1, r);
        tree[i] = tree[2*i + 1] + tree[2*i + 2];
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


    ll rangesum(int i, int l, int r, int st, int end){
        if(l>end || r<st) return 0;
        if(l>=st && r<=end) return tree[i];
        int mid = (l+r)/2;
        return rangesum(2*i+1, l, mid, st, end) + rangesum(2*i+2, mid+1, r, st, end);
    }  

public:
    SegmentTree(vector<ll> &arr){
        n =  arr.size();
        tree.resize(4*n);
        lazy.resize(4*n, 0);
        build(0,0,n-1, arr);
    }

    ll getSum(int st, int end){
        return rangesum(0, 0, n-1, st, end);
    }

    void setValue(int idx,  ll val){
        updatequery(idx, val, 0, 0, n-1);
    }


};

int main() {
    fast;
    int n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(int i = 0 ; i<n ; i++) cin>>arr[i];
    SegmentTree st(arr);
    while(q--){
        int q1, q2;
        cin>>q1>>q2;
        // rangesum calling
        
        cout<<st.getSum(q1-1, q2-1)<<endl;
    }
    
    
    return 0;
}