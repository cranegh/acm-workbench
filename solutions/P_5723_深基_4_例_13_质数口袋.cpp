#include<iostream>
using namespace std;
int isprime;
void check(int x);
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int l; cin>>l;
    
    int i=2,cnt=0,sum=0;
    while (i){
        check(i);
        if (isprime==1){
            sum+=i;
            if (sum>l) break;
            cout<<i<<'\n';
            cnt++;
        }
        i++;
    }
    cout<<cnt;
    return 0;
}
void check(int x){
    isprime=1;
    for (int i=2 ; i<x ; i++){
        if (x%i==0) {
        isprime=0;
        break;
        }
    }
}