#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
void printarr(int *a,ostream &f,int size){
  for(int i=0;i<size;i++){
    f<<a[i]<<endl;
  }
}
int main(){
    srand(time(0));
    int size;
    cin>>size;
    int arr[size];
    ofstream f;
    f.open("randominput.txt");
    f<<size<<endl;
    for (int i=0;i<size;i++){
        arr[i]=rand();
    }    
    printarr(arr,f,size);
    return 0;
}