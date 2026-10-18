#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,k; scanf("%d %d",&n,&k);
    
    int Acnt=0,Bcnt=0;
    int Asum=0,Bsum=0;
    for (int i=1 ; i<=n ; i++){
        if(i%k==0){
            Asum+=i;
            Acnt++;
        }
        else if(i%k){
            Bsum+=i;
            Bcnt++;
        }
    }
    double Aave=1.0*Asum/Acnt,Bave=1.0*Bsum/Bcnt;

    printf("%.1f %.1f",Aave,Bave);

    return 0;
}