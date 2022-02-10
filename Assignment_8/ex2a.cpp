#include <iostream>
using namespace std;
void printarr(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void countsort(int arr[],int arrsize){
    int max=arr[0];
    int result[arrsize];
    //finding the max value in original array
    for(int i=0;i<arrsize;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }   
    int count[max+1];
    //filling the count array with 0
    for(int i=0;i<=max;i++){
        count[i]=0;
    }
    //counting how many of each element we have in the original arr
    for(int i=0;i<arrsize;i++){
        count[arr[i]]++;
    }
    //storing the accumulative sum of elements in count
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    //putting the stored array in the result array
    for(int i=arrsize-1;i>=0;i--){
        result[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    //copying result into array
    for(int i=0;i<arrsize;i++){
        arr[i]=result[i];
    }
}
void radixsort(int a[],int d){
    for(int i=0;i<=d;i++){
        countsort(a,i);
    }
}
int main(){
    int arr[10]={1,3,2,5,6,7,2,9,3,5};
    cout<<"before: ";printarr(arr,10);
    radixsort(arr,10);
    cout<<"after: ";printarr(arr,10);
    return 0;
}