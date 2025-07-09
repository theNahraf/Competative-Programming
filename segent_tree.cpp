#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int a[100005];
int seg[4*100005];

void build(int i, int low, int high){
    if(low == high){
        seg[i] = a[low];
        return;
    }
    int mid = (low + high)/2;
    build(2*i+1,low, mid );
    build(2*i+2,mid+1, high);

    seg[i] = max(seg[2*i+1], seg[2*i + 2]);
}


int query(int i, int low, int high, int l, int r){
   
   //when cdompletely occur
    if(low>=l && high<=r){
        return seg[i];
    }
    

    //jab dono me na lie kre
    if(high < l || low > r) return INT_MIN;

    //when overlap
    int mid =  (low + high)/2;
    int left = query(2*i+1, low, mid, l, r);
    int right = query(2*i+2, mid+1, high, l, r);
    return max(right, left);
}

int main() {
    int n;
    cin>>n;
    for(int i =0 ;i<n; i++){
        cin>>a[i];
    }   

    build(0, 0, n-1);
    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<query(0, 0, n-1, l, r)<<endl;
    }





    return 0;
}