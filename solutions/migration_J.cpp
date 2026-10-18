#include<bits/stdc++.h>

using namespace std;
using ll = long long;

map<char,int> mp1;
map<char,int> mp2;

bool had[13][4];
bool had1[13][4];
bool had2[13][4];

int cal1(){
    //皇家同花顺
    int cur = 0;
    for(int k=0 ; k<4 ; k++){
        int cur = 0;
        for(int i=8 ; i<=12 ; i++) if(had1[i][k]) cur++;
        if(cur==4)
    }
}

int cal2(){
    for()
}

void solve()
{
    for(int i=0 ; i<13 ; i++){
        for(int j=0 ; j<4 ; j++){
            had[i][j] = false;
            had1[i][j] = false;
            had2[i][j] = false;
        }
    }

    for(int i=0 ; i<4 ; i++){
        string ss; cin>>ss;
        had[mp1[ss[0]]][mp2[ss[1]]] = true;
        had1[mp1[ss[0]]][mp2[ss[1]]] = true;
    }
    for(int i=0 ; i<4 ; i++){
        string ss; cin>>ss;
        had[mp1[ss[0]]][mp2[ss[1]]] = true;
        had2[mp1[ss[0]]][mp2[ss[1]]] = true;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    mp1['A'] = 12;
    mp1['K'] = 11;
    mp1['Q'] = 10;
    mp1['J'] = 9;
    mp1['10'] = 8;
    mp1['9'] = 7;
    mp1['8'] = 6;
    mp1['7'] = 5;
    mp1['6'] = 4;
    mp1['5'] = 3;
    mp1['4'] = 2;
    mp1['3'] = 1;
    mp1['2'] = 0;

    mp2['C'] = 0;
    mp2['D'] = 1;
    mp2['H'] = 2;
    mp2['S'] = 3;
    
    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}