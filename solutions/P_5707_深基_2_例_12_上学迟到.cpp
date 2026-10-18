#include<cstdio>
#include<cmath>
int main(){
    int s,v;
    scanf("%d %d",&s,&v);
    int t_need=ceil(1.0*s/v+10),t_total=(24+8)*60,t=t_total-t_need,h,m;
    h=t/60%24,m=t%60;
    printf("%02d:%02d",h,m);
    return 0;
}