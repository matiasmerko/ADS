#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <set>
#include <cstring>
using namespace std;
typedef long long int ll;
void printLIS(vector<int>& arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}
void constructPrintLIS(int arr[], int n)
{
    vector<vector<int> > L(n);
    L[0].push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] > arr[j]) &&
                    (L[i].size() < L[j].size() + 1))
                L[i] = L[j];
        }
        L[i].push_back(arr[i]);
    }
    vector<int> max = L[0];
    for (vector<int> x : L)
        if (x.size() > max.size())
            max = x;
    printLIS(max);
}
int main()
{
    int arr[] = { 8, 3, 6, 50, 10, 8, 100, 30, 60, 40, 80 };
    int n = sizeof(arr) / sizeof(arr[0]);
    constructPrintLIS(arr, n);
 
    return 0;
}