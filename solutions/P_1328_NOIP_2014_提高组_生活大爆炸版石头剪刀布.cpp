#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int N = 210;
int a[N],b[N];
int score[5][5]{
    {0,0,1,1,0},
    {1,0,0,1,0},
    {0,1,0,0,1},
    {0,0,1,0,1},
    {1,1,0,0,0}
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,na,nb; cin>>n>>na>>nb;
    for(int i=1 ; i<=na ; i++) cin>>a[i];
    for(int i=1 ; i<=nb ; i++) cin>>b[i];
    
    int cnta=0, cntb=0;
    for(int i=1 ; i<=n ; i++){
        int ca=i%na, cb=i%nb;
        if(ca==0) ca=na;
        if(cb==0) cb=nb;

        if(score[a[ca]][b[cb]]) cnta++;
        if(score[b[cb]][a[ca]]) cntb++;
    }

    cout<<cnta<<" "<<cntb;

    return 0;
}