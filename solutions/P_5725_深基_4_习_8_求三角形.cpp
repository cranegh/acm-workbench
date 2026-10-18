#include<cstdio>
int main(){
    int n; scanf("%d",&n);

    int j=1;
    for(int i=n ; i<=n*n ;i+=n){
        int tmp=n;
        while(tmp--){
            printf("%02d",j);
            j++;
        }
        printf("\n");
    }

    printf("\n");

    j=1;
    for(int i=1 ; i<=n ; i++)
    {
        int tmp=n-i;
        while(tmp--){
            printf("  ");
        }
        tmp=i;
        while(tmp--){
            int cnt=0;
            printf("%02d",j);
            cnt++;
            j++;
        }
        printf("\n");
    }

    return 0;
}