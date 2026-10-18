#include<iostream>
using namespace std;
const int N =3e5+6;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,a,b;
    string s;
    cin>>n>>a>>b>>s;

    int na=0,nb=0,ans=0;
    for(int r=0 ; r<n ; r++)
    for(int l=0 ; l<r ; l++)
    for(int i=l ; i<=r ; i++){
        if (s[i]=='a') na++;
        if (s[i]=='b') nb++;
        if(i=r && na>=a && nb<b ) ans++;
    }
    
    cout<<ans<<'\n';
    return 0; 
}