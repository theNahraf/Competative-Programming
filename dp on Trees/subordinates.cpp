#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<int> tree[200001];

void solve(int src, int parent, vector<int>&ans){
    int subsor = 0;
    for(int child : tree[src]){
        if(child!=parent){
            solve(child, src, ans);
            subsor += 1 + ans[child];
        }
    }

    ans[src] = subsor;
}

int main() {
    fast;
    int n, x; cin>>n;
    vector<int> ans(n+1);
    for(int i = 2 ; i<=n ; i++){
        cin>>x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }

    solve(1, 0, ans);
    for(int i = 1 ; i<=n ; i++) cout<<ans[i]<<' ';
    
    return 0;
}