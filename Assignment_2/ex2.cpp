/**Matias Merko
 * mmerko@jacobs-university.de
 * */
#include <iostream>
#include <deque>
using namespace std;
//function which prints deque
void printdeque(deque<float> d)
{
    unsigned int count = 0;
    deque<float>::iterator it;
    for (it = d.begin(); it != d.end(); it++)
    {
        count++;
        if (count == d.size())
        {
            break;
        }
        cout << *it << ';';
    }
    cout << *it;
}
int main()
{
    deque<float> a;
    int inpval;
    //putting input into the deque
    while (1)
    {
        cin >> inpval;
        if (inpval == 0)
        {
            break;
        }
        if (inpval > 0)
        {
            a.push_back(inpval);
        }
        else
        {
            a.push_front(inpval);
        }
    }
    //printing elements seperated by spaces
    deque<float>::iterator it;
    for (it = a.begin(); it != a.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;
    for (it = a.begin(); it != a.end(); it++)
    {
        if (*it > 0)
        {
            break;
        }
    }
    //inserting 0 in the middle
    a.insert(it, 0);
    //printing elements by semicolon
    printdeque(a);
    return 0;
}