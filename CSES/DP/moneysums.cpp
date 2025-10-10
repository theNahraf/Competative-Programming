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
int mod =  1e9 + 7;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    fast;
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i =0; i<n; i++) cin>>coins[i];

    set<int> st;
    st.insert(0);
    
    for(auto coin : coins){
        vector<int> newcoins;
        for(auto s : st){
            newcoins.push_back(s + coin);
        }
        for(auto nc : newcoins){
            st.insert(nc);
        }
    }

    st.erase(0);

    cout<<st.size()<<endl;
    for(auto i : st){
        cout<<i<<" ";
    }


    return 0;
}