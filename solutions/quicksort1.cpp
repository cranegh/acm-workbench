#include<iostream>
void quicksort(int left,int right);
int a[1010];
using namespace std;
int main(){}
void quicksort(int left,int right){
    if(left>right)
    return;

    int i,j,t,temp;
    i=left;
    j=right;
    temp=a[left];
    while(i!=j){
        while(a[j]>temp && i<j)
        j--;
        while(a[i]<=temp && i<j)
        i++;
        
        if(i<j){
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        }
    }

    a[left]=a[i];
    a[i]=temp;

    quicksort(left,i-1);
    quicksort(i+1,right);
}
