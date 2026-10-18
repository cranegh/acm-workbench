#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,a,b; cin>>n>>a>>b;

    if(a==0 && b==0){
        cout<<n<<'\n';
        for(int i=1 ; i<=n ; i++){
            cout<<"0:0\n";
        }
    }else if(n==1 && a==b){
        cout<<1<<'\n';
        cout<<a<<':'<<b;
    }else if(n<=a+b){
       cout<<0<<'\n';
        if(a>=b){
            if(b>=n){
                for(int i=1;i<=n-1;i++){
                    cout<<"0:1"<<'\n';
                }
                cout<<a<<":"<<b-n+1<<'\n';
            }
            else {
                for(int i=1;i<=b;i++){
                    cout<<"0:1"<<'\n';
                }
                for(int i=1;i<=n-b-1;i++){
                    cout<<"1:0"<<'\n';
                }
                cout<<a-(n-b-1)<<":"<<0<<'\n';
            }
        }
        else if(a<b){
            if(a>=n){
                for(int i=1;i<=n-1;i++){
                    cout<<"1:0"<<'\n';
                }
                cout<<a-n+1<<":"<<b<<'\n';
            }
            else {
                for(int i=1;i<=a;i++){
                    cout<<"1:0"<<'\n';
                }
                for(int i=1;i<=n-a-1;i++){
                    cout<<"0:1"<<'\n';
                }
                cout<<0<<":"<<b-(n-a-1)<<'\n';
            }
        }
    }
    else if(n>a+b){
        cout<<n-(a+b)<<'\n';
        for(int i=1;i<=n-(a+b);i++){
            cout<<"0:0"<<'\n';
        }
        n=a+b;
        if(a>=b){
            if(b>=n){
                for(int i=1;i<=n-1;i++){
                    cout<<"0:1"<<'\n';
                }
                cout<<a<<":"<<b-n+1<<'\n';
            }
            else {
                for(int i=1;i<=b;i++){
                    cout<<"0:1"<<'\n';
                }
                for(int i=1;i<=n-b-1;i++){
                    cout<<"1:0"<<'\n';
                }
                cout<<a-(n-b-1)<<":"<<0<<'\n';
            }
        }
        else if(a<b){
            if(a>=n){
                for(int i=1;i<=n-1;i++){
                    cout<<"1:0"<<'\n';
                }
                cout<<a-n+1<<":"<<b<<'\n';
            }
            else {
                for(int i=1;i<=a;i++){
                    cout<<"1:0"<<'\n';
                }
                for(int i=1;i<=n-a-1;i++){
                    cout<<"0:1"<<'\n';
                }
                cout<<0<<":"<<b-(n-a-1)<<'\n';
            }
        }
    }
    return 0;
}