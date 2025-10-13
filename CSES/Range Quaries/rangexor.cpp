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
    int n;
    vector<ll> tree;

    SegmentTree(vector<ll> arr){
        int n = arr.size();
        tree.resize(4*n);
        build(0,0, n-1, arr);
    }

    void build(int i, int l, int r, vector<ll> &arr){
        if(l==r){
            tree[i] =  arr[l];
            return ;
        }

        int mid = (l + r)/2;
        build(2*i + 1, l, mid, arr);
        build(2*i +2 , mid + 1, r, arr);
        tree[i] = tree[2*i +1] ^ tree[2*i + 2];
    }


  ll rangexor(int i, int l, int r, int st, int end){
        if(l>end || r<st) return 0;
        if(l>=st && r<=end) return tree[i];
        int mid = (l+r)/2;
        return rangexor(2*i+1, l, mid, st, end) ^ rangexor(2*i+2, mid+1, r, st, end);
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
        
        cout<<st.rangexor(0, 0, n-1, q1-1, q2-1)<<endl;
    }
    
    
    return 0;
}