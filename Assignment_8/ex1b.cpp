#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printarr(double a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void printvec(vector <double> v){
    for(unsigned int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void bucketsort(double a[],int size){
    //creating n buckets
    vector <double> b[size];
    int index;
    for(int i=0;i<size;i++){
        index=size*a[i];
        b[index].push_back(a[i]);
    }
    for(int i=0;i<size;i++){
        sort(b[i].begin(),b[i].end());
    }   
    int arrindex=0;
    for(int i=0;i<size;i++){
        for(unsigned int j=0;j<b[i].size();j++){
            a[arrindex]=b[i][j];
            arrindex++;
        }
    }
}
int main(){
    double arr[7]={0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"before: ";printarr(arr,size);
    bucketsort(arr,size);
    cout<<"after: ";printarr(arr,size);
    return 0;
}