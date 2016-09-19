#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
string aa[][2] = {
"1967","DavidBowie",
"1969","SpaceOddity",
"1970","TheManWhoSoldTheWorld",
"1971","HunkyDory",
"1972","TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars",
"1973","AladdinSane",
"1973","PinUps",
"1974","DiamondDogs",
"1975","YoungAmericans",
"1976","StationToStation",
"1977","Low",
"1977","Heroes",
"1979","Lodger",
"1980","ScaryMonstersAndSuperCreeps",
"1983","LetsDance",
"1984","Tonight",
"1987","NeverLetMeDown",
"1993","BlackTieWhiteNoise",
"1995","1.Outside",
"1997","Earthling",
"1999","Hours",
"2002","Heathen",
"2003","Reality",
"2013","TheNextDay",
"2016","BlackStar"};
typedef pair<int,string> IS;
int T,a,b;
vector<IS> dic;
int main(){
	cin>>T;
    int l = sizeof(aa)/sizeof(string)/2;
    for(int i=0;i<l;i++){
        dic.push_back( IS(atoi(aa[i][0].c_str()),aa[i][1]) );
    }
    while(T--){
        cin>>a>>b;
        auto it = lower_bound(ALL(dic), IS(a,"")); 
        auto jt = upper_bound(ALL(dic), IS(b,"zz")); 
        stringstream ss;
        int c=0;
        for(; it!=jt; ++it){
            ss<<it->first<<" "<<it->second<<"\n";
            c++;
        }
        cout<<c<<"\n"<<ss.str();
    }
	return 0;
}
