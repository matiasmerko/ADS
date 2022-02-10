#include <iostream>
using namespace std;
void printarr(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void Swap(int A[], int i, int j) {
    int tmp = A[i]; A[i] = A[j]; A[j] = tmp;
}
void sort(int A[], int left, int right) {
    if (right > left) {
        // Choose outermost elements as pivots
        if (A[left] > A[right]) Swap(A, left, right);
        int p = A[left], q = A[right];

        // Partition A according to invariant below
        int l = left + 1, g = right - 1, k = l;
        while (k <= g) {
            if (A[k] < p) {
                Swap(A, k, l);
                ++l;
            } else if (A[k] >= q) {
                while (A[g] > q && k < g) --g;
                Swap(A, k, g);
                --g;
                if (A[k] < p) {
                    Swap(A, k, l);
                    ++l;
                }
            }
            ++k;
        }
        --l; ++g;

        // Swap pivots to final place
        Swap(A, left, l); Swap(A, right, g);

        // Recursively sort partitions
        sort(A, left, l - 1);
        sort(A, l + 1, g - 1);
        sort(A, g + 1, right);
    }
}

int main(){
    int a[6]={1,4,5,2,3,6};
    cout<<"before: ";printarr(a,6);
    sort(a,0,6);
    cout<<"after: ";printarr(a,6);
    return 0;
}