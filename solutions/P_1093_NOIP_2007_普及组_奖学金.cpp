#include<iostream>
#include<algorithm>
using namespace std;
const int N =3e2+9;

struct student{
    int n,t,a,b,c;
    bool operator < (const student &u) const{
        if(u.t==t && u.a==a) return n>u.n;
        else if(u.t==t) return a<u.a;
        else return t<u.t;  
    }
}s[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n; cin>>n;

    for(int i=1 ; i<=n ;i++){
        cin>>s[i].a>>s[i].b>>s[i].c;
        s[i].n=i;
    }
    for(int i=1 ; i<=n ;i++){
        s[i].t=s[i].a+s[i].b+s[i].c;
    }

    sort(s+1,s+1+n);
    reverse(s+1,s+1+n);

    for(int i=1 ; i<=5 ;i++){
        cout<<s[i].n<<' '<<s[i].t<<'\n';
    }
    
    return 0;
}