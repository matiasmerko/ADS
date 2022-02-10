//NOTE: Below the code there are more parts of the exercise 4.1!
#include <iostream>
using namespace std;
void printarr(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
void insertionSort(int arr[],int start, int n)
{
    int i, key, j;
    for (i = start+1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= start && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void merge(int *array, int l, int m, int r)
{
    cout<<"Mrena merge"<<endl;
    int i, j, k, nl, nr;
    //size of left and right sub-arrays
    nl = m - l + 1;
    nr = r - m;
    int larr[nl], rarr[nr];
    //fill left and right sub-arrays
    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    //marge temp arrays to real array
    while (i < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        {
            array[k] = larr[i];
            i++;
        }
        else
        {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    { //extra element in left array
        array[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr)
    { //extra element in right array
        array[k] = rarr[j];
        j++;
        k++;
    }
}
void mergeSort(int *array, int l, int r, int k)
{
    cout<<"l: "<<l<<" r: "<<r<<" k: "<<k<<endl; 
    int m;
    if(k>=r-l && l<r){
        insertionSort(array,l,r+1);
    }
    else if(k<r-l && l<r) 
    {
        int m = l + (r - l) / 2;
        cout<<" m: "<<m<<endl;
        cout<<"Para recursive1"<<endl;
        mergeSort(array, l, m, k);
        cout<<"Mas recursive1 dhe Para recursive2"<<endl;
        mergeSort(array, m + 1, r, k);
        cout<<"Mas recursive2"<<endl;
        merge(array, l, m, r);
    }
}
int main()
{
    int arr[] = {3,2,1,5,6,7,22,4,1,104,142,213,41,24,53};
    int k;
    cout << "k: ";
    cin >> k;
    cout << "before:";
    printarr(arr, 15);
    cout << "after:";
    mergeSort(arr, 0,14, k);
    printarr(arr, 15);
}

/**
 * 4.1 c)
 * For the best case, which is an already sorted array,
 * if k is equal to the size of the array or bigger, then 
 * we have the best case possible. For average case, different
 * k's have different impacts. For worst case we have a reversed 
 * array and k is equal or bigger to its size.
 * 
 * 4.1 d)
 * If the array is mostly sorted then k>=size. Otherwise
 * If the array is random,or mostly unsorted then
 * k must be small.
 * */