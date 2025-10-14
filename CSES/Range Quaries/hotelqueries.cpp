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
    SegmentTree(vector<ll> arr){
        int n = arr.size();
        tree.resize(4*n);
        build(0,0,n-1,arr);
    }

    void build(int i, int l, int r, vector<ll>&arr){
        if(l==r){
            tree[i] = arr[l];
            return ;
        }
        
        int mid = (l+r)/2;
        build(2*i+1, l, mid, arr);
        build(2*i+2, mid + 1, r, arr);
        tree[i] = max (tree[2*i+1] ,tree[2*i+2]);
    }

    void updateval(int idx, ll val, int i, int l , int r){
        if(l==r){
            tree[i] = val;
            return ;
        }
        int  mid = (l + r)/2;
        if(idx<=mid) updateval(idx, val, 2*i+1, l, mid);
        else updateval(idx, val, 2*i+2, mid+1, r);
        tree[i] =  max(tree[2*i+1], tree[2*i+2]);
    }

    int firstupdate(ll val,int i, int l , int r ){

        if(tree[i] <  val) return 0;

        if(l==r){
            tree[i]-=val;
            return l+1;
        }

        int mid = (l+r)/2;
        int  ans ;
        if(tree[2*i+1] >= val)
            ans = firstupdate(val, 2*i+1, l, mid);
        else 
            ans = firstupdate(val, 2*i+2, mid + 1, r);
        
        tree[i] = max( tree[2*i+1], tree[2*i+2] );
        return ans;
    }

};

int main() {
    fast;
    int n,m;
    cin>>n>>m;
    vector<ll> hotels(n);
    vector<ll> groups(m);
    for(int i = 0; i<n ; i++) cin>>hotels[i];
    for(int i = 0; i<m ;i++) cin>>groups[i];
    SegmentTree st(hotels);
    vector<int> ans;
    for(int i = 0; i<m ; i++){
        ll grp = groups[i];
        ans.push_back(st.firstupdate(grp,0, 0, n-1));

    }

    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}