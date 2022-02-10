#include <iostream>
using namespace std;
//Lomoto method
void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int Partition(int A[],int low,int hi){
    int key=A[low];
    int i=low;
    for(int j=low+1;j<hi;j++){
        if(A[j]<=key){
            i=i+1;  
            swap(A[i],A[j]);
        }
    }
    swap(A[low],A[i]);
    return i;
}
void Quicksort(int A[],int p,int r){
    if(p<r){
        int q=Partition(A,p,r);
        Quicksort(A,p,q);
        Quicksort(A,q+1,r);
    }
}
int main(){
    int a[7]={1,8,3,5,7,9,4};
    printarr(a,7);
    Quicksort(a,0,7);
    printarr(a,7);
    return 0;
}