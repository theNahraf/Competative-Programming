#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
   fast;
    int t;
    cin>>t;
    while(t--){
        int n, p;
        cin>>n>>p;
        vector<int> a(n);
        vector<int>b(n);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];

        vector<pair<int, int>> vec;
        for(int i=0; i<n;i++){
            vec.push_back({b[i], a[i]});
        }
    sort(vec.begin(), vec.end());
        
    long long  mincost = p;
    long long already_shared = 1;
    for(auto it : vec){
        long long can_shared = it.second;
       long long shared_cost = it.first;

       if(shared_cost >= p){
            break;
       }
       if(already_shared + can_shared > n){
        mincost += (n-already_shared)*shared_cost;    
        already_shared = n;
            break;
       }
       else{
            mincost += shared_cost*can_shared;
            already_shared+=can_shared;
       }
    }
   if (already_shared < n) {
    mincost += (n - already_shared) * p;
}
    cout<<mincost<<endl;
    }
    return 0;
}