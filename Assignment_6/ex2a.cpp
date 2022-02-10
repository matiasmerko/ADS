#include <iostream>
#include <array>
using namespace std;
void maxheapify(int a[], int i,int asize)
{
    int biggest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < asize && a[l] > a[biggest])
        biggest = l;
 
    if (r < asize && a[r] > a[biggest])
        biggest = r;
 
    if (biggest != i) {
        swap(a[i], a[biggest]);
 
        maxheapify(a,biggest,asize);
    }
}
void buildmaxheap(int a[],int asize){
    for(int i=(asize/2)-1;i>=0;i--){
        maxheapify(a,i,asize);
    }
}
void heapsort(int a[],int asize){
    buildmaxheap(a,asize);
    for (int i=asize-1;i>0;i--){
        swap(a[0],a[i]);
        asize=asize-1;
        maxheapify(a,0,i);
    }
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main(){
    int arr[]={ 12, 11, 13, 5, 6, 7 };
    int arrsize=sizeof(arr)/sizeof(arr[0]);
    printarr(arr,arrsize);
    heapsort(arr,arrsize);
    printarr(arr,arrsize);
    return 0;
}