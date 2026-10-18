#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
using ll = long long;
const int N =5010;
struct Bigint{
    int len,a[N];
    Bigint(int x=0){
        memset(a,0,sizeof(a));
        for(len=1 ; x ; len++){
            a[len]=x%10;
            x/=10;
        }
        len--;
        if(x==0) len=1;
    }
    int& operator[](int i){
        return a[i];
    }
    void flatten(int L){
        len=L;
        for(int i=1 ; i<=len ;i++){
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
        while(!a[len]){
            len--;
        }
    }
    void print(){
        for(int i=len ; i>=1 ; i--){
            cout<<a[i];
        }
    }
};
Bigint dp[N];
Bigint operator+ ( Bigint a , Bigint b){
    Bigint c;
    c.len=max(a.len,b.len);
    for(int i=1 ; i<=c.len ; i++){
        c[i]=a[i]+b[i];
    }
    c.flatten(c.len+1);
    return c;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n;
    cin >> n;
    dp[0] = Bigint(1); 
    dp[1] = Bigint(1);

    for(int i=2 ; i<=n ; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
        dp[n].print();
        return 0;
}
