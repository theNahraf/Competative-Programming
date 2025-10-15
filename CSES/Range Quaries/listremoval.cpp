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
        int n= arr.size();
        tree.resize(4*n);
        build(0, 0, n-1);
    }
    void build(int i ,int l , int r){
        if(l==r){
            tree[i] = 1;
            return ;
        }
        int mid = (l+r)/2;
        build(2*i+1, l, mid);
        build(2*i+2, mid + 1, r);
        tree[i] = tree[2*i+1] + tree[2*i+2];
    }

    int update(int ind, int i, int l, int r){
        if(l==r){
            tree[i] = 0;
            return l;
        }
        int mid = (l + r)/2;
        int leftcnt  =  tree[2*i+1];
        int ans;
        if(ind <= leftcnt){
            ans =  update(ind,2*i+1,l , mid);
        }
        else{
            ans = update(ind-leftcnt, 2*i+2, mid + 1,r);
        }
        tree[i] = tree[2*i+1] + tree[2*i+2];
        return ans;
    }

};

int main() {
    fast;
    int n;
    cin>>n;
    vector<ll>arr(n);
    vector<ll>task(n);
    for(int i = 0; i<n ; i++) cin>>arr[i];
    for(int i = 0; i<n ; i++) cin>>task[i];

    SegmentTree st(arr);
    vector<int> ans;
    for(int i = 0; i<n ; i++){
        int ind = task[i];
        int idx = st.update(ind, 0, 0, n-1);
        ans.push_back(arr[idx]);
    }

    for(auto it : ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}