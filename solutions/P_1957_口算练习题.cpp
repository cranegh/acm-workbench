#include<cstdio>
#include<cstring>
int main(){
    int n,a,b,c;
    char s[20],ans[20],last;
    scanf("%d\n",&n);
    for (int i=0 ; i<n ;i++){
        fgets(s,sizeof(s),stdin);
        if (s[0]=='a'||s[0]=='b'||s[0]=='c'){
            last=s[0];
            s[0]=' ';
        }
        sscanf(s,"%d %d",&a,&b);
        switch (last)
        {
        case 'a': c=a+b;sprintf(ans,"%d+%d=%d",a,b,c);break;
        case 'b': c=a-b;sprintf(ans,"%d-%d=%d",a,b,c);break;
        case 'c': c=a*b;sprintf(ans,"%d*%d=%d",a,b,c);break;
        default:
            break;
        }
        printf("%s\n%d\n",ans,strlen(ans));
    }
    return 0;
}