#include<iostream>

using namespace std;
using ll = long long;
const int N = 7e4;

char cap[N];
int num_W=0,num_L=0,cnt=1;;

void print(){
    cout<<num_W<<':'<<num_L<<'\n';
}

void f11(){
    for(int i=1 ; i<=cnt ; i++)
    {
        if(cap[i]=='E'){
        print();
        num_W=0,num_L=0;
        break;
        }
        if(cap[i]=='W') num_W++;
        if(cap[i]=='L') num_L++;
        if((num_W>=11 || num_L>=11) && abs(num_W-num_L)>=2){
            print();
            num_W=0,num_L=0;
        }
    }
}

void f21(){
    for(int i=1 ; i<=cnt ; i++)
    {
        if(cap[i]=='E'){
        print();
        break;
        }
        if(cap[i]=='W') num_W++;
        if(cap[i]=='L') num_L++;
        if((num_W>=21 || num_L>=21) && abs(num_W-num_L)>=2){
            print();
            num_W=0,num_L=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    char cur_c;
    while(cin>>cur_c){
        cap[cnt]=cur_c;
        if(cur_c=='E') break;
        cnt++;
    }

    f11();
    cout<<'\n';
    f21();

    return 0;
}