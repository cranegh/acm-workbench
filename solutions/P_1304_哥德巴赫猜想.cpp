#include<cstdio>
int isprime=1;
void check(int x);
int main(){
    int n,a,b;
    scanf("%d",&n);
    for (int i=1 ; 2*i+2<=n ; i++){
        for (int j=2 ; j<n ; j++){
            check(j);
            if (isprime==1){
                check(2*i+2-j);
                if (isprime==1){
                    a=j;
                    b=2*i+2-j;
                    printf("%d=%d+%d\n",2*i+2,a,b);
                break;
                }
            }
        }
    }
    return 0;
}
void check(int x){
    isprime=1;
    for (int i=2 ; i<x ;i++){
        if (x%i==0){
        isprime=0;
        break;
        }
    }
}
