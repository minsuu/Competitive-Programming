#include <bits/stdc++.h>
using namespace std;
 
vector<int> zFunction(const string &s) { /* O(n) */
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++ i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
string s;
long long cnt;

inline int getZ(const vector<int> &z, int i){
    return 0<=i && i<(int)z.size() ? z[i] : 0;
}
void findSquares(string s, int shift){
    int n = (int) s.length();
    if(n <= 1 ) return;
    int nu = n/2, nv = n-nu;
    string u = s.substr(0, nu), v = s.substr(nu);
    string ru = string(u.rbegin(), u.rend()),
           rv = string(v.rbegin(), v.rend());

    findSquares(u, shift);
    findSquares(v, shift + nu);

    vector<int> z1 = zFunction(ru),
                z2 = zFunction(v+ '#' +u),
                z3 = zFunction(ru+ '#' +rv),
                z4 = zFunction(v);

    for(int r=0, l, k1, k2; r<n; ++r) {
        if( r<nu ){
            l = nu - r;
            k1 = getZ(z1, nu-r);
            k2 = getZ(z2, nv+1+r);
        }else{
            l = r-nu+1;
            k1 = getZ(z3, (nu+1) + nv-1 -(r-nu) );
            k2 = getZ(z4, (r-nu)+1);
        }
        if( k1+k2 >= l ){
            cnt += ( min(l,k1) - max(1, (l-k2)) + 1 );
            if( r<nu && l<=k1 && 0<=k2 ) cnt--;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    while(1) {
        cin>>s;
        if( s[0] == '0' ) break;
        cnt = 0;
        findSquares(s,0);
        cout<<cnt<<"\n";
    }
    return 0;
}