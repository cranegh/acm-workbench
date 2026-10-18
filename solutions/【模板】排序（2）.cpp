/*
#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

const int N = 2e5+5;

struct book{
    int a,b,c;
    bool operator < (const book &u)const
    {
        if(a==u.a && b==u.b) return c<u.c;
        if(a==u.a) return b<u.b;
        return a<u.a;
    }
}p[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>p[i].a>>p[i].b>>p[i].c;
    sort(p+1,p+1+n);
    reverse(p+1,p+1+n);

    for(int i=1 ; i<=n ; i++) cout<<p[i].a<<" "<<p[i].b<<" "<<p[i].c<<'\n';
    return 0;
}*/

#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

const int N = 2e5+5;

struct book{
    int a,b,c;
}p[N];

bool cmp (const book &x , const book &y);
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>p[i].a>>p[i].b>>p[i].c;
    sort(p+1,p+1+n,cmp);
    

    for(int i=1 ; i<=n ; i++) cout<<p[i].a<<" "<<p[i].b<<" "<<p[i].c<<'\n';
    return 0;
}
bool cmp (const book &x , const book &y){
    if(x.a==y.a && x.b==y.b) return x.c>y.c;
    if(x.a==y.a) return x.b>y.b;
    return x.a>y.a;
}