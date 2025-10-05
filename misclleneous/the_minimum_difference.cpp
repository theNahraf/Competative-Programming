// Write your code here
#include<iostream>
using namespace std;

void string_helper(string& s1, string&s2, int n){
    for(int i =0; i<n; i++){
        if(i%2==0){
            s1+='w';
            s2+='b';
        }
        else{
            s1+='b';
            s2+='w';
        }
    }
}


int min_box(string s){
    int n = s.length();
    string st =  s + s;
    int m = st.length();
    string alt1 = "";
    string alt2 = "";
    string_helper(alt1, alt2, m);
    int diff1 = 0;
    int diff2 = 0;
    int minidiff = n;

    for(int i =0 ; i<m; i++){
        if(st[i]!=alt1[i]) diff1++;
        if(st[i]!=alt2[i]) diff2++;

        if(i>=n){
            if(st[i-n]!=alt1[i-n]) diff1--;
            if(st[i-n]!=alt2[i-n]) diff2--;
        }
        if(i>=n-1){
            minidiff =  min(minidiff,min(diff1, diff2));
        }
    }

    return minidiff;

}

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        cout<<min_box(s)<<endl;
    }
}
