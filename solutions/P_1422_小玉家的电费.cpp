#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int x;
    double money;
    cin>>x;
    if (x<=150) money=0.4463*x;
    else if (x<=400) money=0.4463*150+0.4663*(x-150);
    else if (x>400) money=0.4463*150+0.4663*250+0.5663*(x-400);
    printf("%.1f",money);
    return 0;
}