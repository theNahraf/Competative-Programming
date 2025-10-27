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

struct Node{
    ll sum, maxsubsum, maxps, maxsf;
};

vector<int> arr;
vector<Node> tree;

Node merge(const Node& left, const Node& right){
    Node node;
    node.sum =  left.sum + right.sum;
    node.maxps = max(left.maxps, left.sum + right.maxps);
    node.maxsf = max(right.maxsf, right.sum + left.maxsf);
    
    node.maxsubsum = max({left.maxsubsum, right.maxsubsum, left.maxsf + right.maxps});
    return node;
}

void build(int i, int l ,  int r){
    if(l==r){
        tree[i] = {arr[l], arr[l], arr[l], arr[l]};
        return ;
    }

    int mid = (l + r)/2;
    build(2*i+1, l, mid);
    build(2*i+2, mid + 1, r);
    tree[i] = merge(tree[2*i+1], tree[2*i+2]);
}

void update(int i, int l, int r, int pos, int x){
    if(l==r){
        tree[i] = {x, x,x ,x};
        return ;
    }

    int mid = (l+r)/2;
    if(pos<=mid){
        update(2*i+1, l, mid, pos, x);
    }
    else{
        update(2*i+2, mid + 1, r, pos, x);
    }
    tree[i] = merge(tree[2*i+1], tree[2*i+2]);
}




int main() {
    fast;
    int n, m;
    cin>>n>>m;
    arr.resize(n);
    for(int i = 0; i<n ; i++) cin>>arr[i];
    tree.resize(4*n);
    build(0, 0, n-1);
    while(m--){
        int k, x;
        cin>>k>>x;
        update(0, 0, n-1, k-1, x);
        // Node res = query(0, 0, n-1, k-1);
        cout<<max(0LL, tree[0].maxsubsum)<<endl;
    }
    return 0;
}