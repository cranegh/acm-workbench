#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int p[4], c[4];
map<string,int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mp["ZhuJiaoFan"] = 0;
    mp["KaoLengMian"] = 1;
    mp["NaiCha"] = 2;
    mp["GuoCha"] = 3;

    for(int i=0; i<4; i++) cin>>p[i];
    for(int i=0; i<4; i++) cin>>c[i];

    int pl,cl; cin>>pl>>cl;

    string f,d; cin>>f>>d;
    int tt_p = 0, tt_c = 0;

    tt_p += p[mp[f]];
    tt_p += p[mp[d]];
    tt_c += c[mp[f]];
    tt_c += c[mp[d]];

    if(tt_p <= pl && tt_c <= cl){
        cout<<"Piggy Good\n";
    }
    else if(tt_p > pl && tt_c <= cl){
        cout<<"Piggy Poor\n";
    }
    else if(tt_p <= pl && tt_c > cl){
        cout<<"Piggy Fat\n";
    }
    else cout<<"Piggy Bad\n";


}