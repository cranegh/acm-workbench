#include<iostream>
#include<cstring>
int f[1010];
using namespace std;
int sol(int x);
int main(){
    memset(f,-1,sizeof(f));
    f[1]=1;
    int n;
    cin>>n;
    cout<<sol(n);
    return 0;
}
int sol(int x){
    if (x==1) return 1;
    if(f[x]!=-1) return f[x];
    int ans=1;
    for (int i=1; i<=x/2 ; i++)
    {
        ans+=sol(i);
    }
    return f[x]=ans;
}