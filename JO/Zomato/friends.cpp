#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

bool bfs(int start, vector<int> &color, vector<vector<int>> &adj){
    color[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(color[it]==-1){
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it]==color[node]) return false;
        }
    }

    return true;
}

bool isbipartite(int mid, vector<vector<int>> &arr, int n){
  vector<vector<int>> adj(n);
  for(int i =0; i<n ; i++){
    int cnt = 0;
    for(int j  = 0; j<n ; j++){
        if(i!=j && arr[i][j] < mid){
            cnt++;
            adj[i].push_back(j);
            adj[j].push_back(i);
        } 
    }

    if(cnt == n - 1) return false;
  }

  vector<int> color(n, -1);
  for(int i =0; i<n ; i++){
    if(color[i]==-1 && bfs(i, color, adj)==false) return false;
  } 

    return true;
}

int main() {
    fast;
    int n; cin>>n;
  
    vector<vector<int>> arr(n, vector<int>(n));
    int maxwt  = 0;
    for(int i  = 0 ; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>arr[i][j];
           if(i!=j) maxwt = max(maxwt, arr[i][j]);
        }
    }

    int low = 0;
    int high = maxwt +  2;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isbipartite(mid,arr, n)){
            low = mid+1;
            ans = mid;
        }
        else{
            high =  mid-1;
        }
    }
    // cout<<isbipartite(702209412, arr,n);
    cout<<ans<<endl;
    return 0;
}