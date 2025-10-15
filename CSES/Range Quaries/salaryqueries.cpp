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
    int n;
    vector<int> tree;

    void update(int idx, int l, int r, int pos, int delta){
        if(l==r){
            tree[idx] += delta;
            return;
        }

        int mid = (l+r)/2;
        if(pos <= mid) update(2*idx + 1, l, mid, pos, delta);
        else update(2*idx+2, mid + 1, r, pos, delta);
        tree[idx]  = tree[2*idx+1] + tree[2*idx+2];
    }

    int query(int i, int l, int r, int q1, int q2){
        if(q1>r || q2<l) return 0;
        if(q1<=l && r<=q2) return tree[i];
        int mid = (l+r)/2;
        return query(2*i+1, l, mid, q1, q2) + query(2*i+2, mid + 1, r, q1, q2);
    }

public:
    SegmentTree(int n){
        this->n = n;
        tree.assign(4*n, 0);
    }
    
    void add(int pos, int delta){
        update(0, 1, n, pos,delta);
    }

    int rangesum(int l, int r){
        if(l>r) return 0;
        return query(0, 1, n, l, r);
    }
};

int main() {
    fast;
    int n, q;
    cin>>n>>q;
    vector<ll> salary(n);
    for(int i = 0; i<n ; i++) cin>>salary[i];
    
    //collect all values;
    vector<tuple<char, int, int>> queries;
    vector<int> allvals;
    allvals.reserve(n + 2*q);

    for(int i  = 0; i<n; i++) allvals.push_back(salary[i]);

    while(q--){
        char type;
        cin>>type;
        if(type=='!'){
            int k, x;
            cin>>k>>x;
            queries.push_back({type, k, x});
            allvals.push_back(x);
        }
        else{
            int a, b;
            cin>>a>>b;
            queries.push_back({type, a, b});
            allvals.push_back(a);
            allvals.push_back(b);
        }
    }

    //cooordinatoin compression
    sort(allvals.begin(), allvals.end());
    allvals.erase(unique(allvals.begin(), allvals.end()), allvals.end());

    //lowerbound + 1 index get by lamda
    auto getid = [&](int x){
        return int(lower_bound(allvals.begin(), allvals.end(), x) - allvals.begin()  + 1);
    };

    int maxid = allvals.size();
    SegmentTree st(maxid);

    //initialize freqeuencies
    vector<int> salaryId(n);
    for(int i = 0 ; i < n ; i++){
        salaryId[i] =  getid(salary[i]);
        //filling our segment tree with new values
        st.add(salaryId[i], 1);
    }

    //process queries

    for(auto [type, a, b] : queries){
       
        //update at index k, update its cnt at mapped postion
        if(type == '!'){
            int  k = a, x=b;
            int newid = getid(x);
            st.add(salaryId[k-1], -1);
            salaryId[k-1] =  newid;
            st.add(newid, +1);
        }else{
            int l = getid(a);
            int r = getid(b);
            cout<<st.rangesum(l, r)<<endl;
        }
    }


    return 0;
}