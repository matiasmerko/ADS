#include <iostream>
using namespace std;
int leafsearch(int a[],int i,int end){
    int j=i;
    while(a[2*j+2]<=end){
        if(a[2*j+2]<=end){
            if(a[2*j+2]>a[2*j+1]){
                j=a[2*j+2];
            }else{
                j=2*j+1;
            }
        }
    }
    if(a[2*j+1]<=end){
        j=a[2*j+1];
    }
    return j;
}
void siftDown(int a[],int i,int end){
    int j=leafsearch(a,i,end);
    while(a[i]>a[j]){
        j=a[(j-1)/2];
    }
    int x=a[j];
    a[j]=a[i];
    while(j>i){
        swap(x,a[(j-1)/2]);
        j=a[(j-1)/2];
    }
}
void buildmaxheap(int a[],int asize){
    for(int i=asize/2-1;i>=0;i--){
        siftDown(a,i,asize);
    }
}
void heapsort(int a[],int asize){
    buildmaxheap(a,asize);
    for (int i=asize-1;i>=1;i--){
        swap(a[0],a[i]);
        asize=asize-1;
        siftDown(a,0,i);
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