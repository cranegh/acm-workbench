#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int huiwen,isprime;
void checkhuiwen(string x);
void checkisprime(int x);

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int a,b; cin>>a>>b;
    if (a%2==0) a+=1;
    for (int i=a ; i<=b ; i+=2){
        string x=to_string(i);
        checkhuiwen(x);
        if (huiwen==1){
            checkisprime(i);
            if (isprime==1) cout<<i<<'\n';
        }
    }
    return 0;
}
void checkhuiwen(string x){
    huiwen=1;
    for (int i=0 ; i<x.length() ; i++){
        s.push(x[i]);
    }
    for (int i=0 ; i<x.length() ; i++){
        if(x[i]==s.top()){
            s.pop();
        }
        else {
            huiwen=0;
            break;
        }
    }
}
void checkisprime(int x){
    isprime=1;
    for (int i=2 ; i*i<=x ; i++){
        if ( x%i==0 ){
            isprime=0;
            break;
        }
    }
}