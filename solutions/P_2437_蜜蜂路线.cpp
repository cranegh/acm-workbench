#include<iostream>
#include<cstring>

using namespace std;
using ll = long long;

const int N = 1e3;

string f[N];

    string operator + (const string a , const string b)
    {
    char sa[N],sb[N];
    for(int i=1 ; i<=a.length() ; i++) sa[i]=a[a.length()-i];
    for(int i=1 ; i<=b.length() ; i++) sb[i]=b[b.length()-i];

    int len=max(a.length(),b.length())+1;
    int ans[len+1];
    for(int i=1 ; i<=len ; i++) ans[i]=0;

    for(int i=1 ; i<=len ; i++){
        ans[i]+=sa[i]-'0'+sb[i]-'0';
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    while(!(ans[len])) len--;
    string s="";
    for(int i=len ; i>=1 ; i--) s+=ans[i];

    return s;
    }

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int m,n; cin>>m>>n;
    f[m]="1",f[m+1]="1";
    for(int i=m+2 ; i<=n ; i=i+1) f[i]=f[i-1]+f[i-2];

    cout<<f[n];

    return 0;
}