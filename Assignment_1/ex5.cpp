#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printvec(vector<string> v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    string str;
    vector<string> vec;
    int count = 0;
    while (str != "END")
    {
        getline(cin, str);
        vec.push_back(str);
        count++;
    }
    vec.pop_back();
    if (count < 5)
    {
        cout << "Second and fifth element don't exist at the same time" << endl;
    }
    else
    {
        cout << "Swapping second and fifth element:" << endl;
        string tmp = vec[1];
        vec[1] = vec[4];
        vec[4] = tmp;
    }
    printvec(vec);
    cout << "Replacing last element:" << endl;
    vec[count - 2] = "???";
    printvec(vec);
    cout << "Elements seperated by comma:\n";
    vector<string>::iterator it;
    for (it = vec.begin(); it != vec.end() - 1; it++)
    {
        cout << *it << ",";
    }
    cout << vec[count - 2];
    cout << "\nElements seperated by semicolumn:\n";
    vector<string>::iterator itt;
    for (itt = vec.begin(); itt != vec.end() - 1; itt++)
    {
        cout << *itt << ";";
    }
    cout << vec[count - 2];
    cout << "\nReversed order seperated by space\n";
    // vector <string> :: iterator ti;
    // for(ti=vec.end()-1;ti!=vec.begin();ti--){
    //     cout<<*ti<<" ";
    // }
    reverse(vec.begin(), vec.end());
    printvec(vec);
    return 0;
}