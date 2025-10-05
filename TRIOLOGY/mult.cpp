#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include<math.h>


using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

long long powi(long long base, int exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

string katapeete(map<int, int>&num, map<int, int> &den){
    for(auto&it : num){
        if(den.find(it.first)!=den.end()){
            
            if(num[it.first] >= den[it.first]){
                num[it.first]-=den[it.first];
                den.erase(it.first);
            }
            else{
                den[it.first]-=num[it.first];
                num.erase(it.first);
            }
    }
    }
    int numer = 1;
    int denmo = 1;
    for(auto it : num){
        numer = numer*powi(it.first, it.second);
    }
    
    for(auto it : den){
        denmo = denmo*powi(it.first, it.second);
    }

    return to_string(numer) + "/" + to_string(denmo);
}

map<int, int> addmap(map<int,int> mp1, map<int, int> mp2){
    
   for (const auto &p : mp2) {
        mp1[p.first] += p.second;
    }
    return mp1;

}


map<int, int> primefactor(long long n) {
    map<int, int> mp;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 1) mp[n]++;
    return mp;
}


map<int, int> mulmap(map<int, int> mp1, map<int, int> mp2) {
    long long val1 = 1;
    long long val2 = 1;
    for (auto &it : mp1) {
        val1 *= powi(it.first, it.second);
    }
    for (auto &it : mp2) {
        val2 *= powi(it.first, it.second);
    }

    long long summed = val1 + val2; // this is the numerator: a*v + u*b
    return primefactor(summed);
}



int main() {
    fast;
      string s;
    cin >> s; // Example: "22/52+3/2"

    int a = 0, b = 0, u = 0, v = 0;
    string temp = "";
    bool firstFractionDone = false;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != '/' && s[i] != '+') {
            temp += s[i]; // build number
        }
        else if (s[i] == '/') {
            if (!firstFractionDone) {
                a = stoi(temp); // numerator of first fraction
            } else {
                u = stoi(temp); // numerator of second fraction
            }
            temp = "";
        }
        else if (s[i] == '+') {
            b = stoi(temp); // denominator of first fraction
            temp = "";
            firstFractionDone = true;
        }
    }
    // after loop, temp holds last denominator
    v = stoi(temp);

    map<int, int> mpa  = primefactor(a);
    map<int, int> mpb  = primefactor(b);
    map<int, int> mpu  = primefactor(u);
    map<int, int> mpv  = primefactor(v);

    
    map<int, int> av =  addmap(mpa, mpv);
    map<int, int> bu =  addmap(mpb, mpu);
    map<int, int> bv =  addmap(mpb, mpv);

    map<int, int> mp_av_bu = mulmap(av, bu);

    string ans = katapeete(mp_av_bu, bv);

    cout<<ans<<endl;



    return 0;
}
