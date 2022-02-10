#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <fstream>
using namespace std;
int selection_sort(int* array_, int size)
{
    int temp;
    int index;
    int min;
    int count=0;
    for (int i = 0; i < size; i++)
    {
        min=array_[i];
        index = i;
        for (int j = i+1; j < size; j++)
        {
            if (min>array_[j])
            {
                min=array_[j];
                index=j;
            }
        }
        temp=array_[i];
        array_[i]=min;
        array_[index]=temp;
        count++;
    }
    return count;
}
int main()
{   
    int size,i=0;
    ifstream f("randominput.txt");
    f>>size;
    int arr[size];
    while(!f.eof()){
        f>>arr[i];
        i++;
    }
    selection_sort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}