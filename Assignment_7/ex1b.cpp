#include <iostream>
using namespace std;
//Hoare's Method
void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int partition(int A[],int low, int hi){
    int pivot= A[low];
    int i=low-1;
    int j=hi;
    while(1){
        while(A[i]<pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i>=j){
            return j;
        }
        swap(A[i],A[j]);
    }
}
void Quicksort(int A[],int low,int hi){
    if(low<hi){
        int pindex=partition(A,low,hi);
        Quicksort(A,low,pindex);
        Quicksort(A,pindex+1,hi);
    }
}
int main()
{
    int arr[] = {3,2,4,5,1,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    Quicksort(arr, 1, n - 1);
    printarr(arr, n);
    return 0;
}