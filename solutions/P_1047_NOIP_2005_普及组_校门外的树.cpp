#include<iostream>
using namespace std;
int main(){
    int l,m,a[10010]={0},ans=0;
    cin>>l>>m;
    for(int num=0 ; num<m ;num++)
    {
        int u,v;
        cin>>u>>v;
        for (int j=u ; j <= v; j++)
        {
            a[j]=1;
        }
    }
    for(int k=0 ; k<=l ; k++){
        if( a[k]==0 ){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}