#include <iostream>

using namespace std;

const int N = 2e5+9;
int a[2][N];

signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        if(n==1){
            int x,y;cin>>x>>y;
            if(x>y)cout<<"Mandy"<<endl;
            else if(x<y)cout<<"brz"<<endl;
            else cout<<"draw"<<endl;
            continue;
        }else {
            for (int i=0 ; i<2 ; i++) {
                for (int j=1 ; j<=n ; j++){
                    cin>>a[i][j];
                }
            }
            if (n%2==0) {
                int sum_s=0,sum_x=0,sum_l=0,sum_r=0;
                for (int i=1 ; i<=n ; i++) sum_s+=a[0][i];
                for (int i=1 ; i<=n ; i++) sum_x+=a[1][i];
                for (int i=n/2+1;i<=n;i++) {
                    sum_r+=a[0][i];
                    sum_r+=a[1][i];
                }
                for (int i=1 ; i<=n/2 ; i++) {
                    sum_l+=a[0][i];
                    sum_l+=a[1][i];
                }

                if (sum_s>=sum_l) {
                    if (sum_s>sum_x) cout<<"Mandy1\n";
                    else if (sum_s==sum_x) cout<<"draw\n";
                    else if (sum_s<sum_x) cout<<"brz\n";
                    continue;
                }else {
                    if (sum_l>sum_r) cout<<"Mandy2\n";
                    else if (sum_l==sum_r) cout<<"draw\n";
                    else if (sum_l<sum_r) cout<<"brz\n";
                    continue;
                }


            }else {
                int sum_s=0,sum_x=0,sum_l=0,sum_r=0,sum_z=0;
                for (int i=1 ; i<=n ; i++) sum_s+=a[0][i];
                for (int i=1 ; i<=n ; i++) sum_x+=a[1][i];
                for (int i=n/2+2;i<=n;i++) {
                    sum_r+=a[0][i];
                    sum_r+=a[1][i];
                }
                for (int i=1 ; i<=n/2 ; i++) {
                    sum_l+=a[0][i];
                    sum_l+=a[1][i];
                }
                sum_z+=a[0][n/2+1];
                sum_z+=a[1][n/2+1];

                if (sum_s>=sum_l) {
                    if (sum_s>sum_x) cout<<"Mandy3\n";
                    else if (sum_s==sum_x) cout<<"draw\n";
                    else if (sum_s<sum_x) cout<<"brz\n";
                    continue;
                }else {
                    if (sum_l>sum_r+sum_z) cout<<"Mandy4\n";
                    else if (sum_l==sum_r+sum_z) cout<<"draw\n";
                    else if (sum_l<sum_r+sum_z) cout<<"brz\n";
                    continue;
                }



            }
        }
    }


    return 0;
}