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

void update(int i, int l, int r, int pos, ll x, vector<ll> &tree){
    if(l==r){
        tree[i] = x;
        return; 
    }

    int mid = (l + r)/2;
    if(pos <= mid){
        update(2*i+1, l, mid, pos, x, tree);
    }
    else{
        update(2*i+2, mid + 1, r, pos, x, tree);
    }
    tree[i] = min(tree[2*i+1], tree[2*i+2]);
}

int query(int i, int l, int r, int q1, int q2, vector<ll> &tree){
    
    if(l>q2 || r<q1) return INT_MAX;
    if(l>=q1 && r<=q2) return tree[i];

    int mid = (l+r)/2;
    int leftans =  query(2*i+1, l, mid, q1,q2,  tree);
    int rightans = query(2*i+2,  mid+1, r, q1, q2, tree);
    return min(leftans, rightans);

}
int main() {
    fast;
    int n, q;
    cin>>n>>q;
    
    vector<ll> arr(n);
    for(int i =0; i<n ; i++) cin>>arr[i];
    
    vector<ll> tree1(4*n, INT_MAX), tree2(4*n, INT_MAX);
    for(int i = 0; i<n ; i++){
        //pos[a] - a; zero based indexing
        update(0, 0, n-1, i, arr[i]-(i+1), tree1);
        //pos[a] + a;
        update(0, 0, n-1, i, arr[i]+(i+1), tree2);
    }   
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int k;
            ll x;
            cin>>k>>x;
            //left
            // p[k] -> x
            //p[a] - a  -> x - k
            update(0, 0, n-1, k-1, x-k, tree1);
            //right
            update(0, 0, n-1, k-1, x+k, tree2);
        }
        else{
            int k;
            cin>>k;
            //zero based indxing
            int left = query(0, 0, n-1, 0, k-1, tree1);
            int right  =  query(0, 0, n-1, k-1, n-1, tree2);
            cout<<min(left+k, right-k)<<endl;
        }
    }
    return 0;
}   