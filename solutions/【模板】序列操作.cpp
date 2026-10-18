#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int q;
    cin>>q;
    vector<int> s;
    while(q--){
        int op;
        cin>>op;
        switch (op)
        {
        case 1:
            int x;
            cin>>x;
            s.push_back(x);
            break;
        case 2:
            s.pop_back();
            break;
        case 3:
            int i;
            cin>>i;
            cout<<s[i]<<endl;
            break;
        case 4:
            int k;
            cin>>k;
            s.push_back(0);
            for ( int j=s.size()-1 ; j>k ; j--){
                s[j]=s[j-1];
            }
            int m;
            cin>>m;
            s[k+1]=m;
            break;
        case 5:
            sort(s.begin(),s.end());
            break;
        case 6:
            sort(s.begin(),s.end());
            reverse(s.begin(),s.end());
            break;
        case 7:
            cout<<s.size()<<endl;
            break;
        case 8:
            for (int i=0 ; i<s.size() ; i++)
            {
                cout<<s[i]<<" ";
            }
            cout<<endl;
            break; 
        default:
            break;
        }
    }
    return 0;
}
