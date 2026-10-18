#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5+9;
int h[N],b[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,m,k;
    cin>>n>>m>>k;

    for(int i=1 ; i<=n ; i++)
    cin>>h[i];
    for(int i=1 ; i<=m ; i++)
    cin>>b[i];
    
   sort(h+1,h+n+1); 
   sort(b+1,b+m+1); 

   int i=1,j=1,cnt=0;
   while(i<=n && j<=m){
    if(h[i]<=b[j]){
        i++;
        j++;
        cnt++;
    }
    else j++;
   }
   if(cnt>=k) cout<<"Yes";
   else cout<<"No";

   return 0;
}