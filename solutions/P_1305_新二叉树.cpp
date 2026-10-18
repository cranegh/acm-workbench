#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;
const int N = 300;
struct node{
    char l,r;
}t[N];

void f(char x){
    if(x=='*') return;

    cout<<x;
    f(t[x].l);
    f(t[x].r);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;

    char par,l,r; cin>>par>>l>>r;
    t[par]={l,r};
    char root = par;
    for(int i=2 ; i<=n ; i++)
    {
        char par,l,r; cin>>par>>l>>r;
        t[par]={l,r};
    }

    f(root);
    
    return 0;
}