#include <iostream>
#include <vector>
#include <map>
#include <bitset>

using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int k; cin>>k;
    int max_d=0;
    for(int i=0 ; i<k ; i++){
        int temp; cin>>temp;
        max_d=max(max_d,temp);
    }

    cout<<max_d+k-1;

    return 0;
}