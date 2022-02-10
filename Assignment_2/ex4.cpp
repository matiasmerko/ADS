/**Matias Merko
 * mmerko@jacobs-university.de
 * */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//function which prints vector
void printvec(vector<int> v)
{
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;
}
int main()
{
    vector<int> vec;
    //adding ints from 1 to 30 into vec
    for (int i = 1; i <= 30; i++)
    {
        vec.push_back(i);
    }
    //pushing no.5
    vec.push_back(5);
    //reversing
    reverse(vec.begin(), vec.end());
    printvec(vec);
    cout << endl;
    //replacing 5 with 129
    replace(vec.begin(), vec.end(), 5, 129);
    printvec(vec);
    return 0;
}