#include<bits/stdc++.h>

using namespace std;
#define int long long
const int MAXN=1e5+5;
vector<int>g[MAXN][2];
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
auto bing(int x,int y){
    vector<int>a,b;
    for(int&ax:g[x][0]){
        for(int&ay:g[y][0]){
            int ma=max(ax,ay);
            int mi=min(ax,ay);
            if(ma%mi==0)ax=mi,ay=mi;
        }
    }
    for(int ax:g[x][0])a.push_back(ax);
    for(int ay:g[y][0])a.push_back(ay);
    a.erase(unique(a.begin(),a.end()),a.end());
    for(int&bx:g[x][1]){
        for(int&by:g[y][1]){
            int ma=max(bx,by);
            int mi=min(bx,by);
            if(mi%ma==0)bx=mi,by=mi;
        }
    }
    for(int bx:g[x][0])b.push_back(bx);
    for(int by:g[y][0])b.push_back(by);
    b.erase(unique(b.begin(),b.end()),b.end());

    return make_pair(a,b);
}
auto jiao(int x,int y){
    vector<int>a,b;
    for(int&ax:g[x][0]){
        for(int&ay:g[y][0]){
            int k=lcm(ax,ay);
            a.push_back(k);
        }
    }
    a.erase(unique(a.begin(),a.end()),a.end());
    for(int&bx:g[x][1]){
        for(int&by:g[y][1]){
            int k=lcm(bx,by);
            b.push_back(k);
        }
    }
    b.erase(unique(b.begin(),b.end()),b.end());
    return make_pair(a,b);
}
auto bu(int x){

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,q;cin>>n>>m>>q;
    for(int i=1;i<=n;i++)g[i][0].push_back(i);
    for(int i=1;i<=m;i++){
        int opt;cin>>opt;
        if(opt==1){

        }
    }
   

    return 0;
}