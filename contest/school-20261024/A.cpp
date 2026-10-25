#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h,m; cin>>h>>m;

    int t1 = 0, t2 = 0;

    while(1){
        if(0<=h && h<24 && 0<=m && m<60){
            int a = h/10, b = h%10;
            int c = m/10, d = m%10;

            int dh = a*10 + c;
            int dm = b*10 + d;
            if(0<=dh && dh<24 && 0<=dm && dm<60){
                cout<<h<<" "<<m<<endl;
                break;
            }
        }

        m++;
        t1++;
        if(m == 60){
            h++;
            m = 0;
        }

        if(h == 24){
            h = 0;
        }
    }



}