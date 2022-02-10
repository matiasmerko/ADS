#include <iostream>
using namespace std;
void printarr(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[7]={9, 1, 6, 7, 6, 2, 1};
    int max,arrsize;
    max=arr[0];
    arrsize=sizeof(arr)/sizeof(arr[0]);
    cout<<"before: ";printarr(arr,arrsize);
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
    cout<<"after: ";printarr(result,arrsize);
    return 0;
}