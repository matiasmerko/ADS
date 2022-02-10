#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> vec;
    string b;
    int count = 0;
    while (b != "END")
    {
        cin >> b;
        vec.push_back(b);
        count++;
    }
    vec.pop_back(); //removing END
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    vector<string>::iterator it;
    for (it = vec.begin(); it != vec.end() - 1; it++)
    {
        cout << *it << ",";
    }
    cout << vec[count - 2];
    return 0;
}