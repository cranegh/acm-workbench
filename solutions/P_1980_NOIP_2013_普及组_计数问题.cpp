#include<iostream>
using namespace std;
int main(){
    int n,x,ans=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        int j=i;
        while (j>0)
        {
        int num=j%10;
        if(num==x) ans++;
        j/=10;
        }
        }
    cout<<ans;
    return 0;
}